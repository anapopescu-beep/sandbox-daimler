# 1 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c"
# 33 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h"
extern "C"
{
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement_Type.h" 1
# 29 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement_Type.h"
extern "C"
{
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_Type.h" 1
# 28 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_Type.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Std_Types.h" 1
# 65 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Std_Types.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Platform_Types.h" 1
# 101 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Platform_Types.h"
typedef unsigned char boolean;

typedef signed char sint8;
typedef unsigned char uint8;
typedef signed short sint16;
typedef unsigned short uint16;
typedef signed long sint32;
typedef unsigned long uint32;

typedef signed char sint8_least;
typedef unsigned char uint8_least;
typedef signed short sint16_least;
typedef unsigned short uint16_least;
typedef signed long sint32_least;
typedef unsigned long uint32_least;
# 125 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Platform_Types.h"
typedef signed long long sint64;
typedef unsigned long long uint64;


typedef float float32;
typedef double float64;
# 66 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Std_Types.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler.h" 1
# 55 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler_Cfg.h" 1
# 127 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler_Cfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_Compiler_Cfg.h" 1
# 49 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_Compiler_Cfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_Compiler_Cfg.h" 1
# 50 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_Compiler_Cfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_Compiler_Cfg.h" 1
# 52 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_Compiler_Cfg.h" 2
# 128 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler_Cfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler_Cfg_MSR4_MBP.h" 1
# 130 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler_Cfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler_Cfg_MSR4_MCP.h" 1
# 131 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler_Cfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler_Cfg_MSR4_MEP.h" 1
# 132 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler_Cfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler_Cfg_MSR4_MOP_Daimler.h" 1
# 133 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler_Cfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler_Cfg_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 736 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler_Cfg_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Compiler_Cfg.h" 1
# 737 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler_Cfg_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 2
# 134 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler_Cfg.h" 2
# 56 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler.h" 2
# 67 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Std_Types.h" 2
# 127 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Std_Types.h"
typedef unsigned char StatusType;




typedef uint8 Std_ReturnType;

typedef struct
{
   uint16 vendorID;
   uint16 moduleID;
   uint8 sw_major_version;
   uint8 sw_minor_version;
   uint8 sw_patch_version;
} Std_VersionInfoType;
# 41 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_PBCfg.h" 1
# 27 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_PBCfg.h"
typedef struct {
  uint8 variant;
} SchM_ConfigType;
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 33 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_PBCfg.h" 2

extern const SchM_ConfigType Rte_Config_Left;

extern const SchM_ConfigType Rte_Config_Right;
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 41 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_PBCfg.h" 2
# 42 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_UserTypes.h" 1
# 53 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_UserTypes.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/ComStack_Types.h" 1
# 76 "S:/COMPON~1/APPLIC~1/Supplier/_Common/ComStack_Types.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Std_Types.h" 1
# 77 "S:/COMPON~1/APPLIC~1/Supplier/_Common/ComStack_Types.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComStack_Cfg.h" 1
# 62 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComStack_Cfg.h"
typedef uint8 PduIdType;

typedef uint16 PduLengthType;
# 79 "S:/COMPON~1/APPLIC~1/Supplier/_Common/ComStack_Types.h" 2
# 196 "S:/COMPON~1/APPLIC~1/Supplier/_Common/ComStack_Types.h"
typedef uint8 * SduDataPtrType;
typedef struct
{
  SduDataPtrType SduDataPtr;
  PduLengthType SduLength;
} PduInfoType;

typedef enum
{
  BUFREQ_OK,
  BUFREQ_E_NOT_OK,
  BUFREQ_E_BUSY,
  BUFREQ_E_OVFL
} BufReq_ReturnType;

typedef uint8 NotifResultType;

typedef uint8 BusTrcvErrorType;

typedef uint8 NetworkHandleType;

typedef uint16 PNCHandleType;

typedef enum
{
  TP_DATACONF,

  TP_DATARETRY,

  TP_CONFPENDING
} TpDataStateType;

typedef struct
{
  TpDataStateType TpDataState;
  PduLengthType TxTpDataCnt;
} RetryInfoType;


typedef enum
{
  TP_STMIN,
  TP_BS,
  TP_BC
} TPParameterType;
# 54 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_UserTypes.h" 2
# 44 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Det/Det.h" 1
# 82 "S:/COMPON~1/APPLIC~1/Supplier/Det/Det.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Det_Cfg.h" 1
# 220 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Det_Cfg.h"
typedef Std_ReturnType ( * Det_CalloutTableType)(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);
# 237 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Det_Cfg.h"
typedef struct sDet_PCConfigType
{
  uint8 Det_PCConfigNeverUsed;
} Det_PCConfigType;

typedef Det_PCConfigType Det_ConfigType;
# 272 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Det_Cfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 273 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Det_Cfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 279 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Det_Cfg.h" 2
# 83 "S:/COMPON~1/APPLIC~1/Supplier/Det/Det.h" 2
# 217 "S:/COMPON~1/APPLIC~1/Supplier/Det/Det.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 218 "S:/COMPON~1/APPLIC~1/Supplier/Det/Det.h" 2
# 232 "S:/COMPON~1/APPLIC~1/Supplier/Det/Det.h"
void Det_Init( const Det_ConfigType * const ConfigPtr );
# 247 "S:/COMPON~1/APPLIC~1/Supplier/Det/Det.h"
void Det_Start( void );
# 261 "S:/COMPON~1/APPLIC~1/Supplier/Det/Det.h"
void Det_InitMemory( void );
# 282 "S:/COMPON~1/APPLIC~1/Supplier/Det/Det.h"
Std_ReturnType Det_ReportError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );
# 302 "S:/COMPON~1/APPLIC~1/Supplier/Det/Det.h"
Std_ReturnType Det_ReportRuntimeError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );
# 322 "S:/COMPON~1/APPLIC~1/Supplier/Det/Det.h"
Std_ReturnType Det_ReportTransientFault( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );
# 346 "S:/COMPON~1/APPLIC~1/Supplier/Det/Det.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 347 "S:/COMPON~1/APPLIC~1/Supplier/Det/Det.h" 2
# 46 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte.h" 2
# 29 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_Type.h" 2
# 37 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_Type.h"
typedef uint8 * Csm_DataPtr;


typedef uint32 * Csm_LengthPtr;


typedef const uint8 * Csm_const_DataPtr;


typedef const uint8 * KeyM_ConstDataPtrType;


typedef uint8 * KeyM_CryptoKeyDataType;


typedef uint8 * KeyM_DataPtrType;


typedef uint32 * KeyM_LengthPtrType;


typedef const uint8 * KeyM_const_CryptoKeyDataType;


typedef const uint8 * Ssa_ConstDataPtr;


typedef uint8 * Ssa_DataPtr;


typedef void * dtRef_VOID;


typedef const void * dtRef_const_VOID;


typedef uint8 impl_BswM_RoEMode;


typedef uint8 CertP_RawCertBufferType[910];


typedef uint8 Coding_VINDataType[17];


typedef uint8 Csm_DecryptDataType_AES128Decrypt[80];


typedef uint8 Csm_DecryptResultType_AES128Decrypt[80];


typedef uint8 Csm_HashDataType_Sha2_512[8192];


typedef uint8 Csm_HashResultType_Sha2_512[64];


typedef uint8 Csm_KeyDataType_KeyM_SigVerifyKey_TrustModelEcu[32];


typedef uint8 Csm_KeyDataType_KeyM_SigVerifyKey_TrustModelEcuCsr[32];


typedef uint8 Csm_KeyDataType_KeyM_SigVerifyKey_TrustModelEcuPeer[32];


typedef uint8 Csm_KeyDataType_Ssa_AesRamKey[16];


typedef uint8 Csm_KeyDataType_Ssa_Authentication[16];


typedef uint8 Csm_KeyDataType_Ssa_BackendCert[600];


typedef uint8 Csm_KeyDataType_Ssa_EcuCert[600];


typedef uint8 Csm_KeyDataType_Ssa_RandomSeed[209];


typedef uint8 Csm_KeyDataType_Ssa_RealTime[16];


typedef uint8 Csm_KeyDataType_Ssa_RootCert[600];


typedef uint8 Csm_KeyDataType_Ssa_SecurityAccessPublicKey[32];


typedef uint8 Csm_KeyDataType_Ssa_SharedSecretHash[4];


typedef uint8 Csm_KeyDataType_Ssa_SharedSecretKeyExchange[32];


typedef uint8 Csm_KeyDataType_Ssa_SignatureRamKey[32];


typedef uint8 Csm_KeyDataType_Ssa_TickCount[16];


typedef uint8 Csm_KeyDataType_Ssa_TrustModelPrivateEcuKey[32];


typedef uint8 Csm_KeyDataType_Ssa_TrustModelPrivateEcuUniqueKey[32];


typedef uint8 Csm_KeyDataType_Ssa_VIN[16];


typedef uint8 Csm_MacGenerateDataType_MacGenAesCmac[27];


typedef uint8 Csm_MacGenerateResultType_MacGenAesCmac[16];


typedef uint8 Csm_MacVerifyCompareType_MacVerifyAesCmac[8];


typedef uint8 Csm_MacVerifyDataType_MacVerifyAesCmac[27];


typedef uint8 Csm_PublicValueDataType_KeyM_SigVerifyKey_TrustModelEcu[32];


typedef uint8 Csm_PublicValueDataType_KeyM_SigVerifyKey_TrustModelEcuCsr[32];


typedef uint8 Csm_PublicValueDataType_KeyM_SigVerifyKey_TrustModelEcuPeer[32];


typedef uint8 Csm_PublicValueDataType_Ssa_AesRamKey[16];


typedef uint8 Csm_PublicValueDataType_Ssa_Authentication[16];


typedef uint8 Csm_PublicValueDataType_Ssa_BackendCert[600];


typedef uint8 Csm_PublicValueDataType_Ssa_EcuCert[600];


typedef uint8 Csm_PublicValueDataType_Ssa_RandomSeed[209];


typedef uint8 Csm_PublicValueDataType_Ssa_RealTime[16];


typedef uint8 Csm_PublicValueDataType_Ssa_RootCert[600];


typedef uint8 Csm_PublicValueDataType_Ssa_SecurityAccessPublicKey[32];


typedef uint8 Csm_PublicValueDataType_Ssa_SharedSecretHash[4];


typedef uint8 Csm_PublicValueDataType_Ssa_SharedSecretKeyExchange[32];


typedef uint8 Csm_PublicValueDataType_Ssa_SignatureRamKey[32];


typedef uint8 Csm_PublicValueDataType_Ssa_TickCount[16];


typedef uint8 Csm_PublicValueDataType_Ssa_TrustModelPrivateEcuKey[32];


typedef uint8 Csm_PublicValueDataType_Ssa_TrustModelPrivateEcuUniqueKey[32];


typedef uint8 Csm_PublicValueDataType_Ssa_VIN[16];


typedef uint8 Csm_RandomGenerateResultType_Random[32];


typedef uint8 Csm_SeedDataTypeKeyM_SigVerifyKey_TrustModelEcu[32];


typedef uint8 Csm_SeedDataTypeKeyM_SigVerifyKey_TrustModelEcuCsr[32];


typedef uint8 Csm_SeedDataTypeKeyM_SigVerifyKey_TrustModelEcuPeer[32];


typedef uint8 Csm_SeedDataTypeSsa_AesRamKey[16];


typedef uint8 Csm_SeedDataTypeSsa_Authentication[16];


typedef uint8 Csm_SeedDataTypeSsa_BackendCert[600];


typedef uint8 Csm_SeedDataTypeSsa_EcuCert[600];


typedef uint8 Csm_SeedDataTypeSsa_RandomSeed[209];


typedef uint8 Csm_SeedDataTypeSsa_RealTime[16];


typedef uint8 Csm_SeedDataTypeSsa_RootCert[600];


typedef uint8 Csm_SeedDataTypeSsa_SecurityAccessPublicKey[32];


typedef uint8 Csm_SeedDataTypeSsa_SharedSecretHash[4];


typedef uint8 Csm_SeedDataTypeSsa_SharedSecretKeyExchange[32];


typedef uint8 Csm_SeedDataTypeSsa_SignatureRamKey[32];


typedef uint8 Csm_SeedDataTypeSsa_TickCount[16];


typedef uint8 Csm_SeedDataTypeSsa_TrustModelPrivateEcuKey[32];


typedef uint8 Csm_SeedDataTypeSsa_TrustModelPrivateEcuUniqueKey[32];


typedef uint8 Csm_SeedDataTypeSsa_VIN[16];


typedef uint8 Csm_SignatureGenerateDataType_SigGenEd25519[129];


typedef uint8 Csm_SignatureGenerateResultType_SigGenEd25519[64];


typedef uint8 Csm_SignatureVerifyCompareType_SigVerifyEd25519[64];


typedef uint8 Csm_SignatureVerifyCompareType_SigVerifyEd25519_SSA[64];


typedef uint8 Csm_SignatureVerifyCompareType_SigVerifyEd25519ph[64];


typedef uint8 Csm_SignatureVerifyCompareType_SigVerifyEd25519ph_SyncAsync[64];


typedef uint8 Csm_SignatureVerifyDataType_SigVerifyEd25519[8192];


typedef uint8 Csm_SignatureVerifyDataType_SigVerifyEd25519_SSA[8192];


typedef uint8 Csm_SignatureVerifyDataType_SigVerifyEd25519ph[8192];


typedef uint8 Csm_SignatureVerifyDataType_SigVerifyEd25519ph_SyncAsync[8192];


typedef uint8 DataArrayType_uint8_1[1];


typedef uint8 DataArrayType_uint8_2[2];


typedef uint8 DataArrayType_uint8_4[4];


typedef uint8 Dcm_Data1000ByteType[1000];


typedef uint8 Dcm_Data1002ByteType[1002];


typedef uint8 Dcm_Data100ByteType[100];


typedef uint8 Dcm_Data1058ByteType[1058];


typedef uint8 Dcm_Data10ByteType[10];


typedef uint8 Dcm_Data12ByteType[12];


typedef uint8 Dcm_Data15ByteType[15];


typedef uint8 Dcm_Data160ByteType[160];


typedef uint8 Dcm_Data16ByteType[16];


typedef uint8 Dcm_Data17ByteType[17];


typedef uint8 Dcm_Data18ByteType[18];


typedef uint8 Dcm_Data1ByteType[1];


typedef uint8 Dcm_Data2002ByteType[2002];


typedef uint8 Dcm_Data2004ByteType[2004];


typedef uint8 Dcm_Data200ByteType[200];


typedef uint8 Dcm_Data20ByteType[20];


typedef uint8 Dcm_Data220ByteType[220];


typedef uint8 Dcm_Data22ByteType[22];


typedef uint8 Dcm_Data250ByteType[250];


typedef uint8 Dcm_Data254ByteType[254];


typedef uint8 Dcm_Data255ByteType[255];


typedef uint8 Dcm_Data28ByteType[28];


typedef uint8 Dcm_Data2ByteType[2];


typedef uint8 Dcm_Data3000ByteType[3000];


typedef uint8 Dcm_Data3006ByteType[3006];


typedef uint8 Dcm_Data30ByteType[30];


typedef uint8 Dcm_Data321ByteType[321];


typedef uint8 Dcm_Data328ByteType[328];


typedef uint8 Dcm_Data32ByteType[32];


typedef uint8 Dcm_Data33ByteType[33];


typedef uint8 Dcm_Data381ByteType[381];


typedef uint8 Dcm_Data3ByteType[3];


typedef uint8 Dcm_Data4004ByteType[4004];


typedef uint8 Dcm_Data4008ByteType[4008];


typedef uint8 Dcm_Data4064ByteType[4064];


typedef uint8 Dcm_Data4092ByteType[4092];


typedef uint8 Dcm_Data48ByteType[48];


typedef uint8 Dcm_Data4ByteType[4];


typedef uint8 Dcm_Data512ByteType[512];


typedef uint8 Dcm_Data5ByteType[5];


typedef uint8 Dcm_Data64ByteType[64];


typedef uint8 Dcm_Data6ByteType[6];


typedef uint8 Dcm_Data7ByteType[7];


typedef uint8 Dcm_Data80ByteType[80];


typedef uint8 Dcm_Data8192ByteType[8192];


typedef uint8 Dcm_Data8195ByteType[8195];


typedef uint8 Dcm_DataDID_FD2F_EcuLocationData_ArrayType[1];


typedef uint8 Dem_MaxDataValueType[5];


typedef uint8 KeyM_CertificateDataType_Ssa_TrustModelBackendCert[1000];


typedef uint8 KeyM_CertificateDataType_Ssa_TrustModelBackendPeerCert[1000];


typedef uint8 KeyM_CertificateDataType_Ssa_TrustModelEcuCert[1000];


typedef uint8 KeyM_CertificateDataType_Ssa_TrustModelEcuCsr[1000];


typedef uint8 KeyM_CertificateDataType_Ssa_TrustModelEcuPeerCert[1000];


typedef uint8 KeyM_CertificateDataType_Ssa_TrustModelIntermediateCert[1000];


typedef uint8 KeyM_CertificateDataType_Ssa_TrustModelIntermediatePeerCert[1000];


typedef uint8 KeyM_CertificateDataType_Ssa_TrustModelRootCert[1000];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Issuer_002[10];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SerialNo_002[16];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SigAlgoId_002[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002[33];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Version_002[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_authKeyId_002[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_basicConstraints_002[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_keyUsage_002[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_pkiRole_002[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_subKeyId_002[20];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_signatureAlgorithm_002[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_signatureValue_002[65];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_subject_002[10];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotAfter_002[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotBefore_002[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Issuer_004[10];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SerialNo_004[16];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SigAlgoId_004[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004[33];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Version_004[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004[20];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_signatureValue_004[65];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_subject_004[10];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotAfter_004[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotBefore_004[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Issuer_005[10];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SerialNo_005[16];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SigAlgoId_005[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005[33];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Version_005[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_authKeyId_005[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_extKeyUsage_005[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_extKeyUsage_oid1_005[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_extKeyUsage_oid2_005[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_extKeyUsage_oid3_005[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_keyUsage_005[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_pkiRole_005[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_specialEcu_005[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_subKeyId_005[20];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_uniqueECUID_005[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_signatureAlgorithm_005[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_signatureValue_005[65];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_subject_005[10];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotAfter_005[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotBefore_005[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_Issuer_008[10];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SerialNo_008[16];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SigAlgoId_008[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008[33];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_Version_008[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_authKeyId_008[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_keyUsage_008[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_pkiRole_008[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_specialEcu_007[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_subKeyId_008[20];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_signatureAlgorithm_008[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_signatureValue_008[65];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_subject_008[10];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_validityNotAfter_008[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_validityNotBefore_008[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Issuer_006[10];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SerialNo_006[16];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SigAlgoId_006[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006[33];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Version_006[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_extKeyUsage_006[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_extKeyUsage_oid1_006[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_extKeyUsage_oid2_006[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_extKeyUsage_oid3_006[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_pkiRole_006[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006[20];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_signatureValue_006[65];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_subject_006[10];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotAfter_006[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotBefore_006[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Issuer_003[10];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SerialNo_003[16];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SigAlgoId_003[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003[33];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Version_003[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_authKeyId_003[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_keyUsage_003[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_pkiRole_003[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_subKeyId_003[20];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_signatureValue_003[65];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_subject_003[10];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotAfter_003[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotBefore_003[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Issuer_007[10];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SerialNo_007[16];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007[33];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Version_007[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_007[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007[20];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_signatureValue_007[65];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_subject_007[10];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_Issuer[10];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_SerialNo[16];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_SigAlgoId[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey[33];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_Version[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_authKeyId[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_basicConstraints[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_keyUsage[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_pkiRole[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_subKeyId[20];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_signatureAlgorithm[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_signatureValue[65];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_subject[10];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotAfter[1];


typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotBefore[1];


typedef uint8 KeyM_SharedSecretType[32];


typedef uint8 RightsM_AuthenticationBroadcastType[20];


typedef uint8 RightsM_ChallengeEcuType[32];


typedef uint8 RightsM_IssuerType[15];


typedef uint8 RightsM_SerialNumberType[16];


typedef uint8 SecLog_AclVersionType[11];


typedef uint8 SecLog_AuthenticationContentType[18];


typedef uint8 SecLog_LogDataEvnt10_FailedPduMacVerifType[128];


typedef uint8 SecLog_LogDataEvnt11_SecOrAuthBootType[59];


typedef uint8 SecLog_LogDataEvnt12_ChangeOfVinType[76];


typedef uint8 SecLog_LogDataEvnt13_AclReplacementType[95];


typedef uint8 SecLog_LogDataEvnt1_FailedCertVerifType[176];


typedef uint8 SecLog_LogDataEvnt2_SucCertVerifType[244];


typedef uint8 SecLog_LogDataEvnt3_SucAuthAndEnhanceRightsType[391];


typedef uint8 SecLog_LogDataEvnt4_AuthBySecAccessType[68];


typedef uint8 SecLog_LogDataEvnt5_SucDiagServiceExecType[138];


typedef uint8 SecLog_LogDataEvnt6_RightsMgmtType[216];


typedef uint8 SecLog_LogDataEvnt7_SigVerifType[94];


typedef uint8 SecLog_LogDataEvnt8_TickCountDateAndTimeType[232];


typedef uint8 SecLog_LogDataEvnt9_SecOcMisconfigType[62];


typedef uint8 SecLog_LogFailedMacVerifCount_ExceededThType[200];


typedef uint8 SecLog_VinType[17];


typedef uint8 Ssa_Data12ByteType[12];


typedef uint8 Ssa_Data20ByteType[20];


typedef uint8 Ssa_Data2ByteType[2];


typedef uint8 Ssa_Data30ByteType[30];


typedef uint8 Ssa_Data32ByteType[32];


typedef uint8 Ssa_Data5ByteType[5];


typedef uint8 Ssa_Data6ByteType[6];


typedef uint8 Ssa_Data7ByteType[7];


typedef uint8 Ssa_Data8ByteType[8];


typedef uint8 Ssa_DataToBeSignedType[4092];


typedef uint8 freshnessValueType[8];


typedef struct
{
  boolean validContent;
  uint16 elemDataIdx;
  uint16 elemDataLength;
} CertP_BerElementType;


typedef struct
{
  uint8 SarDataStorageStatus;
  uint32 MaxNumberOfSARWriteCycles;
  uint32 NumberOfSARWriteCycles;
} Idt_codingData;


typedef struct
{
  uint16 writeIdx;
  uint16 lengthContent;
  uint16 thresholdWarning;
} SecLog_LogEntryCtrlDataType;


typedef struct
{
  uint16 year;
  uint8 month;
  uint8 day;
  uint8 hour;
  uint8 minute;
  uint8 second;
} TimeM_DateTimeType;


typedef uint8 BswM_ESH_KillAllRun;


typedef uint8 BswM_ESH_Mode;


typedef uint8 BswM_ESH_RunRequest;


typedef uint8 CertP_PkiRoleType;


typedef uint8 CertP_VerificationResultType;


typedef uint8 Coding_MemoryStatusType;


typedef uint8 Coding_ModeType;


typedef uint8 ComM_InhibitionStatusType;


typedef uint8 ComM_ModeType;


typedef uint16 ComM_UserHandleType;


typedef uint8 Crypto_OperationModeType;


typedef uint8 Crypto_ResultType;


typedef uint8 Crypto_VerifyResultType;


typedef uint16 Csm_ConfigIdType;


typedef uint32 Csm_KeyElementEnumType;


typedef uint8 Csm_ResultType;


typedef uint8 Csm_VerifyResultType;


typedef boolean DC_BOOL;


typedef uint8 Dcm_CommunicationModeType;


typedef uint8 Dcm_ConfirmationStatusType;


typedef uint8 Dcm_ControlDtcSettingType;


typedef uint8 Dcm_DiagnosticSessionControlType;


typedef uint8 Dcm_EcuResetType;


typedef uint8 Dcm_ModeRapidPowerShutDownType;


typedef uint8 Dcm_NegativeResponseCodeType;


typedef uint8 Dcm_NegativeResponseCodeType_1;


typedef uint8 Dcm_OpStatusType;


typedef uint8 Dcm_OpStatusType_1;


typedef uint8 Dcm_ProtocolType;


typedef uint8 Dcm_RequestKindType;


typedef uint8 Dcm_SecLevelType;


typedef uint8 Dcm_SesCtrlType;


typedef uint8 Dem_ASR42_EventStatusExtendedType;


typedef uint8 Dem_ASR42_EventStatusType;


typedef uint8 Dem_DTCFormatType;


typedef uint32 Dem_DTCGroupType;


typedef uint8 Dem_DTCKindType;


typedef uint16 Dem_DTCOriginType;


typedef uint8 Dem_DTCSeverityType;


typedef uint8 Dem_DTCStatusMaskType;


typedef uint8 Dem_DTRControlType;


typedef uint8 Dem_DebounceResetStatusType;


typedef uint8 Dem_DebouncingStateType;


typedef uint16 Dem_EventIdType;


typedef uint8 Dem_EventStatusExtendedType;


typedef uint8 Dem_EventStatusType;


typedef uint8 Dem_IndicatorStatusType;


typedef uint8 Dem_InitMonitorReasonType;


typedef uint8 Dem_IumprDenomCondIdType;


typedef uint8 Dem_IumprDenomCondStatusType;


typedef uint8 Dem_IumprReadinessGroupType;


typedef uint8 Dem_MonitorStatusType;


typedef uint8 Dem_OperationCycleStateType;


typedef uint16 Dem_RatioIdType;


typedef uint8 Dem_UdsStatusByteType;


typedef uint8 EcuM_BootTargetType;


typedef uint8 EcuM_ModeType;


typedef uint8 EcuM_ShutdownCauseType;


typedef uint8 EcuM_StateType;


typedef uint32 EcuM_TimeType;


typedef uint8 EcuM_UserType;


typedef uint16 KeyM_CertElementIdType;


typedef uint16 KeyM_CertificateIdType;


typedef uint8 KeyM_CertificateStatusType;


typedef uint8 KeyM_CsrEncodingType;


typedef uint8 KeyM_ResultType;


typedef uint8 KeyM_ServiceCertificateType;


typedef uint16 NvM_ASR42_BlockIdType;


typedef uint8 NvM_ASR42_RequestResultType;


typedef uint16 NvM_BlockIdType;


typedef uint8 NvM_RequestResultType;


typedef uint8 NvM_ServiceIdType;


typedef uint32 RightsM_ACL_BitMaskType;


typedef uint8 RightsM_AuthenticationModeType;


typedef uint8 RightsM_AuthenticationStateType;


typedef uint8 RightsM_DiagnosticUserRoleType;


typedef uint8 Rsrv01;


typedef uint8 Rsrv02;


typedef uint8 Rsrv04;


typedef uint8 Rsrv05;


typedef uint8 Rsrv08;


typedef uint32 Rsrv24;


typedef uint32 Rsrv27;


typedef uint8 SecOC_VerificationResultType;


typedef uint8 Ssa_BswM_ComModeType;


typedef uint32 Ssa_BusOdometerTyp;


typedef uint8 Ssa_CentralAuthStatusProductionType;


typedef uint8 Ssa_ChangeTickCountEventIdType;


typedef uint8 Ssa_IgnitionStatus_Prim;


typedef uint32 Ssa_KeyElementType;


typedef uint8 Ssa_KeyStorageTaskType;


typedef uint8 Ssa_KeyStorageUseCaseType;


typedef uint8 Ssa_OpStatusType;


typedef uint8 Ssa_OperationModeType;


typedef uint8 Ssa_PowernetMgmtStateType;


typedef uint8 Ssa_ThresholdExceededType;


typedef uint8 Ssa_TickCountSyncStateType;


typedef uint8 Ssa_VinStoreStateType;


typedef uint32 TimeInMicrosecondsType;


typedef uint8 TimeM_CompareOperatorType;


typedef uint8 TimeM_RealTimeChangeReasonType;


typedef uint16 UInt16;


typedef uint32 UInt32;


typedef uint8 UInt8;


typedef uint8 VIN_Status;


typedef uint8 WdgMMode;


typedef uint16 WdgM_CheckpointIdType;


typedef uint8 WdgM_GlobalStatusType;


typedef uint8 WdgM_LocalStatusType;


typedef uint8 WdgM_ModeType;


typedef uint16 WdgM_SupervisedEntityIdType;


typedef uint8 b8AlgorithmFlagsStatusType;


typedef uint8 b8BooleanType;


typedef uint8 b8DefectStatusType;


typedef uint8 b8IsActiveDiagSessionType;


typedef uint8 b8IsCarAccelerationLowType;


typedef uint8 b8IsCarCrankingActiveType;


typedef uint8 b8IsCarCrashDetectedType;


typedef uint8 b8PyroActivationStatusType;


typedef uint8 c01_FalseTrue;


typedef uint8 c01_Right_Left;


typedef uint8 c01_UnitVehSpd;


typedef uint8 c02_0_3_1_nSNA;


typedef uint8 c02_ADAS_MapVerQuar;


typedef uint8 c02_Bckl_Sw_Stat;


typedef uint8 c02_BeltHdOvr_Stat;


typedef uint8 c02_DPC_Md_SSA;


typedef uint8 c02_Dr_Stat;


typedef uint8 c02_EVC_Stat;


typedef uint8 c02_HiBmLvr_Stat;


typedef uint8 c02_Inact_Act_ST3;


typedef uint8 c02_Inactv_Silent_Actv_ST3;


typedef uint8 c02_NDef_ECO_Comfort;


typedef uint8 c02_NDef_Off_On_ST3;


typedef uint8 c02_NDef_On_Off;


typedef uint8 c02_Navi_MPP_ResetRsn_ST3;


typedef uint8 c02_Ndef_False_True_ST3;


typedef uint8 c02_Off_On;


typedef uint8 c02_Off_Stage1_Stage2;


typedef uint8 c02_PT_Rdy_V2;


typedef uint8 c02_Presf_Disp_Rq;


typedef uint8 c02_Presf_Snd;


typedef uint8 c02_SSA_Standby_Stat;


typedef uint8 c02_StStyle;


typedef uint8 c02_TransMd_Stat;


typedef uint8 c02_TurnIndLvr_Stat;


typedef uint8 c02_TxBurnOut_Stat;


typedef uint8 c02_false_true_sna;


typedef uint8 c03_0_6_1;


typedef uint8 c03_0_to_7_1_no_SNA;


typedef uint8 c03_ADAS_MapProvid;


typedef uint8 c03_ADAS_Posn_CurLane;


typedef uint8 c03_ADAS_Posn_Idx;


typedef uint8 c03_Accel_Md_ST3;


typedef uint8 c03_DCDCBuckSuprtStat_ST3;


typedef uint8 c03_DPC_Md_ExhaustFlap;


typedef uint8 c03_DPC_Md_St;


typedef uint8 c03_EngStartPN14_Stat;


typedef uint8 c03_ISw_Stat;


typedef uint8 c03_MsgTyp_1_to_7;


typedef uint8 c03_No_Lt_Rt_Both;


typedef uint8 c03_PN14_ProdMd_Stat_ST3;


typedef uint8 c03_PN14_TDP_Sw_Stat;


typedef uint8 c03_VehPos_ST3;


typedef uint8 c03_m2_p3_1_Init;


typedef uint8 c04_0_15_1_SNA_na;


typedef uint8 c04_DPC_GlobalMd_Rq;


typedef uint8 c04_DPC_Md_ESP_Rq_ST3;


typedef uint8 c04_DrvPosn_ST3;


typedef uint8 c04_EVC_HL_Style_ST3;


typedef uint8 c04_EVC_TxStyle_ST3;


typedef uint8 c04_EVC_YrOfModf_1_ST3;


typedef uint8 c04_EVC_YrOfModf_2_ST3;


typedef uint8 c04_Gr;


typedef uint8 c04_Gr_Target;


typedef uint8 c04_NDef_Man_Auto;


typedef uint8 c04_Presf_Frct_ST3;


typedef uint8 c04_Presf_Lvl_V2;


typedef uint8 c04_VehOpMode;


typedef uint8 c05_ADAS_ProfShort_ProfTyp;


typedef uint8 c05_DPC_Md_PT_HU;


typedef uint8 c05_DPC_Md_Susp_V2;


typedef uint8 c05_perc_0_31_3k333;


typedef uint8 c06_ADAS_MapVerYear;


typedef uint8 c06_EVC_BodyStyle_ST3;


typedef uint8 c06_EVC_VehLine_ST3;


typedef uint8 c06_Idx_0_to_63_1;


typedef uint8 c07_0_111_1_SNA;


typedef uint8 c07_per_0to100_1_SNA;


typedef uint8 c08_0_254_1_SNA_255;


typedef uint8 c08_0_255_1_SNA_na;


typedef uint8 c08_EVC_Country_extended;


typedef uint8 c08_ROE_0;


typedef uint8 c08_TxDrvPosn;


typedef uint8 c08_UInt_SNA_na;


typedef uint8 c08_V_0_25k4_0k1;


typedef uint8 c08_degC_m40_85_0k5;


typedef uint8 c08_deg_0_358k5_1k417;


typedef uint8 c08_km_p_h_0_250_1_Blank;


typedef uint8 c08_km_p_h_0_254_1;


typedef uint8 c08_km_p_h_30_250_1_NoRcmnd;


typedef uint8 c08_m_1d6_2d87_0d005;


typedef uint8 c08_perc_0_100_0k4;


typedef uint8 c08_perc_0_100_0k5;


typedef uint16 c09_ADAS_HwVer;


typedef uint16 c09_km_p_h_0_500_1;


typedef uint16 c09_m_p_s_m12k8_89k2_0k2;


typedef uint32 c09_ms_0_510_5;


typedef uint16 c10_ADAS_CountryCode;


typedef uint16 c10_PT4_PTCoor_DAS_Hlth_Stat;


typedef uint16 c10_V_0_25k55_0k025;


typedef uint16 c10_WakeupRsn_ST3;


typedef uint16 c10_m_0_510_1;


typedef uint16 c10_to_1022_1;


typedef uint16 c12_0_4094_1_SNA;


typedef uint16 c12_km_p_h_0_409k4_0k1;


typedef uint16 c12_rpm_0_16376_4;


typedef uint16 c13_A_m409k6_409k4_0k1;


typedef uint32 c13_PresfAct_Adj_Rq;


typedef uint16 c13_m_0_8190_1;


typedef uint16 c14_rpm_0_16382_1;


typedef uint16 c15_ADAS_RegionCode;


typedef uint16 c16_CRC_woSNA;


typedef uint16 c16_SeatBeltHdOvr_FctAvlStat_ST3;


typedef uint32 c24_km_0_999999k9_0k1_Invld_SNA;


typedef uint8 cDC_errorCode_ST3;


typedef uint8 cDC_keyStorageTask_ST3;


typedef uint8 cDC_keyStorageUseCase_ST3;


typedef uint8 cDC_syncState_ST3;


typedef uint64 cDC_tickCount_ST3;


typedef uint8 c_DC_VIN_Stat_ST3;


typedef uint32 freshnessValueLengthType;


typedef sint16 s16AccelerationPedalPositionRateType;


typedef sint16 s16AccelerationType;


typedef sint16 s16AngleRateType;


typedef sint16 s16BeltPosition_degType;


typedef sint16 s16BeltPosition_mmType;


typedef sint16 s16BrakePressureRateType;


typedef sint16 s16HWAngleType;


typedef sint16 s16HWRateType;


typedef sint16 s16InternalTemperature_deg_Type;


typedef sint16 s16MotorPowerOrderType;


typedef sint32 s32BeltSpeed_deg_sType;


typedef sint32 s32BeltSpeed_mm_sType;


typedef sint32 s32MotorCurrentInmAType;


typedef sint32 s32OrderValueType;


typedef sint8 s8MotorCurrentInAType;


typedef uint16 u16AecGroupsType;


typedef uint16 u16BoostPWMOrderType;


typedef uint16 u16BrakePressureType;


typedef uint16 u16CalibBlockIdType;


typedef uint16 u16CurrentInLSBType;


typedef uint16 u16InternalTemperatureType;


typedef uint16 u16Resistance_mOhmType;


typedef uint16 u16SampledSignalType;


typedef uint16 u16StepDurationType;


typedef uint16 u16VehicleSpeedType;


typedef uint16 u16VoltageType;


typedef uint32 u32DeficiencyLevelType;


typedef uint32 u32InternalCounterType;


typedef uint32 u32ModeMaskType;


typedef uint32 u32RelativeSystemTimeType;


typedef uint32 u32ResetCauseType;


typedef uint32 u32ResetReasonNotificationStatusType;


typedef uint32 u32ResetReasonNotificationType;


typedef uint8 u8AccelerationPedalPositionType;


typedef uint8 u8AecCommandType;


typedef uint8 u8AecIdentifierType;


typedef uint8 u8AecStatusType;


typedef uint8 u8AutoTestIdType;


typedef uint8 u8BatteryVoltageSurveyStatusType;


typedef uint8 u8BeltParkingAuthorizationStateType;


typedef uint8 u8BeltSlackStatusType;


typedef uint8 u8CAN_ByteType;


typedef uint8 u8CanNmStateType;


typedef uint8 u8ClkStatusType;


typedef uint8 u8CycleNumberType;


typedef uint8 u8DoorSwitchStatusType;


typedef uint8 u8EccErrorStatusType;


typedef uint8 u8EccErrorType;


typedef uint8 u8EsmEventIdType;


typedef uint8 u8EsmStateType;


typedef uint8 u8HapticRequestType;


typedef uint8 u8JobTypesListType;


typedef uint8 u8KlemmenStatusType;


typedef uint8 u8MemoryClusterType;


typedef uint8 u8ModeStatusType;


typedef uint8 u8MotorStageStatusType;


typedef uint8 u8OrdersListType;


typedef uint8 u8PreCrashRequestType;


typedef uint8 u8PreCrashSeverityLevelType;


typedef uint8 u8PwmChannelIdType;


typedef uint8 u8RetractionStatusType;


typedef uint8 u8SeverityLevelType;


typedef uint8 u8StepNumberType;


typedef uint8 u8TestResultType;


typedef uint8 u8TriggeringSourceType;


typedef uint8 u8VelocityTargetType;


typedef uint8 u8WdgTestResultType;


typedef uint8 u8lBuckleSwitchStatusType;


typedef c08_UInt_SNA_na ARR_08_UInt_noSNA_17[17];


typedef c08_UInt_SNA_na ARR_08_UInt_noSNA_32[32];


typedef c08_UInt_SNA_na ARR_08_UInt_noSNA_64[64];


typedef c08_UInt_SNA_na ARR_08_UInt_noSNA_7[7];


typedef c08_UInt_SNA_na ARR_08_UInt_noSNA_8[8];


typedef SecLog_LogEntryCtrlDataType SecLog_CtrlDataType[13];


typedef struct
{
  Dcm_Data1ByteType NumberOfDataItems;
  Dcm_Data17ByteType CalibrationIdentification;
} CalibrationIdentifications_StorageType;


typedef struct
{
  boolean validContent;
  TimeM_DateTimeType dateTime;
} CertP_TimeType;


typedef struct
{
  Coding_VINDataType VIN;
  uint8 attributes;
} Coding_StorageType;


typedef struct
{
  uint32 certDataLength;
  KeyM_CertificateDataType_Ssa_TrustModelBackendCert certData;
} KeyM_CertificateType_Ssa_TrustModelBackendCert;


typedef struct
{
  uint32 certDataLength;
  KeyM_CertificateDataType_Ssa_TrustModelBackendPeerCert certData;
} KeyM_CertificateType_Ssa_TrustModelBackendPeerCert;


typedef struct
{
  uint32 certDataLength;
  KeyM_CertificateDataType_Ssa_TrustModelEcuCert certData;
} KeyM_CertificateType_Ssa_TrustModelEcuCert;


typedef struct
{
  uint32 certDataLength;
  KeyM_CertificateDataType_Ssa_TrustModelEcuCsr certData;
} KeyM_CertificateType_Ssa_TrustModelEcuCsr;


typedef struct
{
  uint32 certDataLength;
  KeyM_CertificateDataType_Ssa_TrustModelEcuPeerCert certData;
} KeyM_CertificateType_Ssa_TrustModelEcuPeerCert;


typedef struct
{
  uint32 certDataLength;
  KeyM_CertificateDataType_Ssa_TrustModelIntermediateCert certData;
} KeyM_CertificateType_Ssa_TrustModelIntermediateCert;


typedef struct
{
  uint32 certDataLength;
  KeyM_CertificateDataType_Ssa_TrustModelIntermediatePeerCert certData;
} KeyM_CertificateType_Ssa_TrustModelIntermediatePeerCert;


typedef struct
{
  uint32 certDataLength;
  KeyM_CertificateDataType_Ssa_TrustModelRootCert certData;
} KeyM_CertificateType_Ssa_TrustModelRootCert;


typedef struct
{
  u8CAN_ByteType BlockId;
  u8CAN_ByteType MeasurementFrame_Byte1;
  u8CAN_ByteType MeasurementFrame_Byte2;
  u8CAN_ByteType MeasurementFrame_Byte3;
  u8CAN_ByteType MeasurementFrame_Byte4;
  u8CAN_ByteType MeasurementFrame_Byte5;
  u8CAN_ByteType MeasurementFrame_Byte6;
  u8CAN_ByteType MeasurementFrame_Byte7;
} MeasurementFrame;


typedef struct
{
  c10_ADAS_CountryCode ADAS_Meta_CountryCode_ST3;
  c02_0_3_1_nSNA ADAS_Meta_CycCnt_ST3;
  c01_Right_Left ADAS_Meta_DrvSide_ST3;
  c09_ADAS_HwVer ADAS_Meta_HwVer_ST3;
  c03_ADAS_MapProvid ADAS_Meta_MapProvid_ST3;
  c02_ADAS_MapVerQuar ADAS_Meta_MapVerQuar_ST3;
  c06_ADAS_MapVerYear ADAS_Meta_MapVerYear_ST3;
  c02_0_3_1_nSNA ADAS_Meta_ProtVer_Major_ST3;
  c04_0_15_1_SNA_na ADAS_Meta_ProtVer_Minor_ST3;
  c03_0_to_7_1_no_SNA ADAS_Meta_ProtVer_MinorSub_ST3;
  c15_ADAS_RegionCode ADAS_Meta_RegionCode_ST3;
  c01_UnitVehSpd ADAS_Meta_SpdUnits_ST3;
} REC_ADAS_Meta_ST3;


typedef struct
{
  c10_ADAS_CountryCode ADAS_Meta_CountryCode_ST3;
  c15_ADAS_RegionCode ADAS_Meta_RegionCode_ST3;
} REC_ADAS_Meta_ST3_b2mk60164reg2lw3ivnikdnou;


typedef struct
{
  c09_ms_0_510_5 ADAS_Posn_Age_ST3;
  c03_ADAS_Posn_CurLane ADAS_Posn_CurLane_ST3;
  c02_0_3_1_nSNA ADAS_Posn_CycCnt_ST3;
  c03_ADAS_Posn_Idx ADAS_Posn_Idx_ST3;
  c03_MsgTyp_1_to_7 ADAS_Posn_MsgTyp_ST3;
  c13_m_0_8190_1 ADAS_Posn_Offset_ST3;
  c06_Idx_0_to_63_1 ADAS_Posn_PathIdx_ST3;
  c03_0_6_1 ADAS_Posn_PosConfdc_ST3;
  c05_perc_0_31_3k333 ADAS_Posn_PosProbb_ST3;
  c08_deg_0_358k5_1k417 ADAS_Posn_RelHead_ST3;
  c09_m_p_s_m12k8_89k2_0k2 ADAS_Posn_Spd_ST3;
} REC_ADAS_Posn_ST3;


typedef struct
{
  c09_ms_0_510_5 ADAS_Posn_Age_ST3;
  c03_ADAS_Posn_Idx ADAS_Posn_Idx_ST3;
  c13_m_0_8190_1 ADAS_Posn_Offset_ST3;
  c06_Idx_0_to_63_1 ADAS_Posn_PathIdx_ST3;
  c09_m_p_s_m12k8_89k2_0k2 ADAS_Posn_Spd_ST3;
} REC_ADAS_Posn_ST3_7tu0j7cag3wthixhamscgyjyr;


typedef struct
{
  c02_0_3_1_nSNA ADAS_ProfShort_AccurClass_CL_ST3;
  c01_FalseTrue ADAS_ProfShort_CtrlPoint_CL_ST3;
  c02_0_3_1_nSNA ADAS_ProfShort_CycCnt_CL_ST3;
  c10_m_0_510_1 ADAS_ProfShort_Dist1_CL_ST3;
  c03_MsgTyp_1_to_7 ADAS_ProfShort_MsgTyp_CL_ST3;
  c13_m_0_8190_1 ADAS_ProfShort_Offset_CL_ST3;
  c06_Idx_0_to_63_1 ADAS_ProfShort_PathIdx_CL_ST3;
  c01_FalseTrue ADAS_ProfShort_ReTr_CL_ST3;
  c01_FalseTrue ADAS_ProfShort_Updt_CL_ST3;
  c10_to_1022_1 ADAS_ProfShort_Value0_CL_ST3;
  c10_to_1022_1 ADAS_ProfShort_Value1_CL_ST3;
} REC_ADAS_Profile_Short_CurvLn_ST3;


typedef struct
{
  c10_m_0_510_1 ADAS_ProfShort_Dist1_CL_ST3;
  c13_m_0_8190_1 ADAS_ProfShort_Offset_CL_ST3;
  c06_Idx_0_to_63_1 ADAS_ProfShort_PathIdx_CL_ST3;
  c01_FalseTrue ADAS_ProfShort_ReTr_CL_ST3;
  c10_to_1022_1 ADAS_ProfShort_Value0_CL_ST3;
  c10_to_1022_1 ADAS_ProfShort_Value1_CL_ST3;
} REC_ADAS_Profile_Short_CurvLn_ST3_490g5rtcnid4ivawivkcosvcg;


typedef struct
{
  Rsrv04 Rsrv1_Bckl_Sw_Fx_Stat_ST3;
  c02_Bckl_Sw_Stat Bckl_Sw_D_Stat_ST3;
  c02_Bckl_Sw_Stat Bckl_Sw_FP_Stat_ST3;
  c16_CRC_woSNA CRC_Bckl_Sw_Fx_Stat_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_Bckl_Sw_Fx_Stat_Pr5_ST3;
} REC_Bckl_Sw_Fx_Stat_Pr5_ST3;


typedef struct
{
  c02_Bckl_Sw_Stat Bckl_Sw_D_Stat_ST3;
  c02_Bckl_Sw_Stat Bckl_Sw_FP_Stat_ST3;
} REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx;


typedef struct
{
  Rsrv04 Rsrv1_Bckl_Sw_Fx_Stat_ST3;
  c02_Bckl_Sw_Stat Bckl_Sw_D_Stat_ST3;
  c02_Bckl_Sw_Stat Bckl_Sw_FP_Stat_ST3;
  c16_CRC_woSNA CRC_Bckl_Sw_Fx_Stat_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_Bckl_Sw_Fx_Stat_Pr5_ST3;
} REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt;


typedef struct
{
  c16_CRC_woSNA CRC_CLkS_DrRltch_Stat_Pr5_ST3;
  c02_Dr_Stat DrRLtch_FL_Stat_ST3;
  c02_Dr_Stat DrRLtch_FR_Stat_ST3;
  c02_Dr_Stat DrRLtch_RL_Stat_ST3;
  c02_Dr_Stat DrRLtch_RR_Stat_ST3;
  c08_0_255_1_SNA_na SQC_CLkS_DrRltch_Stat_Pr5_ST3;
} REC_CLkS_DrRltch_Stat_Pr5_ST3;


typedef struct
{
  c02_Dr_Stat DrRLtch_FL_Stat_ST3;
  c02_Dr_Stat DrRLtch_FR_Stat_ST3;
} REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx;


typedef struct
{
  c16_CRC_woSNA CRC_DI_Odo_Pr5_ST3;
  c24_km_0_999999k9_0k1_Invld_SNA Odo_ST3;
  c08_0_255_1_SNA_na SQC_DI_Odo_Pr5_ST3;
} REC_DI_Odo_Pr5_ST3;


typedef struct
{
  c24_km_0_999999k9_0k1_Invld_SNA Odo_ST3;
} REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh;


typedef struct
{
  c04_DPC_GlobalMd_Rq DPC_GlobalMd_Rq_ST3;
  c02_Ndef_False_True_ST3 DPC_GlobalMd_TrgRq_ST3;
  c02_NDef_On_Off DPC_Md_eSPC_Carv_Rq_ST3;
  c02_NDef_On_Off DPC_Md_ABC_Preview_Rq_ST3;
  c04_DPC_Md_ESP_Rq_ST3 DPC_Md_ESP_Rq_ST3;
  c03_DPC_Md_ExhaustFlap DPC_Md_ExhstFlap_Rq_ST3;
  c02_NDef_ECO_Comfort DPC_Md_Ht_Rq_ST3;
  c05_DPC_Md_PT_HU DPC_Md_PT_Rq_ST3;
  c02_NDef_On_Off DPC_Md_PwrFreeD_Plus_Rq_ST3;
  c02_DPC_Md_SSA DPC_Md_SSA_Rq_ST3;
  c03_DPC_Md_St DPC_Md_St_Rq_ST3;
  c05_DPC_Md_Susp_V2 DPC_Md_Susp_Rq_ST3;
  c03_m2_p3_1_Init DPC_Md_SuspLvl_Rq_ST3;
  c04_NDef_Man_Auto DPC_Md_Tx_Rq_ST3;
  Rsrv05 Rsrv1_DPC_Md_Rq_ESP_Pr5_ST3;
  c16_CRC_woSNA CRC_DPC_Md_Rq_ESP_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_DPC_Md_Rq_ESP_Pr5_ST3;
  Rsrv24 Rsrv2_DPC_Md_Rq_ESP_Pr5_ST3;
} REC_DPC_Md_Rq_ESP_Pr5_ST3;


typedef struct
{
  c05_DPC_Md_PT_HU DPC_Md_PT_Rq_ST3;
} REC_DPC_Md_Rq_ESP_Pr5_ST3_18cj3r9lb95cc7w4q3mwqkn86;


typedef struct
{
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_01;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_02;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_03;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_04;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_05;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_06;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_07;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_08;
} REC_Develop8_Rq_RBTM_FL_ST3;


typedef struct
{
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_01;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_02;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_03;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_04;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_05;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_06;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_07;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_08;
} REC_Develop8_Rq_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv;


typedef struct
{
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_01;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_02;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_03;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_04;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_05;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_06;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_07;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_08;
} REC_Develop8_Rq_RBTM_FR_ST3;


typedef struct
{
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_01;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_02;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_03;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_04;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_05;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_06;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_07;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_08;
} REC_Develop8_Rq_RBTM_FR_ST3_dgfi1nrxtb0voy6rb7ybeonmv;


typedef struct
{
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_01;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_02;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_03;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_04;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_05;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_06;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_07;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_08;
} REC_Develop8_Rs_RBTM_FL_ST3;


typedef struct
{
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_01;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_02;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_03;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_04;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_05;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_06;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_07;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_08;
} REC_Develop8_Rs_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv;


typedef struct
{
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_01;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_02;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_03;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_04;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_05;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_06;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_07;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_08;
} REC_Develop8_Rs_RBTM_FR_ST3;


typedef struct
{
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_01;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_02;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_03;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_04;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_05;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_06;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_07;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_08;
} REC_Develop8_Rs_RBTM_FR_ST3_dgfi1nrxtb0voy6rb7ybeonmv;


typedef struct
{
  c16_CRC_woSNA CRC_ELC_Lvr_Stat_Pr5_ST3;
  c02_TurnIndLvr_Stat ELC_TurnIndLvr_Stat_ST3;
  Rsrv04 Rsrv1_ELC_Lvr_Stat_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_ELC_Lvr_Stat_Pr5_ST3;
  c02_HiBmLvr_Stat ELC_HiBmLvr_Stat_ST3;
} REC_ELC_Lvr_Stat_Pr5_ST3;


typedef struct
{
  c02_TurnIndLvr_Stat ELC_TurnIndLvr_Stat_ST3;
} REC_ELC_Lvr_Stat_Pr5_ST3_9t50popkpz30is106xpis1iyh;


typedef struct
{
  c16_CRC_woSNA CRC_EVC_CfgList_01_08_Pr5_ST3;
  c02_EVC_Stat EVC_CfgList_01_08_Stat_ST3;
  c06_EVC_BodyStyle_ST3 EVC_List01_BodyStyle_ST3;
  c06_EVC_VehLine_ST3 EVC_List02_VehLine_ST3;
  c02_StStyle EVC_List03_StStyle_ST3;
  c04_EVC_YrOfModf_2_ST3 EVC_List04_YrOfModf_2_ST3;
  c04_EVC_YrOfModf_1_ST3 EVC_List05_YrOfModf_1_ST3;
  c08_EVC_Country_extended EVC_List06_Country_ST3;
  c04_EVC_TxStyle_ST3 EVC_List07_TxStyle_ST3;
  c04_EVC_HL_Style_ST3 EVC_List08_HL_Style_ST3;
  c08_0_255_1_SNA_na SQC_EVC_CfgList_01_08_Pr5_ST3;
} REC_EVC_CfgList_01_08_Pr5_ST3;


typedef struct
{
  c02_StStyle EVC_List03_StStyle_ST3;
} REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby;


typedef struct
{
  c02_EVC_Stat EVC_CfgList_01_08_Stat_ST3;
  c02_StStyle EVC_List03_StStyle_ST3;
} REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw;


typedef struct
{
  c03_ISw_Stat ISw_Stat_ST3;
  c04_VehOpMode Veh_Op_Mode_ST3;
  c16_CRC_woSNA CRC_Ign_Stat_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_Ign_Stat_Pr5_ST3;
  DC_BOOL KG_StartSw_Psd_ST3;
} REC_Ign_Stat_Pr5_ST3;


typedef struct
{
  c03_ISw_Stat ISw_Stat_ST3;
} REC_Ign_Stat_Pr5_ST3_b0ko81o0x5jgvwtduf99gvzi0;


typedef struct
{
  c03_ISw_Stat ISw_Stat_ST3;
  c04_VehOpMode Veh_Op_Mode_ST3;
  c16_CRC_woSNA CRC_Ign_Stat_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_Ign_Stat_Pr5_ST3;
  DC_BOOL KG_StartSw_Psd_ST3;
} REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96;


typedef struct
{
  c08_UInt_SNA_na Meas_RBTM_FL_01;
  c08_UInt_SNA_na Meas_RBTM_FL_02;
  c08_UInt_SNA_na Meas_RBTM_FL_03;
  c08_UInt_SNA_na Meas_RBTM_FL_04;
  c08_UInt_SNA_na Meas_RBTM_FL_05;
  c08_UInt_SNA_na Meas_RBTM_FL_06;
  c08_UInt_SNA_na Meas_RBTM_FL_07;
  c08_UInt_SNA_na Meas_RBTM_FL_08;
} REC_Meas_RBTM_FL_ST3;


typedef struct
{
  c08_UInt_SNA_na Meas_RBTM_FL_01;
  c08_UInt_SNA_na Meas_RBTM_FL_02;
  c08_UInt_SNA_na Meas_RBTM_FL_03;
  c08_UInt_SNA_na Meas_RBTM_FL_04;
  c08_UInt_SNA_na Meas_RBTM_FL_05;
  c08_UInt_SNA_na Meas_RBTM_FL_06;
  c08_UInt_SNA_na Meas_RBTM_FL_07;
  c08_UInt_SNA_na Meas_RBTM_FL_08;
} REC_Meas_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv;


typedef struct
{
  c08_UInt_SNA_na Meas_RBTM_FR_01;
  c08_UInt_SNA_na Meas_RBTM_FR_02;
  c08_UInt_SNA_na Meas_RBTM_FR_03;
  c08_UInt_SNA_na Meas_RBTM_FR_04;
  c08_UInt_SNA_na Meas_RBTM_FR_05;
  c08_UInt_SNA_na Meas_RBTM_FR_06;
  c08_UInt_SNA_na Meas_RBTM_FR_07;
  c08_UInt_SNA_na Meas_RBTM_FR_08;
} REC_Meas_RBTM_FR_ST3;


typedef struct
{
  c08_UInt_SNA_na Meas_RBTM_FR_01;
  c08_UInt_SNA_na Meas_RBTM_FR_02;
  c08_UInt_SNA_na Meas_RBTM_FR_03;
  c08_UInt_SNA_na Meas_RBTM_FR_04;
  c08_UInt_SNA_na Meas_RBTM_FR_05;
  c08_UInt_SNA_na Meas_RBTM_FR_06;
  c08_UInt_SNA_na Meas_RBTM_FR_07;
  c08_UInt_SNA_na Meas_RBTM_FR_08;
} REC_Meas_RBTM_FR_ST3_dgfi1nrxtb0voy6rb7ybeonmv;


typedef struct
{
  DC_BOOL Impact_Y_ST3;
  c16_CRC_woSNA CRC_ORC_Impact2_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_ORC_Impact2_Pr5_ST3;
  DC_BOOL Impact_R1_ST3;
  DC_BOOL Impact_R2_ST3;
  DC_BOOL Impact_minor_ST3;
  DC_BOOL Impact_P_ST3;
  c03_VehPos_ST3 VehPosn_ST3;
} REC_ORC_Impact2_Pr5_ST3;


typedef struct
{
  DC_BOOL Impact_Y_ST3;
} REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh;


typedef struct
{
  DC_BOOL Impact_F1_ST3;
  DC_BOOL Impact_F3_ST3;
  DC_BOOL Impact_RO_type1_ST3;
  DC_BOOL Impact_RO_type2_ST3;
  c16_CRC_woSNA CRC_ORC_Impact3_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_ORC_Impact3_Pr5_ST3;
  DC_BOOL Impact_F2_ST3;
  DC_BOOL Impact_S1_ST3;
  DC_BOOL Impact_S2_ST3;
  DC_BOOL Impact_X_ST3;
} REC_ORC_Impact3_Pr5_ST3;


typedef struct
{
  DC_BOOL Impact_F1_ST3;
  DC_BOOL Impact_F3_ST3;
  DC_BOOL Impact_RO_type1_ST3;
  DC_BOOL Impact_RO_type2_ST3;
  c16_CRC_woSNA CRC_ORC_Impact3_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_ORC_Impact3_Pr5_ST3;
  DC_BOOL Impact_F2_ST3;
  DC_BOOL Impact_S1_ST3;
  DC_BOOL Impact_S2_ST3;
  DC_BOOL Impact_X_ST3;
} REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19;


typedef struct
{
  DC_BOOL Impact_X_ST3;
} REC_ORC_Impact3_Pr5_ST3_b4auermbjwizt3ufwg8j8br58;


typedef struct
{
  c16_CRC_woSNA CRC_PT4_PTCoor4_Pr5_ST3;
  c02_PT_Rdy_V2 PT4_PTCoor_PT_Rdy_ST3;
  c08_0_255_1_SNA_na SQC_PT4_PTCoor4_Pr5_ST3;
  c03_EngStartPN14_Stat PT4_PTCoor_EngStartPN14_Stat_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_SSA_EngSp_ST3;
  Rsrv01 Rsrv1_PT4_PTCoor_PT_Rdy_Pr5_ST3;
} REC_PT4_PTCoor4_Pr5_ST3;


typedef struct
{
  c03_EngStartPN14_Stat PT4_PTCoor_EngStartPN14_Stat_ST3;
} REC_PT4_PTCoor4_Pr5_ST3_6v3sj55wsjghho72slblc9pby;


typedef struct
{
  c02_PT_Rdy_V2 PT4_PTCoor_PT_Rdy_ST3;
} REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh;


typedef struct
{
  c02_PT_Rdy_V2 PT4_PTCoor_PT_Rdy_ST3;
  c03_EngStartPN14_Stat PT4_PTCoor_EngStartPN14_Stat_ST3;
} REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw;


typedef struct
{
  c16_CRC_woSNA CRC_PT4_PTCoor9_Pr5_ST3;
  c08_perc_0_100_0k4 PT4_PTCoor_AccelPdlPosn_D_Raw_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_KickDnSw_Psd_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_SSA_StopWarn_ST3;
  c08_0_255_1_SNA_na SQC_PT4_PTCoor9_Pr5_ST3;
  c14_rpm_0_16382_1 PT4_PTCoor_EngRPM_ST3;
  c08_perc_0_100_0k5 PT4_PTCoor_ClutchPdlPosn_CPC_ST3;
  c08_km_p_h_30_250_1_NoRcmnd PT4_PTCoor_EcoRcmnd_VehHighSpd_ST3;
  c08_km_p_h_30_250_1_NoRcmnd PT4_PTCoor_EcoRcmnd_VehSpd_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_EmgPath_Enbl_ST3;
  c08_V_0_25k4_0k1 PT4_PTCoor_EmgPath_Volt_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_LHOM_PkLk_ST3;
  Rsrv27 Rsrv4_PT4_PTCoor9_Pr5_ST3;
  c03_Accel_Md_ST3 PT4_PTCoor_Accel_Md_ST3;
  c02_TxBurnOut_Stat PT4_PTCoor_TxBurnOut_Stat_ST3;
  c09_km_p_h_0_500_1 PT4_PTCoor_VehFixMaxSpd_ST3;
  c02_NDef_Off_On_ST3 PT4_PTCoor_ShftTcase_Enbl_ST3;
  c10_PT4_PTCoor_DAS_Hlth_Stat PT4_PTCoor_DAS_Health_Stat_ST3;
  c12_rpm_0_16376_4 PT4_PTCoor_TrsmCtrl_OutRPM_ST3;
  c03_DCDCBuckSuprtStat_ST3 PT4_PTCoor_VEPM_DCDC_BuckSuprt_Stat_ST3;
} REC_PT4_PTCoor9_Pr5_ST3;


typedef struct
{
  c03_Accel_Md_ST3 PT4_PTCoor_Accel_Md_ST3;
} REC_PT4_PTCoor9_Pr5_ST3_cl82h0erzy2xfmj19jwk97p4u;


typedef struct
{
  c16_CRC_woSNA CRC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3;
  c04_DrvPosn_ST3 PT4_PTCoor_DrvPosn_Stat_ST3;
  c04_DrvPosn_ST3 PT4_PTCoor_DrvPosn_Target_ST3;
  c04_Gr PT4_PTCoor_Gr_ST3;
  c08_0_255_1_SNA_na SQC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3;
  c08_TxDrvPosn PT4_PTCoor_DrvPosn_Disp_Rq_ST3;
  c04_Gr_Target PT4_PTCoor_Gr_Target_ST3;
  c02_Inact_Act_ST3 PT4_PTCoor_DrvPosn_N_Actv_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_ShW_MnTrctAxl_D_Allowed_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_ShW_MnTrctAxl_N_Allowed_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_ShW_MnTrctAxl_P_Allowed_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_ShW_MnTrctAxl_R_Allowed_ST3;
  c02_SSA_Standby_Stat PT4_PTCoor_SSA_Standby_Stat_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_ShW_MnTrctAxl_P_Allow_Drv_ST3;
  Rsrv02 Rsrv1_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3;
} REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3;


typedef struct
{
  c04_DrvPosn_ST3 PT4_PTCoor_DrvPosn_Stat_ST3;
} REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh;


typedef struct
{
  c13_PresfAct_Adj_Rq PresfAct_Adj_Rq_ST3;
  Rsrv08 Rsrv6_Presf_Adj_ST3;
  c04_Presf_Lvl_V2 Presf_Lvl_ST3;
  c02_Presf_Snd Presf_Snd_Rq_ST3;
  c02_Ndef_False_True_ST3 PresfAccelReset_NotExcd_ST3;
  c02_false_true_sna Presf_Enbl_ST3;
  c02_false_true_sna Presf_Fric_Fctr_Lo_ST3;
  c03_No_Lt_Rt_Both PresfAct_TensSupp_Rq_ST3;
  c16_CRC_woSNA CRC_PresfAct_Adj_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_PresfAct_Adj_Pr5_ST3;
  c04_Presf_Frct_ST3 Presf_FricCoeff_Estim_ST3;
} REC_PresfAct_Adj_Pr5_ST3;


typedef struct
{
  c13_PresfAct_Adj_Rq PresfAct_Adj_Rq_ST3;
  Rsrv08 Rsrv6_Presf_Adj_ST3;
  c04_Presf_Lvl_V2 Presf_Lvl_ST3;
  c02_Presf_Snd Presf_Snd_Rq_ST3;
  c02_Ndef_False_True_ST3 PresfAccelReset_NotExcd_ST3;
  c02_false_true_sna Presf_Enbl_ST3;
  c02_false_true_sna Presf_Fric_Fctr_Lo_ST3;
  c03_No_Lt_Rt_Both PresfAct_TensSupp_Rq_ST3;
  c16_CRC_woSNA CRC_PresfAct_Adj_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_PresfAct_Adj_Pr5_ST3;
  c04_Presf_Frct_ST3 Presf_FricCoeff_Estim_ST3;
} REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j;


typedef struct
{
  c04_Presf_Lvl_V2 Presf_Lvl_ST3;
  c02_Ndef_False_True_ST3 PresfAccelReset_NotExcd_ST3;
} REC_PresfAct_Adj_Pr5_ST3_1fn392wedbq10w68dtk77u1sr;


typedef struct
{
  c08_ROE_0 ROE_0;
  c08_UInt_SNA_na ROE_1;
  c08_UInt_SNA_na ROE_2;
  c08_UInt_SNA_na ROE_3;
  c08_UInt_SNA_na ROE_4;
  c08_UInt_SNA_na ROE_5;
  c08_UInt_SNA_na ROE_6;
  c08_UInt_SNA_na ROE_7;
} REC_ROE_XX_ST3;


typedef struct
{
  c08_ROE_0 ROE_0;
  c08_UInt_SNA_na ROE_1;
  c08_UInt_SNA_na ROE_2;
  c08_UInt_SNA_na ROE_3;
  c08_UInt_SNA_na ROE_4;
  c08_UInt_SNA_na ROE_5;
  c08_UInt_SNA_na ROE_6;
  c08_UInt_SNA_na ROE_7;
} REC_ROE_XX_ST3_dgfi1nrxtb0voy6rb7ybeonmv;


typedef struct
{
  c08_km_p_h_0_254_1 VehSpd8_ST3;
  c16_CRC_woSNA CRC_VehSpd8_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_VehSpd8_Pr5_ST3;
} REC_VehSpd8_Pr5_ST3_4y11fh5xzvk3axiqy3atn5wk4;


typedef struct
{
  Ssa_Data32ByteType data;
  boolean validated;
} RightsM_AuthNonceType;


typedef struct
{
  Ssa_Data32ByteType data;
  uint64 timestamp;
  boolean isValid;
} RightsM_NonceType;


typedef struct
{
  Ssa_Data32ByteType testerPublicKey;
  RightsM_SerialNumberType testerSerialNumber;
  RightsM_IssuerType testerIssuer;
  RightsM_DiagnosticUserRoleType diagnosticUserRole;
  boolean restrictedAuthentication;
} RightsM_SecuritySettingsType;


typedef struct
{
  uint16 freshnessValueID;
  SecOC_VerificationResultType verificationStatus;
  uint16 secOCDataId;
} SecOC_VerificationStatusType;


typedef struct
{
  uint16 PduId;
  Ssa_ThresholdExceededType ThresholdExcceded;
} Ssa_FailedMacVerifCounterEventType;


typedef struct
{
  Ssa_IgnitionStatus_Prim ISw_Stat_ST3;
} Ssa_IgnitionStatusType;


typedef struct
{
  uint64 LocalTickCount;
  Ssa_TickCountSyncStateType SyncStatus;
} Ssa_LocalTickCountAndSyncStatusType;


typedef struct
{
  Ssa_BusOdometerTyp Odo_ST3;
} Ssa_OdometerRecordType;


typedef struct
{
  uint64 tickCountOffset;
  TimeM_DateTimeType dateTimeReference;
} TimeM_RealTimeOffsetType;


typedef struct
{
  Dcm_Data1ByteType Equipment1;
  Dcm_Data1ByteType Equipment2;
  Dcm_Data1ByteType Equipment3;
  Dcm_Data1ByteType RaceStart_Stufe1;
  Dcm_Data1ByteType RaceStart_Stufe2;
  Dcm_Data2ByteType Unterspannungsabbruchschwelle;
  Dcm_Data2ByteType Unterspannungsbereichsschwelle;
  Dcm_Data2ByteType Uberspannungsbereichsschwelle;
  Dcm_Data2ByteType Uberspannungsabbruchschwelle;
} VehicleEquipment_StorageType;


typedef struct
{
  Dcm_Data2ByteType Bitfield;
  Dcm_Data1ByteType Zykluszeit_Messtechnik;
} ZZZ_VehicleEquipment_Development_StorageType;


typedef struct
{
  UInt32 u32SystemTimeInSec;
  UInt8 u8SystemTimeOffset;
} stAbsoluteSystemTimeType;


typedef struct
{
  CertP_VerificationResultType verificationResult;
  uint16 parsedCertLength;
  CertP_BerElementType signedCertData;
  uint8 version;
  CertP_BerElementType serialNumber;
  CertP_BerElementType certSignatureAlgOID;
  CertP_BerElementType issuer;
  CertP_TimeType validNotBefore;
  CertP_TimeType validNotAfter;
  CertP_BerElementType subject;
  CertP_BerElementType publicKey;
  CertP_BerElementType subjectKeyIdentifier;
  CertP_BerElementType authorityKeyIdentifier;
  uint16 keyUsage;
  uint8 basicConstraints;
  CertP_PkiRoleType pkiRole;
  RightsM_DiagnosticUserRoleType userRole;
  CertP_BerElementType targetECU;
  CertP_BerElementType targetVIN;
  CertP_BerElementType nonce;
  uint8 prodQualifier;
  CertP_BerElementType uniqueEcuId;
  CertP_BerElementType service;
  CertP_BerElementType holderIssuer;
  CertP_BerElementType holderSerialNumber;
  CertP_BerElementType signatureAlgorithmOID;
  CertP_BerElementType signature;
  uint8 specialECU;
  CertP_BerElementType targetSubjectKeyIdentifier;
} CertP_ParsedCertStructureType;


typedef struct
{
  uint8 currentDiagnosticChannel;
  RightsM_AuthenticationStateType authentication_State;
  uint8 authentication_ExpectedTask;
  RightsM_ChallengeEcuType authentication_ChallengeEcu;
  uint16 authenticationTimeoutTimer;
  boolean defaultSessionRequestFlag;
  RightsM_SecuritySettingsType securitySettings;
} RightsM_DiagChannelDataType;
# 2802 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_Type.h"
typedef void * NvM_ASR42_DstPtrType;


typedef const void * NvM_ASR42_SrcPtrType;


typedef void * NvM_DstPtrType;


typedef const void * NvM_SrcPtrType;


typedef uint16 Rte_DT_ERR_EventLog_0;


typedef uint8 Rte_DT_ERR_EventLog_1;


typedef uint8 impl_BswM_RoEMode_1;


typedef uint8 impl_BswM_RoEMode_2;


typedef uint8 impl_BswM_RoEMode_3;


typedef uint8 impl_BswM_RoEMode_4;


typedef uint8 impl_BswM_RoEMode_5;


typedef uint8 impl_BswM_RoEMode_6;


typedef uint8 Csm_EncryptDataType_AES128Encrypt[80];


typedef uint8 Csm_EncryptResultType_AES128Encrypt[80];


typedef uint8 Csm_KeyDataType_Ssa_PrivateEcuKey[32];


typedef uint8 Csm_KeyDataType_Ssa_SharedSecret[32];


typedef uint8 Csm_SeedDataType_Ssa_RandomSeed[209];


typedef uint8 Csm_SignatureGenerateDataType_SigGenEd25519ph[8192];


typedef uint8 Csm_SignatureGenerateResultType_SigGenEd25519ph[64];


typedef uint8 Dcm_DataDID_F18C_BeltAssemblySerialNumberData_ArrayType[20];


typedef uint8 Dcm_DataDID_F18C_BeltAssemblySerialNumberData_ArrayType_1[20];


typedef uint8 Dcm_DataDID_FD03_AEETraceabilityNumberData_ArrayType[12];


typedef uint8 Dcm_DataDID_FD8B_BeltAssemblyManufDateData_ArrayType[3];


typedef uint8 Dcm_DataDID_FD8C_BeltAssemblySerialNumberData_ArrayType[10];


typedef uint8 Dcm_DataDID_FD8C_BeltAssemblySerialNumberData_ArrayType_1[10];


typedef uint8 Dem_ASR42_MaxDataValueType[1];


typedef uint8 Dem_ASR42_MaxDataValueType_1[1];


typedef uint8 Dem_ASR42_MaxDataValueType_2[1];


typedef uint8 Dem_ASR42_MaxDataValueType_3[1];


typedef uint8 Dem_ASR42_MaxDataValueType_4[1];


typedef uint8 Dem_MaxDataValueTypeAlv[5];


typedef uint8 SwcDiag_ExtTesterDataArrayType[1];


typedef uint8 SwcDiag_OdometerDataArrayType[2];


typedef uint8 SwcDiag_SecurityEventDataArrayType[7];


typedef uint8 SwcDiag_TimestampDataArrayType[5];


typedef struct
{
  Rte_DT_ERR_EventLog_0 u16EventId;
  Rte_DT_ERR_EventLog_1 u8EventStatus;
} ERR_EventLog;


typedef uint8 COM_C04_Sig121;


typedef Csm_VerifyResultType * Csm_VerifyResultPtr;


typedef boolean DAI_boolean;


typedef uint16 DC_U16;


typedef uint8 DC_U8;


typedef sint32 DT_SInt32;


typedef uint16 DT_Uint16;


typedef uint32 DT_Uint32;


typedef uint8 DT_uint8;


typedef uint8 Dcm_ASR42_ProtocolType;


typedef uint8 Dcm_ASR42_SecLevelType;


typedef uint8 Dcm_ASR42_SesCtrlType;


typedef uint8 Dem_ASR42_DTCFormatType;


typedef uint8 Dem_ASR42_DTCFormatType_1;


typedef uint8 Dem_ASR42_DTCFormatType_2;


typedef uint8 Dem_ASR42_DTCFormatType_3;


typedef uint8 Dem_ASR42_DTCFormatType_4;


typedef uint8 Dem_ASR42_DebounceResetStatusType;


typedef uint16 Dem_ASR42_EventIdType;


typedef uint8 Dem_ASR42_EventStatusExtendedType_1;


typedef uint8 Dem_ASR42_EventStatusExtendedType_2;


typedef uint8 Dem_ASR42_EventStatusExtendedType_3;


typedef uint8 Dem_ASR42_EventStatusExtendedType_4;


typedef uint8 Dem_DTCOriginTypeALV;


typedef uint8 Dem_DebouncingStateType_1;


typedef uint8 Dem_DebouncingStateType_2;


typedef uint8 Dem_DebouncingStateType_3;


typedef uint8 Dem_DebouncingStateType_4;


typedef uint16 Dem_EventIdType_1;


typedef uint16 Dem_EventIdType_2;


typedef uint16 Dem_EventIdType_3;


typedef uint16 Dem_EventIdType_4;


typedef uint16 Dem_EventIdType_5;


typedef uint16 Dem_EventIdType_6;


typedef uint8 Dem_OperationCycleIdType;


typedef uint8 Dem_UdsStatusByteType_1;


typedef uint8 Dem_UdsStatusByteType_2;


typedef uint8 Dem_UdsStatusByteType_3;


typedef uint8 Dem_UdsStatusByteType_4;


typedef uint8 Dem_UdsStatusByteType_5;


typedef uint8 Dem_UdsStatusByteType_6;


typedef uint16 NvM_ASR42_BlockIdType_1;


typedef uint16 NvM_ASR42_BlockIdType_2;


typedef uint16 NvM_ASR42_BlockIdType_3;


typedef uint16 NvM_ASR42_BlockIdType_4;


typedef uint16 NvM_ASR42_BlockIdType_5;


typedef uint16 NvM_ASR42_BlockIdType_6;


typedef uint8 NvM_ASR42_RequestResultType_1;


typedef uint8 NvM_ASR42_RequestResultType_2;


typedef uint8 NvM_ASR42_RequestResultType_3;


typedef uint8 NvM_ASR42_RequestResultType_4;


typedef uint8 NvM_ASR42_RequestResultType_5;


typedef uint8 NvM_ASR42_RequestResultType_6;


typedef uint8 SwcDiag_AvailabilityCategoryType;


typedef uint8 SwcDiag_BlockNumberType;


typedef uint32 SwcDiag_BusOdometerType;


typedef uint16 SwcDiag_CnsmblObslscncType;


typedef uint8 SwcDiag_ExtTesterStatusType;


typedef uint8 SwcDiag_FunctionNumberType;


typedef uint8 SwcDiag_IgnitionStatusType;


typedef uint8 SwcDiag_ProductionModeType;


typedef uint8 SwcDiag_RoELitePDUKindType;


typedef uint8 SwcDiag_TransportationModeType;


typedef uint8 SwcDiag_VehicleStartupType;


typedef uint16 SwcDiag_VoltageType;


typedef uint16 UInt16_1;


typedef uint16 UInt16_2;


typedef uint16 UInt16_3;


typedef uint16 UInt16_4;


typedef uint16 UInt16_5;


typedef uint16 UInt16_6;


typedef uint32 UInt32_1;


typedef uint32 UInt32_2;


typedef uint32 UInt32_3;


typedef uint32 UInt32_4;


typedef uint32 UInt32_5;


typedef uint32 UInt32_6;


typedef uint8 UInt8_1;


typedef uint8 UInt8_2;


typedef uint8 UInt8_3;


typedef uint8 UInt8_4;


typedef uint8 UInt8_5;


typedef uint8 UInt8_6;


typedef uint8 b8AlgorithmFlagsStatusType_1;


typedef uint8 b8AlgorithmFlagsStatusType_2;


typedef uint8 b8AlgorithmFlagsStatusType_3;


typedef uint8 b8AlgorithmFlagsStatusType_4;


typedef uint8 b8AlgorithmFlagsStatusType_5;


typedef uint8 b8AlgorithmFlagsStatusType_6;


typedef uint8 b8BooleanType_1;


typedef uint8 b8BooleanType_2;


typedef uint8 b8BooleanType_3;


typedef uint8 b8BooleanType_4;


typedef uint8 b8BooleanType_5;


typedef uint8 b8BooleanType_6;


typedef uint8 b8DefectStatusType_1;


typedef uint8 b8DefectStatusType_2;


typedef uint8 b8DefectStatusType_3;


typedef uint8 b8DefectStatusType_4;


typedef uint8 b8DefectStatusType_5;


typedef uint8 b8DefectStatusType_6;


typedef uint8 b8IsActiveDiagSessionType_1;


typedef uint8 b8IsActiveDiagSessionType_2;


typedef uint8 b8IsActiveDiagSessionType_3;


typedef uint8 b8IsActiveDiagSessionType_4;


typedef uint8 b8IsActiveDiagSessionType_5;


typedef uint8 b8IsActiveDiagSessionType_6;


typedef uint8 b8IsCarAccelerationLowType_1;


typedef uint8 b8IsCarAccelerationLowType_2;


typedef uint8 b8IsCarAccelerationLowType_3;


typedef uint8 b8IsCarAccelerationLowType_4;


typedef uint8 b8IsCarAccelerationLowType_5;


typedef uint8 b8IsCarAccelerationLowType_6;


typedef uint8 b8IsCarCrankingActiveType_1;


typedef uint8 b8IsCarCrankingActiveType_2;


typedef uint8 b8IsCarCrankingActiveType_3;


typedef uint8 b8IsCarCrankingActiveType_4;


typedef uint8 b8IsCarCrankingActiveType_5;


typedef uint8 b8IsCarCrankingActiveType_6;


typedef uint8 b8IsCarCrashDetectedType_1;


typedef uint8 b8IsCarCrashDetectedType_2;


typedef uint8 b8IsCarCrashDetectedType_3;


typedef uint8 b8IsCarCrashDetectedType_4;


typedef uint8 b8IsCarCrashDetectedType_5;


typedef uint8 b8IsCarCrashDetectedType_6;


typedef uint8 b8PyroActivationStatusType_1;


typedef uint8 b8PyroActivationStatusType_2;


typedef uint8 b8PyroActivationStatusType_3;


typedef uint8 b8PyroActivationStatusType_4;


typedef uint8 b8PyroActivationStatusType_5;


typedef uint8 b8PyroActivationStatusType_6;


typedef boolean c01_bit_dummy;


typedef uint8 c02_NotActv_Actv_SNA;


typedef uint8 c02_WakeUp_Stat;


typedef uint8 c03_Off_On_Chng_Idle_ST3;


typedef uint8 c07_na_0_to_127_1;


typedef uint8 c08_0_254_1;


typedef uint8 c08_Platform_Stat;


typedef uint8 c08_WU_REASON_ECUx;


typedef uint8 c08_na_0_to_255_1;


typedef uint8 c08_perc_0_254_1;


typedef uint16 c09_na_0_to_511_1;


typedef uint16 c10_WU_REASON_ECUx;


typedef uint16 c10_na_0_to_1023_1;


typedef uint16 c11_0_2046_1;


typedef uint16 c12_na_0_to_4095_1;


typedef uint16 c16_0_65533_1;


typedef uint16 c16_0_65535_1_SNA_na;


typedef uint16 c16_CRC_woSNA_1;


typedef uint32 c24_na_0_to_16777215_1;


typedef uint8 dtRef_;


typedef sint16 s16AccelerationPedalPositionRateType_1;


typedef sint16 s16AccelerationPedalPositionRateType_2;


typedef sint16 s16AccelerationPedalPositionRateType_3;


typedef sint16 s16AccelerationPedalPositionRateType_4;


typedef sint16 s16AccelerationPedalPositionRateType_5;


typedef sint16 s16AccelerationPedalPositionRateType_6;


typedef sint16 s16AccelerationType_1;


typedef sint16 s16AccelerationType_2;


typedef sint16 s16AccelerationType_3;


typedef sint16 s16AccelerationType_4;


typedef sint16 s16AccelerationType_5;


typedef sint16 s16AccelerationType_6;


typedef sint16 s16AngleRateType_1;


typedef sint16 s16AngleRateType_2;


typedef sint16 s16AngleRateType_3;


typedef sint16 s16AngleRateType_4;


typedef sint16 s16AngleRateType_5;


typedef sint16 s16AngleRateType_6;


typedef sint16 s16BeltPosition_degType_1;


typedef sint16 s16BeltPosition_degType_2;


typedef sint16 s16BeltPosition_degType_3;


typedef sint16 s16BeltPosition_degType_4;


typedef sint16 s16BeltPosition_degType_5;


typedef sint16 s16BeltPosition_degType_6;


typedef sint16 s16BeltPosition_mmType_1;


typedef sint16 s16BeltPosition_mmType_2;


typedef sint16 s16BeltPosition_mmType_3;


typedef sint16 s16BeltPosition_mmType_4;


typedef sint16 s16BeltPosition_mmType_5;


typedef sint16 s16BeltPosition_mmType_6;


typedef sint16 s16BrakePressureRateType_1;


typedef sint16 s16BrakePressureRateType_2;


typedef sint16 s16BrakePressureRateType_3;


typedef sint16 s16BrakePressureRateType_4;


typedef sint16 s16BrakePressureRateType_5;


typedef sint16 s16BrakePressureRateType_6;


typedef sint16 s16HWAngleType_1;


typedef sint16 s16HWAngleType_2;


typedef sint16 s16HWAngleType_3;


typedef sint16 s16HWAngleType_4;


typedef sint16 s16HWAngleType_5;


typedef sint16 s16HWAngleType_6;


typedef sint16 s16HWRateType_1;


typedef sint16 s16HWRateType_2;


typedef sint16 s16HWRateType_3;


typedef sint16 s16HWRateType_4;


typedef sint16 s16HWRateType_5;


typedef sint16 s16HWRateType_6;


typedef sint16 s16InternalTemperature_deg_Type_1;


typedef sint16 s16InternalTemperature_deg_Type_2;


typedef sint16 s16InternalTemperature_deg_Type_3;


typedef sint16 s16InternalTemperature_deg_Type_4;


typedef sint16 s16InternalTemperature_deg_Type_5;


typedef sint16 s16InternalTemperature_deg_Type_6;


typedef sint16 s16MotorPowerOrderType_1;


typedef sint16 s16MotorPowerOrderType_2;


typedef sint16 s16MotorPowerOrderType_3;


typedef sint16 s16MotorPowerOrderType_4;


typedef sint16 s16MotorPowerOrderType_5;


typedef sint16 s16MotorPowerOrderType_6;


typedef sint32 s32BeltSpeed_deg_sType_1;


typedef sint32 s32BeltSpeed_deg_sType_2;


typedef sint32 s32BeltSpeed_deg_sType_3;


typedef sint32 s32BeltSpeed_deg_sType_4;


typedef sint32 s32BeltSpeed_deg_sType_5;


typedef sint32 s32BeltSpeed_deg_sType_6;


typedef sint32 s32BeltSpeed_mm_sType_1;


typedef sint32 s32BeltSpeed_mm_sType_2;


typedef sint32 s32BeltSpeed_mm_sType_3;


typedef sint32 s32BeltSpeed_mm_sType_4;


typedef sint32 s32BeltSpeed_mm_sType_5;


typedef sint32 s32BeltSpeed_mm_sType_6;


typedef sint32 s32MotorCurrentInmAType_1;


typedef sint32 s32MotorCurrentInmAType_2;


typedef sint32 s32MotorCurrentInmAType_3;


typedef sint32 s32MotorCurrentInmAType_4;


typedef sint32 s32MotorCurrentInmAType_5;


typedef sint32 s32MotorCurrentInmAType_6;


typedef sint32 s32OrderValueType_1;


typedef sint32 s32OrderValueType_2;


typedef sint32 s32OrderValueType_3;


typedef sint32 s32OrderValueType_4;


typedef sint32 s32OrderValueType_5;


typedef sint32 s32OrderValueType_6;


typedef sint8 s8MotorCurrentInAType_1;


typedef sint8 s8MotorCurrentInAType_2;


typedef sint8 s8MotorCurrentInAType_3;


typedef sint8 s8MotorCurrentInAType_4;


typedef sint8 s8MotorCurrentInAType_5;


typedef sint8 s8MotorCurrentInAType_6;


typedef sint16 sint16_s16;


typedef uint16 u16AecGroupsType_1;


typedef uint16 u16AecGroupsType_2;


typedef uint16 u16AecGroupsType_3;


typedef uint16 u16AecGroupsType_4;


typedef uint16 u16AecGroupsType_5;


typedef uint16 u16AecGroupsType_6;


typedef uint16 u16BoostPWMOrderType_1;


typedef uint16 u16BoostPWMOrderType_2;


typedef uint16 u16BoostPWMOrderType_3;


typedef uint16 u16BoostPWMOrderType_4;


typedef uint16 u16BoostPWMOrderType_5;


typedef uint16 u16BoostPWMOrderType_6;


typedef uint16 u16BrakePressureType_1;


typedef uint16 u16BrakePressureType_2;


typedef uint16 u16BrakePressureType_3;


typedef uint16 u16BrakePressureType_4;


typedef uint16 u16BrakePressureType_5;


typedef uint16 u16BrakePressureType_6;


typedef uint16 u16CalibBlockIdType_1;


typedef uint16 u16CalibBlockIdType_2;


typedef uint16 u16CalibBlockIdType_3;


typedef uint16 u16CalibBlockIdType_4;


typedef uint16 u16CalibBlockIdType_5;


typedef uint16 u16CalibBlockIdType_6;


typedef uint16 u16CurrentInLSBType_1;


typedef uint16 u16CurrentInLSBType_2;


typedef uint16 u16CurrentInLSBType_3;


typedef uint16 u16CurrentInLSBType_4;


typedef uint16 u16CurrentInLSBType_5;


typedef uint16 u16CurrentInLSBType_6;


typedef uint16 u16InternalTemperatureType_1;


typedef uint16 u16InternalTemperatureType_2;


typedef uint16 u16InternalTemperatureType_3;


typedef uint16 u16InternalTemperatureType_4;


typedef uint16 u16InternalTemperatureType_5;


typedef uint16 u16InternalTemperatureType_6;


typedef uint16 u16Resistance_mOhmType_1;


typedef uint16 u16Resistance_mOhmType_2;


typedef uint16 u16Resistance_mOhmType_3;


typedef uint16 u16Resistance_mOhmType_4;


typedef uint16 u16Resistance_mOhmType_5;


typedef uint16 u16Resistance_mOhmType_6;


typedef uint16 u16SampledSignalType_1;


typedef uint16 u16SampledSignalType_2;


typedef uint16 u16SampledSignalType_3;


typedef uint16 u16SampledSignalType_4;


typedef uint16 u16SampledSignalType_5;


typedef uint16 u16SampledSignalType_6;


typedef uint16 u16StepDurationType_1;


typedef uint16 u16StepDurationType_2;


typedef uint16 u16StepDurationType_3;


typedef uint16 u16StepDurationType_4;


typedef uint16 u16StepDurationType_5;


typedef uint16 u16StepDurationType_6;


typedef uint16 u16VehicleSpeedType_1;


typedef uint16 u16VehicleSpeedType_2;


typedef uint16 u16VehicleSpeedType_3;


typedef uint16 u16VehicleSpeedType_4;


typedef uint16 u16VehicleSpeedType_5;


typedef uint16 u16VehicleSpeedType_6;


typedef uint16 u16VoltageType_1;


typedef uint16 u16VoltageType_2;


typedef uint16 u16VoltageType_3;


typedef uint16 u16VoltageType_4;


typedef uint16 u16VoltageType_5;


typedef uint16 u16VoltageType_6;


typedef uint32 u32ChecksumType;


typedef uint32 u32DeficiencyLevelType_1;


typedef uint32 u32DeficiencyLevelType_2;


typedef uint32 u32DeficiencyLevelType_3;


typedef uint32 u32DeficiencyLevelType_4;


typedef uint32 u32DeficiencyLevelType_5;


typedef uint32 u32DeficiencyLevelType_6;


typedef uint32 u32InternalCounterType_1;


typedef uint32 u32InternalCounterType_2;


typedef uint32 u32InternalCounterType_3;


typedef uint32 u32InternalCounterType_4;


typedef uint32 u32InternalCounterType_5;


typedef uint32 u32InternalCounterType_6;


typedef uint32 u32ModeMaskType_1;


typedef uint32 u32ModeMaskType_2;


typedef uint32 u32ModeMaskType_3;


typedef uint32 u32ModeMaskType_4;


typedef uint32 u32ModeMaskType_5;


typedef uint32 u32ModeMaskType_6;


typedef uint32 u32RelativeSystemTimeType_1;


typedef uint32 u32RelativeSystemTimeType_2;


typedef uint32 u32RelativeSystemTimeType_3;


typedef uint32 u32RelativeSystemTimeType_4;


typedef uint32 u32RelativeSystemTimeType_5;


typedef uint32 u32RelativeSystemTimeType_6;


typedef uint32 u32ResetCauseType_1;


typedef uint32 u32ResetCauseType_2;


typedef uint32 u32ResetCauseType_3;


typedef uint32 u32ResetCauseType_4;


typedef uint32 u32ResetCauseType_5;


typedef uint32 u32ResetCauseType_6;


typedef uint32 u32ResetReasonNotificationStatusType_1;


typedef uint32 u32ResetReasonNotificationStatusType_2;


typedef uint32 u32ResetReasonNotificationStatusType_3;


typedef uint32 u32ResetReasonNotificationStatusType_4;


typedef uint32 u32ResetReasonNotificationStatusType_5;


typedef uint32 u32ResetReasonNotificationStatusType_6;


typedef uint32 u32ResetReasonNotificationType_1;


typedef uint32 u32ResetReasonNotificationType_2;


typedef uint32 u32ResetReasonNotificationType_3;


typedef uint32 u32ResetReasonNotificationType_4;


typedef uint32 u32ResetReasonNotificationType_5;


typedef uint32 u32ResetReasonNotificationType_6;


typedef uint8 u8AccelerationPedalPositionType_1;


typedef uint8 u8AccelerationPedalPositionType_2;


typedef uint8 u8AccelerationPedalPositionType_3;


typedef uint8 u8AccelerationPedalPositionType_4;


typedef uint8 u8AccelerationPedalPositionType_5;


typedef uint8 u8AccelerationPedalPositionType_6;


typedef uint8 u8AecCommandType_1;


typedef uint8 u8AecCommandType_2;


typedef uint8 u8AecCommandType_3;


typedef uint8 u8AecCommandType_4;


typedef uint8 u8AecCommandType_5;


typedef uint8 u8AecCommandType_6;


typedef uint8 u8AecIdentifierType_1;


typedef uint8 u8AecIdentifierType_2;


typedef uint8 u8AecIdentifierType_3;


typedef uint8 u8AecIdentifierType_4;


typedef uint8 u8AecIdentifierType_5;


typedef uint8 u8AecIdentifierType_6;


typedef uint8 u8AecStatusType_1;


typedef uint8 u8AecStatusType_2;


typedef uint8 u8AecStatusType_3;


typedef uint8 u8AecStatusType_4;


typedef uint8 u8AecStatusType_5;


typedef uint8 u8AecStatusType_6;


typedef uint8 u8AutoTestIdType_1;


typedef uint8 u8AutoTestIdType_2;


typedef uint8 u8AutoTestIdType_3;


typedef uint8 u8AutoTestIdType_4;


typedef uint8 u8AutoTestIdType_5;


typedef uint8 u8AutoTestIdType_6;


typedef uint8 u8BatteryVoltageSurveyStatusType_1;


typedef uint8 u8BatteryVoltageSurveyStatusType_2;


typedef uint8 u8BatteryVoltageSurveyStatusType_3;


typedef uint8 u8BatteryVoltageSurveyStatusType_4;


typedef uint8 u8BatteryVoltageSurveyStatusType_5;


typedef uint8 u8BatteryVoltageSurveyStatusType_6;


typedef uint8 u8BeltParkingAuthorizationStateType_1;


typedef uint8 u8BeltParkingAuthorizationStateType_2;


typedef uint8 u8BeltParkingAuthorizationStateType_3;


typedef uint8 u8BeltParkingAuthorizationStateType_4;


typedef uint8 u8BeltParkingAuthorizationStateType_5;


typedef uint8 u8BeltParkingAuthorizationStateType_6;


typedef uint8 u8BeltSlackStatusType_1;


typedef uint8 u8BeltSlackStatusType_2;


typedef uint8 u8BeltSlackStatusType_3;


typedef uint8 u8BeltSlackStatusType_4;


typedef uint8 u8BeltSlackStatusType_5;


typedef uint8 u8BeltSlackStatusType_6;


typedef uint8 u8CanNmStateType_1;


typedef uint8 u8CanNmStateType_2;


typedef uint8 u8CanNmStateType_3;


typedef uint8 u8CanNmStateType_4;


typedef uint8 u8CanNmStateType_5;


typedef uint8 u8CanNmStateType_6;


typedef uint8 u8ClkStatusType_1;


typedef uint8 u8ClkStatusType_2;


typedef uint8 u8ClkStatusType_3;


typedef uint8 u8ClkStatusType_4;


typedef uint8 u8ClkStatusType_5;


typedef uint8 u8ClkStatusType_6;


typedef uint8 u8CycleNumberType_1;


typedef uint8 u8CycleNumberType_2;


typedef uint8 u8CycleNumberType_3;


typedef uint8 u8CycleNumberType_4;


typedef uint8 u8CycleNumberType_5;


typedef uint8 u8CycleNumberType_6;


typedef uint8 u8DoorSwitchStatusType_1;


typedef uint8 u8DoorSwitchStatusType_2;


typedef uint8 u8DoorSwitchStatusType_3;


typedef uint8 u8DoorSwitchStatusType_4;


typedef uint8 u8DoorSwitchStatusType_5;


typedef uint8 u8DoorSwitchStatusType_6;


typedef uint8 u8EccErrorStatusType_1;


typedef uint8 u8EccErrorStatusType_2;


typedef uint8 u8EccErrorStatusType_3;


typedef uint8 u8EccErrorStatusType_4;


typedef uint8 u8EccErrorStatusType_5;


typedef uint8 u8EccErrorStatusType_6;


typedef uint8 u8EccErrorType_1;


typedef uint8 u8EccErrorType_2;


typedef uint8 u8EccErrorType_3;


typedef uint8 u8EccErrorType_4;


typedef uint8 u8EccErrorType_5;


typedef uint8 u8EccErrorType_6;


typedef uint8 u8EsmEventIdType_1;


typedef uint8 u8EsmEventIdType_2;


typedef uint8 u8EsmEventIdType_3;


typedef uint8 u8EsmEventIdType_4;


typedef uint8 u8EsmEventIdType_5;


typedef uint8 u8EsmEventIdType_6;


typedef uint8 u8EsmStateType_1;


typedef uint8 u8EsmStateType_2;


typedef uint8 u8EsmStateType_3;


typedef uint8 u8EsmStateType_4;


typedef uint8 u8EsmStateType_5;


typedef uint8 u8EsmStateType_6;


typedef uint8 u8HapticRequestType_1;


typedef uint8 u8HapticRequestType_2;


typedef uint8 u8HapticRequestType_3;


typedef uint8 u8HapticRequestType_4;


typedef uint8 u8HapticRequestType_5;


typedef uint8 u8HapticRequestType_6;


typedef uint8 u8JobTypesListType_1;


typedef uint8 u8JobTypesListType_2;


typedef uint8 u8JobTypesListType_3;


typedef uint8 u8JobTypesListType_4;


typedef uint8 u8JobTypesListType_5;


typedef uint8 u8JobTypesListType_6;


typedef uint8 u8KlemmenStatusType_1;


typedef uint8 u8KlemmenStatusType_2;


typedef uint8 u8KlemmenStatusType_3;


typedef uint8 u8KlemmenStatusType_4;


typedef uint8 u8KlemmenStatusType_5;


typedef uint8 u8KlemmenStatusType_6;


typedef uint8 u8MemoryClusterType_1;


typedef uint8 u8MemoryClusterType_2;


typedef uint8 u8MemoryClusterType_3;


typedef uint8 u8MemoryClusterType_4;


typedef uint8 u8MemoryClusterType_5;


typedef uint8 u8MemoryClusterType_6;


typedef uint8 u8ModeStatusType_1;


typedef uint8 u8ModeStatusType_2;


typedef uint8 u8ModeStatusType_3;


typedef uint8 u8ModeStatusType_4;


typedef uint8 u8ModeStatusType_5;


typedef uint8 u8ModeStatusType_6;


typedef uint8 u8MotorStageStatusType_1;


typedef uint8 u8MotorStageStatusType_2;


typedef uint8 u8MotorStageStatusType_3;


typedef uint8 u8MotorStageStatusType_4;


typedef uint8 u8MotorStageStatusType_5;


typedef uint8 u8MotorStageStatusType_6;


typedef uint8 u8OrdersListType_1;


typedef uint8 u8OrdersListType_2;


typedef uint8 u8OrdersListType_3;


typedef uint8 u8OrdersListType_4;


typedef uint8 u8OrdersListType_5;


typedef uint8 u8OrdersListType_6;


typedef uint8 u8PreCrashRequestType_1;


typedef uint8 u8PreCrashRequestType_2;


typedef uint8 u8PreCrashRequestType_3;


typedef uint8 u8PreCrashRequestType_4;


typedef uint8 u8PreCrashRequestType_5;


typedef uint8 u8PreCrashRequestType_6;


typedef uint8 u8PreCrashSeverityLevelType_1;


typedef uint8 u8PreCrashSeverityLevelType_2;


typedef uint8 u8PreCrashSeverityLevelType_3;


typedef uint8 u8PreCrashSeverityLevelType_4;


typedef uint8 u8PreCrashSeverityLevelType_5;


typedef uint8 u8PreCrashSeverityLevelType_6;


typedef uint8 u8PwmChannelIdType_1;


typedef uint8 u8PwmChannelIdType_2;


typedef uint8 u8PwmChannelIdType_3;


typedef uint8 u8PwmChannelIdType_4;


typedef uint8 u8PwmChannelIdType_5;


typedef uint8 u8PwmChannelIdType_6;


typedef uint8 u8RetractionStatusType_1;


typedef uint8 u8RetractionStatusType_2;


typedef uint8 u8RetractionStatusType_3;


typedef uint8 u8RetractionStatusType_4;


typedef uint8 u8RetractionStatusType_5;


typedef uint8 u8RetractionStatusType_6;


typedef uint8 u8SeverityLevelType_1;


typedef uint8 u8SeverityLevelType_2;


typedef uint8 u8SeverityLevelType_3;


typedef uint8 u8SeverityLevelType_4;


typedef uint8 u8SeverityLevelType_5;


typedef uint8 u8SeverityLevelType_6;


typedef uint8 u8StepNumberType_1;


typedef uint8 u8StepNumberType_2;


typedef uint8 u8StepNumberType_3;


typedef uint8 u8StepNumberType_4;


typedef uint8 u8StepNumberType_5;


typedef uint8 u8StepNumberType_6;


typedef uint8 u8TestResultType_1;


typedef uint8 u8TestResultType_2;


typedef uint8 u8TestResultType_3;


typedef uint8 u8TestResultType_4;


typedef uint8 u8TestResultType_5;


typedef uint8 u8TestResultType_6;


typedef uint8 u8TriggeringSourceType_1;


typedef uint8 u8TriggeringSourceType_2;


typedef uint8 u8TriggeringSourceType_3;


typedef uint8 u8TriggeringSourceType_4;


typedef uint8 u8TriggeringSourceType_5;


typedef uint8 u8TriggeringSourceType_6;


typedef uint8 u8VelocityTargetType_1;


typedef uint8 u8VelocityTargetType_2;


typedef uint8 u8VelocityTargetType_3;


typedef uint8 u8VelocityTargetType_4;


typedef uint8 u8VelocityTargetType_5;


typedef uint8 u8VelocityTargetType_6;


typedef uint8 u8WdgTestResultType_1;


typedef uint8 u8WdgTestResultType_2;


typedef uint8 u8WdgTestResultType_3;


typedef uint8 u8WdgTestResultType_4;


typedef uint8 u8WdgTestResultType_5;


typedef uint8 u8WdgTestResultType_6;


typedef uint8 u8lBuckleSwitchStatusType_1;


typedef uint8 u8lBuckleSwitchStatusType_2;


typedef uint8 u8lBuckleSwitchStatusType_3;


typedef uint8 u8lBuckleSwitchStatusType_4;


typedef uint8 u8lBuckleSwitchStatusType_5;


typedef uint8 u8lBuckleSwitchStatusType_6;


typedef uint8 uint8_u8;


typedef c08_UInt_SNA_na ARR_08_UInt_noSNA_49[49];


typedef DC_U16 DC_U16_ARRAY_128[128];


typedef uint8_u8 DT_Ssa_Data7ByteType[7];


typedef uint8_u8 DT_U8N_3k[3000];


typedef c08_UInt_SNA_na Rte_DT_ARR_Dyn_08_UInt_noSNA_55_1[55];


typedef c08_UInt_SNA_na Rte_DT_ARR_Dyn_08_UInt_noSNA_800_1[800];


typedef struct
{
  uint8 SIZE;
  Rte_DT_ARR_Dyn_08_UInt_noSNA_55_1 ARRAY_ELEMENT;
} ARR_Dyn_08_UInt_noSNA_55;


typedef struct
{
  uint16 SIZE;
  Rte_DT_ARR_Dyn_08_UInt_noSNA_800_1 ARRAY_ELEMENT;
} ARR_Dyn_08_UInt_noSNA_800;


typedef struct
{
  DT_Uint32 COM_C04_Sig004;
  c16_CRC_woSNA_1 CRC_COM_C04_SGR01_P05;
  c08_0_255_1_SNA_na SQC_COM_C04_SGR01_P05;
} REC_COM_C04_SGR01_P05;


typedef struct
{
  DT_Uint32 COM_C04_Sig004;
  c16_CRC_woSNA_1 CRC_COM_C04_SGR01_P05;
  c08_0_255_1_SNA_na SQC_COM_C04_SGR01_P05;
} REC_COM_C04_SGR01_P05_a8oh4dpz9at39a7d7s3b6v4b3;


typedef struct
{
  c02_NotActv_Actv_SNA E_COM_C04_Sig110_0;
  c03_Off_On_Chng_Idle_ST3 E_COM_C04_Sig110_1;
} REC_COM_C04_Sig110;


typedef struct
{
  c02_NotActv_Actv_SNA E_COM_C04_Sig110_0;
  c03_Off_On_Chng_Idle_ST3 E_COM_C04_Sig110_1;
} REC_COM_C04_Sig110_71njeubj9ico1p8v4pmslfcno;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig111_0;
  c10_to_1022_1 E_COM_C04_Sig111_1;
  c11_0_2046_1 E_COM_C04_Sig111_3;
  c16_0_65533_1 E_COM_C04_Sig111_2;
} REC_COM_C04_Sig111;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig111_0;
  c10_to_1022_1 E_COM_C04_Sig111_1;
  c11_0_2046_1 E_COM_C04_Sig111_3;
  c16_0_65533_1 E_COM_C04_Sig111_2;
} REC_COM_C04_Sig111_euk2owpx15avykqntci714wbp;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig112_0;
  c10_to_1022_1 E_COM_C04_Sig112_1;
  c11_0_2046_1 E_COM_C04_Sig112_2;
  c16_0_65533_1 E_COM_C04_Sig112_3;
} REC_COM_C04_Sig112;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig112_0;
  c10_to_1022_1 E_COM_C04_Sig112_1;
  c11_0_2046_1 E_COM_C04_Sig112_2;
  c16_0_65533_1 E_COM_C04_Sig112_3;
} REC_COM_C04_Sig112_euk2owpx15avykqntci714wbp;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig113_0;
  c10_to_1022_1 E_COM_C04_Sig113_1;
  c11_0_2046_1 E_COM_C04_Sig113_2;
  c16_0_65533_1 E_COM_C04_Sig113_3;
} REC_COM_C04_Sig113;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig113_0;
  c10_to_1022_1 E_COM_C04_Sig113_1;
  c11_0_2046_1 E_COM_C04_Sig113_2;
  c16_0_65533_1 E_COM_C04_Sig113_3;
} REC_COM_C04_Sig113_euk2owpx15avykqntci714wbp;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig115_0;
  c10_to_1022_1 E_COM_C04_Sig115_1;
  c11_0_2046_1 E_COM_C04_Sig115_2;
  c16_0_65533_1 E_COM_C04_Sig115_3;
} REC_COM_C04_Sig115;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig115_0;
  c10_to_1022_1 E_COM_C04_Sig115_1;
  c11_0_2046_1 E_COM_C04_Sig115_2;
  c16_0_65533_1 E_COM_C04_Sig115_3;
} REC_COM_C04_Sig115_euk2owpx15avykqntci714wbp;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig117_0;
  c10_to_1022_1 E_COM_C04_Sig117_1;
  c11_0_2046_1 E_COM_C04_Sig117_2;
  c16_0_65533_1 E_COM_C04_Sig117_3;
} REC_COM_C04_Sig117;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig117_0;
  c10_to_1022_1 E_COM_C04_Sig117_1;
  c11_0_2046_1 E_COM_C04_Sig117_2;
  c16_0_65533_1 E_COM_C04_Sig117_3;
} REC_COM_C04_Sig117_euk2owpx15avykqntci714wbp;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig118_0;
  c10_to_1022_1 E_COM_C04_Sig118_1;
  c11_0_2046_1 E_COM_C04_Sig118_2;
  c16_0_65533_1 E_COM_C04_Sig118_3;
} REC_COM_C04_Sig118;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig118_0;
  c10_to_1022_1 E_COM_C04_Sig118_1;
  c11_0_2046_1 E_COM_C04_Sig118_2;
  c16_0_65533_1 E_COM_C04_Sig118_3;
} REC_COM_C04_Sig118_euk2owpx15avykqntci714wbp;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig119_0;
  c10_to_1022_1 E_COM_C04_Sig119_1;
  c11_0_2046_1 E_COM_C04_Sig119_2;
  c16_0_65533_1 E_COM_C04_Sig119_3;
} REC_COM_C04_Sig119;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig119_0;
  c10_to_1022_1 E_COM_C04_Sig119_1;
  c11_0_2046_1 E_COM_C04_Sig119_2;
  c16_0_65533_1 E_COM_C04_Sig119_3;
} REC_COM_C04_Sig119_euk2owpx15avykqntci714wbp;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig120_0;
  c10_to_1022_1 E_COM_C04_Sig120_1;
  c11_0_2046_1 E_COM_C04_Sig120_2;
  c16_0_65533_1 E_COM_C04_Sig120_3;
} REC_COM_C04_Sig120;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig120_0;
  c10_to_1022_1 E_COM_C04_Sig120_1;
  c11_0_2046_1 E_COM_C04_Sig120_2;
  c16_0_65533_1 E_COM_C04_Sig120_3;
} REC_COM_C04_Sig120_euk2owpx15avykqntci714wbp;


typedef struct
{
  c02_NotActv_Actv_SNA E_COM_C04_Sig110_0;
  c03_Off_On_Chng_Idle_ST3 E_COM_C04_Sig110_1;
} REC_COM_C0X_Sig110;


typedef struct
{
  c02_NotActv_Actv_SNA E_COM_C04_Sig110_0;
  c03_Off_On_Chng_Idle_ST3 E_COM_C04_Sig110_1;
} REC_COM_C0X_Sig110_71njeubj9ico1p8v4pmslfcno;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig114_0;
  c10_to_1022_1 E_COM_C04_Sig114_1;
  c11_0_2046_1 E_COM_C04_Sig114_3;
  c16_0_65533_1 E_COM_C04_Sig114_2;
} REC_E_COM_C04_Sig114_0;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig114_0;
  c10_to_1022_1 E_COM_C04_Sig114_1;
  c11_0_2046_1 E_COM_C04_Sig114_3;
  c16_0_65533_1 E_COM_C04_Sig114_2;
} REC_E_COM_C04_Sig114_0_euk2owpx15avykqntci714wbp;


typedef struct
{
  c08_0_254_1 Sequence_Counter;
  c08_0_254_1 Link_Drop_Counter;
  c16_0_65535_1_SNA_na Rx_Status;
  c16_0_65535_1_SNA_na Rx_Error_Counter;
  c16_0_65535_1_SNA_na CRC_Error_Counter;
  c16_0_65535_1_SNA_na Frame_Counter;
  c08_0_254_1 Temperature;
  c16_0_65535_1_SNA_na Port_Activation_Status;
  c16_0_65535_1_SNA_na PMA_PMD_Status;
  ARR_08_UInt_noSNA_49 Reserved;
} REC_Meas_Eth_ECU4_Base_Layer_Heartbeat;


typedef struct
{
  c16_CRC_woSNA CRC_PT4_PTCoor4_Pr5_ST3;
  c02_PT_Rdy_V2 PT4_PTCoor_PT_Rdy_ST3;
  c08_0_255_1_SNA_na SQC_PT4_PTCoor4_Pr5_ST3;
  c03_EngStartPN14_Stat PT4_PTCoor_EngStartPN14_Stat_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_SSA_EngSp_ST3;
  Rsrv01 Rsrv1_PT4_PTCoor_PT_Rdy_Pr5_ST3;
} REC_PT4_PTCoor4_Pr5_ST3_a1o7mhv0xy8ny0vccjf09ttgc;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig116_0;
  c10_to_1022_1 E_COM_C04_Sig116_1;
  c11_0_2046_1 E_COM_C04_Sig116_2;
  c16_0_65533_1 E_COM_C04_Sig116_3;
} REC_REC_COM_C04_Sig116;


typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig116_0;
  c10_to_1022_1 E_COM_C04_Sig116_1;
  c11_0_2046_1 E_COM_C04_Sig116_2;
  c16_0_65533_1 E_COM_C04_Sig116_3;
} REC_REC_COM_C04_Sig116_euk2owpx15avykqntci714wbp;


typedef struct
{
  c08_km_p_h_0_254_1 VehSpd8_ST3;
  c16_CRC_woSNA CRC_VehSpd8_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_VehSpd8_Pr5_ST3;
} REC_VehSpd8_Pr5_ST3;


typedef struct
{
  SwcDiag_IgnitionStatusType ISw_Stat_ST3;
} SwcDiag_BusIgnitionStatusRecordType;


typedef struct
{
  SwcDiag_BusOdometerType Odo_ST3;
} SwcDiag_OdometerRecordType;


typedef struct
{
  SwcDiag_RoELitePDUKindType ROE_0;
  uint8 ROE_1;
  uint8 ROE_2;
  uint8 ROE_3;
  uint8 ROE_4;
  uint8 ROE_5;
  uint8 ROE_6;
  uint8 ROE_7;
} SwcDiag_RoERecordType;


typedef struct
{
  SwcDiag_VehicleStartupType PT4_PTCoor_EngStartPN14_Stat_ST3;
} SwcDiag_VehicleStartupRecordType;


typedef struct
{
  UInt32_1 u32SystemTimeInSec;
  UInt8_1 u8SystemTimeOffset;
} stAbsoluteSystemTimeType_1;


typedef struct
{
  UInt32_2 u32SystemTimeInSec;
  UInt8_2 u8SystemTimeOffset;
} stAbsoluteSystemTimeType_2;


typedef struct
{
  UInt32_3 u32SystemTimeInSec;
  UInt8_3 u8SystemTimeOffset;
} stAbsoluteSystemTimeType_3;


typedef struct
{
  UInt32_4 u32SystemTimeInSec;
  UInt8_4 u8SystemTimeOffset;
} stAbsoluteSystemTimeType_4;


typedef struct
{
  UInt32_5 u32SystemTimeInSec;
  UInt8_5 u8SystemTimeOffset;
} stAbsoluteSystemTimeType_5;


typedef struct
{
  UInt32_6 u32SystemTimeInSec;
  UInt8_6 u8SystemTimeOffset;
} stAbsoluteSystemTimeType_6;


typedef REC_Meas_Eth_ECU4_Base_Layer_Heartbeat REC_ARR_16_Meas_Eth_ECU_4_Heartbeat[16];
# 4955 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_Type.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 4956 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_Type.h" 2

extern const ARR_08_UInt_noSNA_7 Rte_XDIS_6146w3b2vgdunnu49c413rpbf;

extern const Coding_VINDataType Rte_Ssa_Init_VIN;

extern const KeyM_SharedSecretType Rte_Ssa_Init_Zero_32Byte;

extern const RightsM_AuthenticationBroadcastType Rte_Ssa_Init_Zero_20Byte;

extern const Ssa_Data12ByteType Rte_Ssa_Init_Zero_12Byte;

extern const Ssa_Data5ByteType Rte_Ssa_Init_Zero_5Byte;

extern const Ssa_Data6ByteType Rte_Ssa_Init_Zero_6Byte;

extern const Ssa_Data7ByteType Rte_Ssa_Init_Zero_7Byte;

extern const Ssa_Data8ByteType Rte_Ssa_Init_ComSignal_8Byte;

extern const MeasurementFrame Rte_C_MeasurementFrame_0;

extern const REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx Rte_XDIS_38xd6mxe7w4h211xfx307v7jd;

extern const REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx Rte_XDIS_5tgkwvedu4465t8unm4y2yblo;

extern const REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh Rte_XDIS_6b75pabydagdo3iwsn1mn0uh1;

extern const REC_DPC_Md_Rq_ESP_Pr5_ST3_18cj3r9lb95cc7w4q3mwqkn86 Rte_XDIS_2akyi0yafm6v4b7rnlmtzqky2;

extern const REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby Rte_XDIS_69fckmg12bk5g7417pzn53395;

extern const REC_Ign_Stat_Pr5_ST3 Rte_Const_Ign_Stat_InitVal;

extern const REC_Ign_Stat_Pr5_ST3_b0ko81o0x5jgvwtduf99gvzi0 Rte_XDIS_cfagkw6zyn9r952v5onwpwdur;

extern const REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96 Rte_XDIS_9fnatjo7ibmc7ug14uhxholnb;

extern const REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh Rte_XDIS_6l5b88fcuqpu2imoz1fzls07a;

extern const REC_ORC_Impact3_Pr5_ST3_b4auermbjwizt3ufwg8j8br58 Rte_XDIS_ayiqyrhz0dpk9ygbqo5e5w1f7;

extern const REC_PT4_PTCoor4_Pr5_ST3_6v3sj55wsjghho72slblc9pby Rte_XDIS_9yh6bo4rxot1fkk0920219751;

extern const REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh Rte_XDIS_1j2e7ey8q28fsybvpbxfqeop8;

extern const REC_PT4_PTCoor9_Pr5_ST3_cl82h0erzy2xfmj19jwk97p4u Rte_XDIS_86xn4hwzmz58ui3sqboz24rhd;

extern const REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh Rte_XDIS_bjxptj1w89so7fpxm4dpms8ww;

extern const REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j Rte_XDIS_dw79s45ha1z03s9jiw4xye2p4;

extern const REC_PresfAct_Adj_Pr5_ST3_1fn392wedbq10w68dtk77u1sr Rte_XDIS_klz6op2k9wci74l4e72gktkb;

extern const REC_VehSpd8_Pr5_ST3_4y11fh5xzvk3axiqy3atn5wk4 Rte_XDIS_dj45cy8ua216iwtra2tj416zq;

extern const SecOC_VerificationStatusType Rte_C_SecOC_VerificationStatusType_0;

extern const SecOC_VerificationStatusType Rte_Ssa_Init_SecOcVerificationState;

extern const Ssa_IgnitionStatusType Rte_Ssa_Init_IgnitionStatus;

extern const Ssa_LocalTickCountAndSyncStatusType Rte_Ssa_Init_LocalTickCountAndSyncStatus;

extern const Ssa_OdometerRecordType Rte_Ssa_Init_BusOdometerRecord;
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5023 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_Type.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_DataHandleType.h" 1
# 35 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_DataHandleType.h"
typedef struct
{
  u8CycleNumberType value;
} Rte_DE_u8CycleNumberType;
# 5024 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_Type.h" 2
# 5143 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_Type.h"
typedef unsigned int Rte_BitType;
# 5158 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_Type.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5159 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_Type.h" 2

extern volatile uint8 Rte_InitState;
extern volatile uint8 Rte_StartTiming_InitState;
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5165 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_Type.h" 2
# 34 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement_Type.h" 2
# 2777 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement_Type.h"
typedef impl_BswM_RoEMode Rte_ModeType_BswM_RoEMode;
# 2794 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement_Type.h"
}
# 46 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h" 2
# 54 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 55 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h" 2

extern b8IsCarCrankingActiveType Rte_CIL_psrCustomerSpecific_b8IsCarCrankingActive;
extern u8CycleNumberType Rte_BFE_psrExecutedCycle_u8CycleNumber;
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 61 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h" 2
# 86 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 87 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h" 2

extern u8TestResultType Rte_Irv_MMG_u8CheckHWSelfProtectionResult;
extern u8TestResultType Rte_Irv_MMG_u8CheckMotorCurrentResult;
extern u8TestResultType Rte_Irv_MMG_u8CheckMotorThermalProctectionResult;
extern u8TestResultType Rte_Irv_MMG_u8CheckPowerSupplyOVResult;
extern u8TestResultType Rte_Irv_MMG_u8CheckPowerSupplyUVResult;
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 96 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h" 2
# 114 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 115 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h" 2
void PAL_Autotest_CheckHWSelfProtection( u8TestResultType * pu8TestResult);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 118 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 122 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h" 2
void PAL_Autotest_CheckMotorCurrent( u8TestResultType * pu8TestResult);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 125 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 129 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h" 2
void PAL_Autotest_CheckMotorThermalProctection( u8TestResultType * pu8TestResult);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 132 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 136 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h" 2
void PMP_Autotest_CheckPowerSupplyOV( u8TestResultType * pu8TestResult);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 139 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 143 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h" 2
void PMP_Autotest_CheckPowerSupplyUV( u8TestResultType * pu8TestResult);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 146 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h" 2
# 250 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 1
# 70 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 71 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 2
# 251 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h" 2
# 267 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h"
void MMG_Init(void);
void MMG_runAutotestCall100ms(void);
void MMG_runAutotestCall10ms(void);
void MMG_runCheckModeStatus(u32ModeMaskType u32ModesToCheck, u8ModeStatusType * bModeStatus);
void MMG_runGetTestResult(u8AutoTestIdType u8AutotestId, u8TestResultType * pu8TestResult);
void MMG_runMainFunction(void);
void MMG_runManageModeDelays(void);
void MMG_runUpdateModeStatus(void);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 1
# 147 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 148 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 2
# 278 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h" 2
# 289 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MMG_AC_ModeManagement.h"
}
# 34 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c" 2
# 1 "S:/COMPON~1/APPLIC~1/Autoliv/TL_Lib/IMPLEM~1/inc/common.h" 1
# 35 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c" 2
# 1 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/inc/MMG_Private.h" 1
# 26 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/inc/MMG_Private.h"
# 1 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/Nvp_Generated.h" 1
# 25 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/Nvp_Generated.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Platform_Types.h" 1
# 26 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/Nvp_Generated.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/Compiler.h" 1
# 27 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/Nvp_Generated.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/Nvp_MemoryMapping.h" 1
# 29 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/Nvp_Generated.h" 2
# 55 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/Nvp_Generated.h"
typedef struct {
const uint32 NVP_u32LowForceEOLThrs;
const uint32 NVP_u32ComfortForceEOLThrs;
const uint32 NVP_u32HighForceEOLThrs;
const uint32 NVP_u32HapticWarningEOLThrs;
const uint32 NVP_u32P2PEOLThrs;
const uint32 NVP_u32EOLComfortCyclesMAP;
const uint32 NVP_u32EOLHapticCyclesMAP;
const uint32 NVP_u32EOLPreCrashCyclesMAP;
const uint32 NVP_u32EOLBoostCyclesMAP;
const uint32 NVP_u32EOLP2PCyclesMAP;
}CALIB_BLOCK_ID_EOL_PARAM_StorageType;

typedef struct {
const uint8 NVP_au8BeltFctPriorities[38];
}CALIB_BLOCK_ID_BFS_PRIO_PARAM_StorageType;

typedef struct {
const uint8 NVP_u8PIDsupplyP;
const uint8 NVP_u8PIDsupplyI;
const uint8 NVP_u8PIDsupplyD;
const uint8 NVP_u8PIDmotorP;
const uint8 NVP_u8PIDmotorI;
const uint8 NVP_u8PIDmotorD;
}CALIB_BLOCK_ID_PID_PARAM_StorageType;

typedef struct {
const uint16 NVP_au16WeightTempIdxRel[7];
const uint8 NVP_au8WeightFactorsRel[7];
}CALIB_BLOCK_ID_WEIGHT_REL_TABLE_StorageType;

typedef struct {
const uint16 NVP_au16WeightTempIdxTens0[7];
const uint8 NVP_au8WeightFactorsTens0[7];
}CALIB_BLOCK_ID_WEIGHT_TENS0_TABLE_StorageType;

typedef struct {
const uint16 NVP_au16WeightTempIdxTens1[7];
const uint8 NVP_au8WeightFactorsTens1[7];
}CALIB_BLOCK_ID_WEIGHT_TENS1_TABLE_StorageType;

typedef struct {
const uint16 NVP_au16WeightTempIdxTens2[7];
const uint8 NVP_au8WeightFactorsTens2[7];
}CALIB_BLOCK_ID_WEIGHT_TENS2_TABLE_StorageType;

typedef struct {
const uint16 NVP_au16WeightTempIdxTens3[7];
const uint8 NVP_au8WeightFactorsTens3[7];
}CALIB_BLOCK_ID_WEIGHT_TENS3_TABLE_StorageType;

typedef struct {
const uint16 NVP_au16AdaptCurrentLimitTempIdx[7];
const uint8 NVP_au8AdaptCurrentLimitFactors[7];
}CALIB_BLOCK_ID_INT_CURRENT_CORR_StorageType;

typedef struct {
const uint16 NVP_au16AdaptCurrentLimitValues[64];
}CALIB_BLOCK_ID_INT_CURRENT_TABLE_StorageType;

typedef struct {
const uint16 NVP_au16PowerDegradVoltIdx[6];
const uint8 NVP_au8PowerDegradFactors[6];
}CALIB_BLOCK_ID_POWER_DEGRADATION_StorageType;

typedef struct {
const uint16 NVP_au16AlphaMotorCurrent[3];
const uint8 NVP_au8AlphaFactors[3];
}CALIB_BLOCK_ID_ECPL_ALPHA_TABLE_StorageType;

typedef struct {
const uint16 NVP_au16BetaSupplyCurrent[3];
const uint8 NVP_au8BetaFactors[3];
}CALIB_BLOCK_ID_ECPL_BETA_TABLE_StorageType;

typedef struct {
const uint16 NVP_u16BrakingSequenceDuration;
const uint16 NVP_u16CplBobbinSpeedThrs;
const boolean NVP_b8CplDetectionByBMM;
const boolean NVP_b8CplDetectionByCAN;
const boolean NVP_b8IseCplActivated;
}CALIB_BLOCK_ID_ECPL_OTHER_PARAM_StorageType;

typedef struct {
const uint16 NVP_au16MotorCurrentAbortTempIdx[7];
const uint8 NVP_au8MotorCurrentAbortFactors[7];
}CALIB_BLOCK_ID_BPA_MOTOR_CURRENT_StorageType;

typedef struct {
const uint16 NVP_u16UnderKL30QualificationThrs;
const uint16 NVP_u16UnderKL30DeskillingThrs;
const uint16 NVP_u16UnderKL30bgQualificationThrs;
const uint16 NVP_u16UnderKL30bgDeskillingThrs;
const uint16 NVP_u16OverKL30QualificationThrs;
const uint16 NVP_u16OverKL30DeskillingThrs;
const uint16 NVP_u16OverKL30bgQualificationThrs;
const uint16 NVP_u16OverKL30bgDeskillingThrs;
const uint16 NVP_u16UnderKL30DuringTensQualificationThrs;
const uint16 NVP_u16UnderKL30DuringTensDeskillingThrs;
const uint16 NVP_u16KL30MaximumThr;
const uint16 NVP_u16KL30MinimumThr;
const uint16 NVP_u16ImplausibleKL30bgThrs;
const uint16 NVP_u16MinKL30ForVBoostAT;
}CALIB_BLOCK_ID_VOLT_THRS_StorageType;

typedef struct {
const uint16 NVP_ku16KL30LossDetectionThr;
const uint16 NVP_ku16KL30EndLossDetectionThr;
}CALIB_BLOCK_ID_BATTERY_LOSS_DETECTION_THRS_StorageType;

typedef struct {
const sint16 NVP_s16GainIntegerBoost;
const sint16 NVP_s16GainIntegerStandard;
}CALIB_BLOCK_ID_BOOST_StorageType;

typedef struct {
const uint16 NVP_u16EcuResistance;
const uint16 NVP_u16TemperatureDefaultValue;
const uint16 NVP_u16TemperatureFunctionalLowThrs;
const uint16 NVP_u16TemperatureFunctionalHighThrs;
const uint16 NVP_u16HWSelfProtectionCurrentThrs;
}CALIB_BLOCK_ID_ECU_PROPERTIES_StorageType;

typedef struct {
const uint32 NVP_au32DeficiencyThrs[5];
}CALIB_BLOCK_ID_SW_SELF_PROTECTION_THRS_StorageType;

typedef struct {
const uint16 NVP_au16MotorResistTempIndex[7];
const uint8 NVP_au8MotorResistReferences[7];
}CALIB_BLOCK_ID_MOTOR_RESIST_PARAM_StorageType;

typedef struct {
const uint8 NVP_u8BoostActivation;
}CALIB_BLOCK_ID_BOOST_ACTIVATION_StorageType;





typedef struct {
uint8 NVP_u8ECULocation;
}NVP_BLOCK_ID_ECU_LOCATION_StorageType;

typedef struct {
uint8 NVP_au8AssemblySerialNumber[28];
}NVP_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN_StorageType;

typedef struct {
uint16 NVP_au16CalibADCRel[5];
uint16 NVP_au16CalibADCTens[5];
uint16 NVP_au16CurrentProbeRel[5];
uint16 NVP_au16CurrentProbeTens[5];
}NVP_BLOCK_ID_HB_CALIBRATION_StorageType;

typedef struct {
uint8 NVP_au8AeeTraceabilityNumber[12];
}NVP_BLOCK_ID_AEE_TRACEABILITY_StorageType;

typedef struct {
uint32 NVP_au32ExecutedCycleCounters[5];
}NVP_BLOCK_ID_EXECUTION_COUNTERS_StorageType;

typedef struct {
uint32 NVP_u32CheckMotorOrderMediumMaxDuration;
uint32 NVP_u32MotorCurrentMediumMaxDuration;
uint32 NVP_u32SWThermalProtectionValidationThrs;
uint32 NVP_u32SWThermalProtectionDeskillingThrs;
uint16 NVP_u16MotorCurrentHighResetTime;
uint16 NVP_u16MotorCurrentMediumResetTime;
uint16 NVP_u16CheckMotorOrderHighMaxDuration;
uint16 NVP_u16MotorCurrentHighMaxDuration;
uint16 NVP_u16CheckMotorOrderHighResetTime;
uint16 NVP_u16CheckMotorOrderMediumResetTime;
uint16 NVP_u16CheckMotorOrderResetTime;
uint16 NVP_u16MotorCurrentResetTime;
uint8 NVP_u8MotorCurrentHighThrs;
uint8 NVP_u8MotorCurrentMediumThrs;
uint8 NVP_u8CheckMotorOrderHighThrs;
uint8 NVP_u8checkMotorOrderMediumThrs;
}NVP_BLOCK_ID_TESTS_PARAM_StorageType;

typedef struct {
uint8 NVP_au8BeltProfilesDefinitions[48];
}NVP_BLOCK_ID_CYCLE_0_StorageType;

typedef struct {
uint8 NVP_au8StepsDefinitions[160];
}NVP_BLOCK_ID_STEP_0_StorageType;




extern NVP_BLOCK_ID_ECU_LOCATION_StorageType NVP_BLOCK_ID_ECU_LOCATION_RamBlockData;
extern NVP_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN_StorageType NVP_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN_RamBlockData;
extern NVP_BLOCK_ID_HB_CALIBRATION_StorageType NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData;
extern NVP_BLOCK_ID_AEE_TRACEABILITY_StorageType NVP_BLOCK_ID_AEE_TRACEABILITY_RamBlockData;
extern NVP_BLOCK_ID_EXECUTION_COUNTERS_StorageType NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData;
extern NVP_BLOCK_ID_TESTS_PARAM_StorageType NVP_BLOCK_ID_TESTS_PARAM_RamBlockData;
extern NVP_BLOCK_ID_CYCLE_0_StorageType NVP_BLOCK_ID_CYCLE_0_RamBlockData;
extern NVP_BLOCK_ID_STEP_0_StorageType NVP_BLOCK_ID_STEP_0_RamBlockData;





extern const NVP_BLOCK_ID_ECU_LOCATION_StorageType NVP_BLOCK_ID_ECU_LOCATION_DefaultData;
extern const NVP_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN_StorageType NVP_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN_DefaultData;
extern const NVP_BLOCK_ID_HB_CALIBRATION_StorageType NVP_BLOCK_ID_HB_CALIBRATION_DefaultData;
extern const NVP_BLOCK_ID_AEE_TRACEABILITY_StorageType NVP_BLOCK_ID_AEE_TRACEABILITY_DefaultData;
extern const NVP_BLOCK_ID_EXECUTION_COUNTERS_StorageType NVP_BLOCK_ID_EXECUTION_COUNTERS_DefaultData;
extern const NVP_BLOCK_ID_TESTS_PARAM_StorageType NVP_BLOCK_ID_TESTS_PARAM_DefaultData;
extern const NVP_BLOCK_ID_CYCLE_0_StorageType NVP_BLOCK_ID_CYCLE_0_DefaultData;
extern const NVP_BLOCK_ID_STEP_0_StorageType NVP_BLOCK_ID_STEP_0_DefaultData;





extern const CALIB_BLOCK_ID_EOL_PARAM_StorageType CALIB_BLOCK_ID_EOL_PARAM_RomBlockData;
extern const CALIB_BLOCK_ID_BFS_PRIO_PARAM_StorageType CALIB_BLOCK_ID_BFS_PRIO_PARAM_RomBlockData;
extern const CALIB_BLOCK_ID_PID_PARAM_StorageType CALIB_BLOCK_ID_PID_PARAM_RomBlockData;
extern const CALIB_BLOCK_ID_WEIGHT_REL_TABLE_StorageType CALIB_BLOCK_ID_WEIGHT_REL_TABLE_RomBlockData;
extern const CALIB_BLOCK_ID_WEIGHT_TENS0_TABLE_StorageType CALIB_BLOCK_ID_WEIGHT_TENS0_TABLE_RomBlockData;
extern const CALIB_BLOCK_ID_WEIGHT_TENS1_TABLE_StorageType CALIB_BLOCK_ID_WEIGHT_TENS1_TABLE_RomBlockData;
extern const CALIB_BLOCK_ID_WEIGHT_TENS2_TABLE_StorageType CALIB_BLOCK_ID_WEIGHT_TENS2_TABLE_RomBlockData;
extern const CALIB_BLOCK_ID_WEIGHT_TENS3_TABLE_StorageType CALIB_BLOCK_ID_WEIGHT_TENS3_TABLE_RomBlockData;
extern const CALIB_BLOCK_ID_INT_CURRENT_CORR_StorageType CALIB_BLOCK_ID_INT_CURRENT_CORR_RomBlockData;
extern const CALIB_BLOCK_ID_INT_CURRENT_TABLE_StorageType CALIB_BLOCK_ID_INT_CURRENT_TABLE_RomBlockData;
extern const CALIB_BLOCK_ID_POWER_DEGRADATION_StorageType CALIB_BLOCK_ID_POWER_DEGRADATION_RomBlockData;
extern const CALIB_BLOCK_ID_ECPL_ALPHA_TABLE_StorageType CALIB_BLOCK_ID_ECPL_ALPHA_TABLE_RomBlockData;
extern const CALIB_BLOCK_ID_ECPL_BETA_TABLE_StorageType CALIB_BLOCK_ID_ECPL_BETA_TABLE_RomBlockData;
extern const CALIB_BLOCK_ID_ECPL_OTHER_PARAM_StorageType CALIB_BLOCK_ID_ECPL_OTHER_PARAM_RomBlockData;
extern const CALIB_BLOCK_ID_BPA_MOTOR_CURRENT_StorageType CALIB_BLOCK_ID_BPA_MOTOR_CURRENT_RomBlockData;
extern const CALIB_BLOCK_ID_VOLT_THRS_StorageType CALIB_BLOCK_ID_VOLT_THRS_RomBlockData;
extern const CALIB_BLOCK_ID_BATTERY_LOSS_DETECTION_THRS_StorageType CALIB_BLOCK_ID_BATTERY_LOSS_DETECTION_THRS_RomBlockData;
extern const CALIB_BLOCK_ID_BOOST_StorageType CALIB_BLOCK_ID_BOOST_RomBlockData;
extern const CALIB_BLOCK_ID_ECU_PROPERTIES_StorageType CALIB_BLOCK_ID_ECU_PROPERTIES_RomBlockData;
extern const CALIB_BLOCK_ID_SW_SELF_PROTECTION_THRS_StorageType CALIB_BLOCK_ID_SW_SELF_PROTECTION_THRS_RomBlockData;
extern const CALIB_BLOCK_ID_MOTOR_RESIST_PARAM_StorageType CALIB_BLOCK_ID_MOTOR_RESIST_PARAM_RomBlockData;
extern const CALIB_BLOCK_ID_BOOST_ACTIVATION_StorageType CALIB_BLOCK_ID_BOOST_ACTIVATION_RomBlockData;
# 27 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/inc/MMG_Private.h" 2
# 65 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/inc/MMG_Private.h"
typedef void (* tSystemContextCallbackFct) (void);

typedef struct
{
 tSystemContextCallbackFct pfModeCallback;
} MMG_stModeConfigurationType;







typedef struct
{
 uint16 u16DelayThrs;
 uint32 u32AssociatedMode;
} MMG_stModeDelayType;
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 1
# 90 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/inc/MMG_Private.h" 2
# 98 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/inc/MMG_Private.h"
extern uint32 MMG_u32ModesStatus;
extern uint32 MMG_u32ModesStatusComplement;

extern boolean MMG_bVoltageStatusIsOk;
extern boolean MMG_bInternalStatusIsOk;
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 1
# 106 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/inc/MMG_Private.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 1
# 109 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/inc/MMG_Private.h" 2







extern uint16 MMG_u16MaxDelayAfterCycleActivation;
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 1
# 120 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/inc/MMG_Private.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 1
# 115 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 116 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 2
# 123 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/inc/MMG_Private.h" 2






extern MMG_stModeDelayType MMG_astDelayAfterCycleThrsandModes[((uint8)2)];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 2
# 133 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/inc/MMG_Private.h" 2
# 142 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/inc/MMG_Private.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 1
# 70 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 71 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 2
# 143 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/inc/MMG_Private.h" 2


extern void mmg_ManageModeDelays_ExecutedCycle(void);


extern void mmg_UpdateModeStatus_CriticalAutotestsNok(void);
extern void mmg_UpdateModeStatus_PowerVoltageUnstable(void);
extern void mmg_UpdateModeStatus_ExecutedCycleDelay(void);
extern void mmg_UpdateModeStatus_ExecutedCycle(void);
extern void mmg_UpdateModeStatus_ExecutedTensioningCycle(void);
extern void mmg_UpdateModeStatus_Cranking(void);
extern void mmg_UpdateModeStatus_BusOff(void);
extern void mmg_UpdateModeStatus_NoHallEffectSensor(void);
extern void mmg_UpdateModeStatus_DefaultValues(void);
extern void mmg_UpdateModeStatus_InhibitionOfCyclesByInternalFailure_AllCycles(void);
extern void mmg_UpdateModeStatus_InhibitionOfCyclesByInternalFailure_TensioningCycles(void);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 1
# 147 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 148 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 2
# 162 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/inc/MMG_Private.h" 2
# 36 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h" 1
# 625 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Types.h" 1
# 52 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Types.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Cfg.h" 1
# 53 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Types.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Swc_Types.h" 1
# 64 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Swc_Types.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_DemMaster_0_Type.h" 1
# 29 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_DemMaster_0_Type.h"
extern "C"
{
# 1604 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_DemMaster_0_Type.h"
}
# 65 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Swc_Types.h" 2
# 58 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Types.h" 2
# 87 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Types.h"
typedef uint32 Dem_Com_ProcessorWordType;


typedef uint8 Dem_SatelliteInfoType;


typedef Dem_UdsStatusByteType Dem_EventStatusExtendedType;
# 120 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Types.h"
typedef uint8 Dem_DTCTranslationFormatType;
# 136 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Types.h"
typedef uint8 Dem_DTCRequestType;
# 171 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Types.h"
typedef uint8 Dem_J1939DcmSetClearFilterType;
# 190 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Types.h"
typedef struct Dem_J1939DcmLampStatusType_s
{
 uint8 LampStatus;
 uint8 FlashLampStatus;
} Dem_J1939DcmLampStatusType;







typedef uint8 Dem_J1939DcmSetFreezeFrameFilterType;
# 216 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Types.h"
typedef uint8 Dem_J1939DcmDTCStatusFilterType;
# 227 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Types.h"
typedef struct Dem_J1939DcmDiagnosticReadiness1Type_s
{
 uint8 ActiveTroubleCodes;
 uint8 PreviouslyActiveDiagnosticTroubleCodes;
 uint8 OBDCompliance;
 uint8 ContinuouslyMonitoredSystemsSupport_Status;
 uint16 NonContinuouslyMonitoredSystemsSupport;
 uint16 NonContinuouslyMonitoredSystemsStatus;
} Dem_J1939DcmDiagnosticReadiness1Type;


typedef struct Dem_J1939DcmDiagnosticReadiness2Type_s
{
 uint16 DistanceTraveledWhileMILisActivated;
 uint16 DistanceSinceDTCsCleared;
 uint16 MinutesRunbyEngineWhileMILisActivated;
 uint16 TimeSinceDiagnosticTroubleCodesCleared;
} Dem_J1939DcmDiagnosticReadiness2Type;


typedef struct Dem_J1939DcmDiagnosticReadiness3Type_s
{
 uint16 TimeSinceEngineStart;
 uint8 NumberofWarmupsSinceDTCsCleared;
 uint8 ContinuouslyMonitoredSystemsEnableCompletedStatus;
 uint16 NonContinuouslyMonitoredSystemsEnableStatus;
 uint16 NonContinuouslyMonitoredSystems;
} Dem_J1939DcmDiagnosticReadiness3Type;


typedef Std_ReturnType ( * Dem_ClearEventAllowedFPtrType)(
 boolean * ClearAllowed
 );


typedef Std_ReturnType ( * Dem_ClearDtcNotificationFPtrType)(
 uint32 DTC ,
 Dem_DTCFormatType DTCFormat ,
 Dem_DTCOriginType DTCOrigin
 );


typedef Std_ReturnType ( * Dem_GetFDCFPtrType)(
 sint8 * FaultDetectionCounter
 );


typedef void ( * Dem_GlobalTriggerOnMonitorStatusFPtrType)(
 Dem_EventIdType EventId
 );


typedef Std_ReturnType ( * Dem_EventStatusChangedFPtrType)(
 Dem_UdsStatusByteType EventStatusOld ,
 Dem_UdsStatusByteType EventStatusNew
 );


typedef Std_ReturnType ( * Dem_DtcStatusChangedFPtrType)(
 uint32 DTC ,
 Dem_DTCStatusMaskType DtcStatusOld ,
 Dem_DTCStatusMaskType DtcStatusNew
 );


typedef Std_ReturnType ( * Dem_EventDataChangedFPtrType)(
 void
 );


typedef Std_ReturnType ( * Dem_GlobalStatusChangedFPtrType)(
 Dem_EventIdType EventId ,
 Dem_UdsStatusByteType EventStatusOld ,
 Dem_UdsStatusByteType EventStatusNew
 );


typedef Std_ReturnType ( * Dem_GlobalDataChangedFPtrType)(
 Dem_EventIdType EventId
 );


typedef Std_ReturnType ( * Dem_InitMonitorForEventFPtrType)(
 Dem_InitMonitorReasonType InitReason
 );


typedef Std_ReturnType ( * Dem_InitMonitorForFuncFPtrType)(
 void
 );


typedef Std_ReturnType ( * Dem_ControlDtcSettingChangedFPtrType)(
 boolean Status
 );


typedef Std_ReturnType ( * Dem_ReadDataStandardFPtrType)(
 uint8 * DestinationBuffer
 );


typedef Std_ReturnType ( * Dem_ReadDataExtendedFPtrType)(
 Dem_EventIdType EventId ,
 uint8 * DestinationBuffer
 );


typedef Std_ReturnType ( * Dem_ReadDataSRBooleanFPtrType)(
 boolean * DataBuffer
 );


typedef Std_ReturnType ( * Dem_ReadDataSRSint8FPtrType)(
 sint8 * DataBuffer
 );


typedef Std_ReturnType ( * Dem_ReadDataSRSint16FPtrType)(
 sint16 * DataBuffer
 );


typedef Std_ReturnType ( * Dem_ReadDataSRUint16FPtrType)(
 uint16 * DataBuffer
 );


typedef Std_ReturnType ( * Dem_ReadDataSRSint32FPtrType)(
 sint32 * DataBuffer
 );


typedef Std_ReturnType ( * Dem_ReadDataSRUint32FPtrType)(
 uint32 * DataBuffer
 );


typedef Std_ReturnType ( * Dem_ReadDataFPtrType)(
 void
 );


typedef uint8 * Dem_DataPtrType;

typedef uint8 * Dem_NvDataPtrType;

typedef sint8 * Dem_SignedNvDataPtrType;

typedef uint8 * Dem_DcmDataPtrType;

typedef uint8 * Dem_SharedDataPtrType;


typedef const uint8 * Dem_ConstDataPtrType;

typedef const uint8 * Dem_ConstSharedDataPtrType;
# 626 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 1
# 69 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_SatelliteData_Types.h" 1
# 41 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_SatelliteData_Types.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Int.h" 1
# 46 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Int.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/SchM_Dem.h" 1
# 27 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/SchM_Dem.h"
extern "C" {
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/SchM_Dem_Type.h" 1
# 27 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/SchM_Dem_Type.h"
extern "C" {





}
# 31 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/SchM_Dem.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h" 1
# 441 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/OsInt.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/Os/OsInt.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 1
# 54 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Cfg.h" 1
# 57 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Cfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Hal_Cfg.h" 1
# 58 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Cfg.h" 2
# 55 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Types.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Types.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Types_Lcfg.h" 1
# 148 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Types_Lcfg.h"
typedef uint32 Os_AppAccessMaskType;


typedef enum
{
 OsApplication_Trusted_Core0 = 0,
 SystemApplication_OsCore0 = 1,
 OS_APPID_COUNT = 2,
 INVALID_OSAPPLICATION = OS_APPID_COUNT
} ApplicationType;


typedef enum
{
 OS_TRUSTEDFUNCTIONID_COUNT = 0
} TrustedFunctionIndexType;


typedef enum
{
 OS_NONTRUSTEDFUNCTIONID_COUNT = 0
} Os_NonTrustedFunctionIndexType;


typedef enum
{
 OS_FASTTRUSTEDFUNCTIONID_COUNT = 0
} Os_FastTrustedFunctionIndexType;


typedef enum
{
 ApplBackgroundTask_Core0 = 0,
 ApplInitTask_Core0 = 1,
 ApplTask_Core0_HighPrio = 2,
 ApplTask_Core0_LowPrio = 3,
 BackgroundTask_Core0 = 4,
 BswTask_Core0_HighPrio = 5,
 BswTask_Core0_LowPrio = 6,
 Default_Init_Task = 7,
 Default_Init_Task_Trusted = 8,
 IdleTask_OsCore0 = 9,
 OsTask_ALV_BeltFunctionAlgo = 10,
 OS_TASKID_COUNT = 11,
 INVALID_TASK = OS_TASKID_COUNT
} TaskType;


typedef enum
{
 CanIsr_1 = 0,
 CounterIsr_SystemTimer = 1,
 vHsmResponseIsr = 2,
 OS_ISRID_COUNT = 3,
 INVALID_ISR = OS_ISRID_COUNT
} ISRType;


typedef enum
{
 Rte_Al_TE2_BswTask_Core0_HighPrio_0_10ms = 0,
 Rte_Al_TE2_BswTask_Core0_HighPrio_0_3ms = 1,
 Rte_Al_TE2_BswTask_Core0_HighPrio_0_5ms = 2,
 Rte_Al_TE2_BswTask_Core0_LowPrio_0_10ms = 3,
 Rte_Al_TE2_BswTask_Core0_LowPrio_0_5ms = 4,
 Rte_Al_TE_AdcIf_AdcIf_MainFunction = 5,
 Rte_Al_TE_ApplTask_Core0_LowPrio_0_1000ms = 6,
 Rte_Al_TE_ApplTask_Core0_LowPrio_0_100ms = 7,
 Rte_Al_TE_ApplTask_Core0_LowPrio_0_10ms = 8,
 Rte_Al_TE_ApplTask_Core0_LowPrio_0_1ms = 9,
 Rte_Al_TE_ApplTask_Core0_LowPrio_0_250ms = 10,
 Rte_Al_TE_BFE_BFE_runExecuteStandardSteps = 11,
 Rte_Al_TE_BaseFunction_BaseFunction_Main = 12,
 Rte_Al_TE_OsTask_ALV_BeltFunctionAlgo_0_10ms = 13,
 Rte_Al_TE_PAL_AC_PowerAbstractionLayer_PAL_runMainFunction = 14,
 Rte_Al_TE_SBC_SBC_MainFunction = 15,
 OS_ALARMID_COUNT = 16
} AlarmType;


typedef enum
{
 SystemTimer = 0,
 OS_COUNTERID_COUNT = 1
} CounterType;


typedef enum
{
 OS_SCHTID_COUNT = 0
} ScheduleTableType;


typedef enum
{
 OsResource_EcuM = 0,
 OS_RESOURCEID_COUNT = 1
} ResourceType;


typedef enum
{
 OS_SPINLOCKID_COUNT = 0,
 INVALID_SPINLOCK = OS_SPINLOCKID_COUNT
} SpinlockIdType;


typedef enum
{
 OS_PERIPHERALID_COUNT = 0
} Os_PeripheralIdType;


typedef enum
{
 OS_BARRIERID_COUNT = 0
} Os_BarrierIdType;


typedef enum
{
 Os_TraceId_ApplBackgroundTask_Core0 = 0,
 Os_TraceId_ApplInitTask_Core0 = 1,
 Os_TraceId_ApplTask_Core0_HighPrio = 2,
 Os_TraceId_ApplTask_Core0_LowPrio = 3,
 Os_TraceId_BackgroundTask_Core0 = 4,
 Os_TraceId_BswTask_Core0_HighPrio = 5,
 Os_TraceId_BswTask_Core0_LowPrio = 6,
 Os_TraceId_Default_Init_Task = 7,
 Os_TraceId_Default_Init_Task_Trusted = 8,
 Os_TraceId_IdleTask_OsCore0 = 9,
 Os_TraceId_OsTask_ALV_BeltFunctionAlgo = 10,
 Os_TraceId_CanIsr_1 = 11,
 Os_TraceId_CounterIsr_SystemTimer = 12,
 Os_TraceId_vHsmResponseIsr = 13,
 Os_TraceId_OsCore0_Hooks = 14,
 OS_TRACE_THREADID_COUNT = 15,
 OS_TRACE_INVALID_THREAD = OS_TRACE_THREADID_COUNT + 1
} Os_TraceThreadIdType;


typedef enum
{
 OS_TRACE_NUMBER_OF_CONFIGURED_SPINLOCKS = OS_SPINLOCKID_COUNT,
 OS_TRACE_NUMBER_OF_ALL_SPINLOCKS = OS_SPINLOCKID_COUNT + 0u,
 OS_TRACE_INVALID_SPINLOCK = OS_TRACE_NUMBER_OF_ALL_SPINLOCKS + 1
} Os_TraceSpinlockIdType;
# 40 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Types.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Hal_Os_Types.h" 1
# 61 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Hal_Os_Types.h"
typedef uint32 Os_Hal_AddressType;



struct Os_ExceptionContextType_Tag;
typedef struct Os_ExceptionContextType_Tag Os_ExceptionContextType;
# 44 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Types.h" 2
# 204 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Types.h"
typedef void * TrustedFunctionParameterRefType;


typedef void * Os_NonTrustedFunctionParameterRefType;


typedef void * Os_FastTrustedFunctionParameterRefType;





typedef uint8 AppModeType;
# 230 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Types.h"
typedef enum
{
 IDLE_NO_HALT = 0,
 OS_IDLEMODE_COUNT = 1
} IdleModeType;



typedef uint32 Os_InterruptSourceIdType;



typedef Os_InterruptSourceIdType * Os_InterruptSourceIdRefType;



typedef uint32 Os_ExceptionSourceIdType;



typedef Os_ExceptionSourceIdType * Os_ExceptionSourceIdRefType;



typedef Os_ExceptionContextType * Os_ExceptionContextRefType;
# 266 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Types.h"
typedef enum
{
 TRYTOGETSPINLOCK_SUCCESS,
 TRYTOGETSPINLOCK_NOSUCCESS
}TryToGetSpinlockType;
# 280 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Types.h"
typedef TaskType * TaskRefType;
# 289 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Types.h"
typedef enum
{


 RUNNING,


 READY,


 WAITING,


 SUSPENDED
} TaskStateType;


typedef TaskStateType * TaskStateRefType;



typedef uint64 EventMaskType;


typedef EventMaskType * EventMaskRefType;
# 325 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Types.h"
typedef uint32 PhysicalTimeType;


typedef uint32 Os_TickType;


typedef sint32 Os_TickDiffType;


typedef Os_TickType TickType;



typedef TickType * TickRefType;
# 348 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Types.h"
typedef struct
{

 TickType maxallowedvalue;

 TickType ticksperbase;

 TickType mincycle;
}AlarmBaseType;


typedef AlarmBaseType * AlarmBaseRefType;



typedef enum
{
 NO_ACCESS,
 ACCESS
} ObjectAccessType;




typedef enum
{
 RESTART,
 NO_RESTART,
 OS_RESTARTTYPE_COUNT
} RestartType;






typedef enum
{
 APPLICATION_TERMINATED = 0,
 APPLICATION_RESTARTING,
 APPLICATION_ACCESSIBLE
} ApplicationStateType;




typedef enum
{
 OBJECT_TASK,
 OBJECT_ISR,
 OBJECT_ALARM,
 OBJECT_RESOURCE,
 OBJECT_COUNTER,
 OBJECT_SCHEDULETABLE,
 OBJECT_SPINLOCK
} ObjectTypeType;



typedef uint32 Os_ObjectIdType;
# 419 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Types.h"
typedef ApplicationStateType * ApplicationStateRefType;
# 433 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Types.h"
typedef enum
{

 OSServiceId_GetApplicationID = 0x00u,
 OSServiceId_GetISRID = 0x01u,
 OSServiceId_CallTrustedFunction = 0x02u,
 OSServiceId_CheckISRMemoryAccess = 0x03u,
 OSServiceId_CheckTaskMemoryAccess = 0x04u,
 OSServiceId_CheckObjectAccess = 0x05u,
 OSServiceId_CheckObjectOwnership = 0x06u,
 OSServiceId_StartScheduleTableRel = 0x07u,
 OSServiceId_StartScheduleTableAbs = 0x08u,
 OSServiceId_StopScheduleTable = 0x09u,
 OSServiceId_NextScheduleTable = 0x0au,
 OSServiceId_StartScheduleTableSynchron = 0x0bu,
 OSServiceId_SyncScheduleTable = 0x0cu,
 OSServiceId_SetScheduleTableAsync = 0x0du,
 OSServiceId_GetScheduleTableStatus = 0x0eu,
 OSServiceId_IncrementCounter = 0x0fu,
 OSServiceId_GetCounterValue = 0x10u,
 OSServiceId_GetElapsedValue = 0x11u,
 OSServiceId_TerminateApplication = 0x12u,
 OSServiceId_AllowAccess = 0x13u,
 OSServiceId_GetApplicationState = 0x14u,
 OSServiceId_GetNumberOfActivatedCores = 0x15u,
 OSServiceId_GetCoreID = 0x16u,
 OSServiceId_StartCore = 0x17u,
 OSServiceId_StartNonAutosarCore = 0x18u,
 OSServiceId_GetSpinlock = 0x19u,
 OSServiceId_ReleaseSpinlock = 0x1au,
 OSServiceId_TryToGetSpinlock = 0x1bu,
 OSServiceId_ShutdownAllCores = 0x1cu,
 OSServiceId_ControlIdle = 0x1du,
 OSServiceId_IocSend = 0x1eu,
 OSServiceId_IocWrite = 0x1fu,
 OSServiceId_IocSendGroup = 0x20u,
 OSServiceId_IocWriteGroup = 0x21u,
 OSServiceId_IocReceive = 0x22u,
 OSServiceId_IocRead = 0x23u,
 OSServiceId_IocReceiveGroup = 0x24u,
 OSServiceId_IocReadGroup = 0x25u,
 OSServiceId_IocEmptyQueue = 0x26u,
 OSServiceId_GetCurrentApplicationID = 0x27u,


 OSServiceId_GetExceptionContext = 0xA0u,
 OSServiceId_SetExceptionContext = 0xA1u,
 OSServiceId_CallNonTrustedFunction = 0xA2u,
 OSServiceId_AppKill = 0xA3u,
 OSServiceId_AlarmActionSetEvent = 0xA4u,
 OSServiceId_AlarmActionActivateTask = 0xA5u,
 OSServiceId_AlarmActionIncrementCounter = 0xA6u,
 OSServiceId_AlarmActionCallback = 0xA7u,
 OSServiceId_TimerIsr = 0xA8u,
 OSServiceId_IsrWrapper = 0xA9u,
 OSServiceId_GetTaskStackUsage = 0xAAu,
 OSServiceId_GetISRStackUsage = 0xABu,
 OSServiceId_GetKernelStackUsage = 0xACu,
 OSServiceId_GetStartupHookStackUsage = 0xADu,
 OSServiceId_GetErrorHookStackUsage = 0xAEu,
 OSServiceId_GetShutdownHookStackUsage = 0xAFu,
 OSServiceId_GetProtectionHookStackUsage = 0xB0u,
 OSServiceId_GetSemaphore = 0xB1u,
 OSServiceId_ReleaseSemaphore = 0xB2u,
 OSServiceId_ScheduleTableActivateTask = 0xB3u,
 OSServiceId_ScheduleTableSetEvent = 0xB4u,
 OSServiceId_DisableInterruptSource = 0xB5u,
 OSServiceId_EnableInterruptSource = 0xB6u,
 OSServiceId_ClearPendingInterrupt = 0xB7u,
 OSServiceId_GetUnhandledIrq = 0xB8u,
 OSServiceId_GetUnhandledExc = 0xB9u,
 OSServiceId_HookCallCallback = 0xBAu,
 OSServiceId_IsInterruptSourceEnabled = 0xBBu,
 OSServiceId_IsInterruptPending = 0xBCu,
 OSServiceId_CallFastTrustedFunction = 0xBDu,
 OSServiceId_BarrierSynchronize = 0xBEu,
 OSServiceId_InitialEnableInterruptSources=0xBFu,
 OSServiceId_GetCoreStartState = 0xC0u,
 OSServiceId_GetNonTrustedFunctionStackUsage = 0xC1u,


 OSServiceId_StartOS = 0xD0u,
 OSServiceId_GetActiveApplicationMode = 0xD2u,
 OSServiceId_DisableAllInterrupts = 0xD3u,
 OSServiceId_EnableAllInterrupts = 0xD4u,
 OSServiceId_SuspendAllInterrupts = 0xD5u,
 OSServiceId_ResumeAllInterrupts = 0xD6u,
 OSServiceId_SuspendOSInterrupts = 0xD7u,
 OSServiceId_ResumeOSInterrupts = 0xD8u,
 OSServiceId_ActivateTask = 0xD9u,
 OSServiceId_TerminateTask = 0xDAu,
 OSServiceId_ChainTask = 0xDBu,
 OSServiceId_GetTaskID = 0xDCu,
 OSServiceId_GetTaskState = 0xDDu,
 OSServiceId_Schedule = 0xDEu,
 OSServiceId_SetEvent = 0xDFu,
 OSServiceId_ClearEvent = 0xE0u,
 OSServiceId_GetEvent = 0xE1u,
 OSServiceId_WaitEvent = 0xE2u,
 OSServiceId_GetAlarmBase = 0xE3u,
 OSServiceId_GetAlarm = 0xE4u,
 OSServiceId_SetRelAlarm = 0xE5u,
 OSServiceId_SetAbsAlarm = 0xE6u,
 OSServiceId_CancelAlarm = 0xE7u,
 OSServiceId_GetResource = 0xE8u,
 OSServiceId_ReleaseResource = 0xE9u,

 OSSERVICEID_COUNT = 0xFF
} OSServiceIdType;
# 557 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Types.h"
typedef enum
{


 OS_STATUS_OK = 0u,

 OS_STATUS_CALLEVEL = ((StatusType)0x02),

 OS_STATUS_LIMIT = ((StatusType)0x04),

 OS_STATUS_RESOURCE = ((StatusType)0x06),



 OS_STATUS_SERVICEID = ((StatusType)0x09),




 OS_STATUS_ILLEGAL_ADDRESS = ((StatusType)0x0A),

 OS_STATUS_MISSINGEND = ((StatusType)0x0B),

 OS_STATUS_DISABLEDINT = ((StatusType)0x0C),

 OS_STATUS_STACKFAULT = ((StatusType)0x0D),

 OS_STATUS_PROTECTION_MEMORY = ((StatusType)0x0E),

 OS_STATUS_PROTECTION_TIME = ((StatusType)0x0F),

 OS_STATUS_PROTECTION_ARRIVAL = ((StatusType)0x10),

 OS_STATUS_PROTECTION_LOCKED = ((StatusType)0x11),

 OS_STATUS_PROTECTION_EXCEPTION = ((StatusType)0x12),

 OS_STATUS_INTERFERENCE_DEADLOCK = ((StatusType)0x13),

 OS_STATUS_NESTING_DEADLOCK = ((StatusType)0x14),

 OS_STATUS_SPINLOCK = ((StatusType)0x15),

 OS_STATUS_CORE = ((StatusType)0x16),





 OS_STATUS_KILL_KERNEL_OBJ = ((StatusType)0xF6),

 OS_STATUS_NO_RESTARTTASK = ((StatusType)0xF7),

 OS_STATUS_PROTECTION_IRQ = ((StatusType)0xFB),

 OS_STATUS_PROTECTION_SYSCALL = ((StatusType)0xFA),

 OS_STATUS_API_ERROR = ((StatusType)0xFC),

 OS_STATUS_ASSERTION = ((StatusType)0xFD),

 OS_STATUS_OVERLOAD = ((StatusType)0xFE),

 OS_STATUS_CALL_NOT_ALLOWED = ((StatusType)0xF8),

 OS_STATUS_FUNCTION_UNAVAILABLE = ((StatusType)0xF9),

 OS_STATUS_OVERFLOW = ((StatusType)0xF5),


 OS_STATUS_CALLEVEL_SHARED_STACK = (((uint32) (((uint32)(1u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x02)))),

 OS_STATUS_CALLEVEL_CROSS_CORE_SYNC = (((uint32) (((uint32)(2u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x02)))),

 OS_STATUS_ACCESSRIGHTS_1 = (((uint32) (((uint32)(1u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x01)))),

 OS_STATUS_ACCESSRIGHTS_2 = (((uint32) (((uint32)(2u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x01)))),

 OS_STATUS_NOTACCESSIBLE_1 = (((uint32) (((uint32)(3u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x01)))),

 OS_STATUS_NOTACCESSIBLE_2 = (((uint32) (((uint32)(4u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x01)))),

 OS_STATUS_NOEXTENDEDTASK_1 = (((uint32) (((uint32)(5u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x01)))),

 OS_STATUS_NOEXTENDEDTASK_2 = (((uint32) (((uint32)(6u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x01)))),

 OS_STATUS_NOEXTENDEDTASK_CALLER = (((uint32) (((uint32)(7u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x01)))),

 OS_STATUS_LOCKED = (((uint32) (((uint32)(8u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x01)))),

 OS_STATUS_PRIORITY = (((uint32) (((uint32)(9u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x01)))),

 OS_STATUS_NOT_THE_OWNER_1 = (((uint32) (((uint32)(10u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x01)))),

 OS_STATUS_ID_1 = (((uint32) (((uint32)(1u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x03)))),

 OS_STATUS_ID_2 = (((uint32) (((uint32)(2u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x03)))),

 OS_STATUS_ID_TYPE_1 = (((uint32) (((uint32)(3u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x03)))),

 OS_STATUS_ID_DIFFERENT_COUNTER = (((uint32) (((uint32)(4u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x03)))),

 OS_STATUS_ID_DIFFERENT_SYNC = (((uint32) (((uint32)(5u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x03)))),

 OS_STATUS_HOOK_NOT_AVAILABLE = (((uint32) (((uint32)(6u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x03)))),

 OS_STATUS_UNLOCKED = (((uint32) (((uint32)(1u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x05)))),

 OS_STATUS_NOFUNC_1 = (((uint32) (((uint32)(2u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x05)))),

 OS_STATUS_NOFUNC_2 = (((uint32) (((uint32)(3u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x05)))),

 OS_STATUS_SPINLOCK_ORDER = (((uint32) (((uint32)(4u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x05)))),

 OS_STATUS_STOPPED_1 = (((uint32) (((uint32)(5u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x05)))),

 OS_STATUS_NOT_STOPPED_2 = (((uint32) (((uint32)(6u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x05)))),

 OS_STATUS_NEXTED_1 = (((uint32) (((uint32)(7u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x05)))),

 OS_STATUS_KILLING_IS_DISABLED = (((uint32) (((uint32)(8u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x05)))),

 OS_STATUS_ORDER = (((uint32) (((uint32)(9u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x05)))),

 OS_STATUS_STATE_1 = (((uint32) (((uint32)(1u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x07)))),

 OS_STATUS_STATE_2 = (((uint32) (((uint32)(2u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x07)))),

 OS_STATUS_STATE_STOPPED = (((uint32) (((uint32)(3u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x07)))),

 OS_STATUS_STATE_RUNNING = (((uint32) (((uint32)(4u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x07)))),

 OS_STATUS_STATE_NEXTED = (((uint32) (((uint32)(5u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x07)))),

 OS_STATUS_STATE_WAITING = (((uint32) (((uint32)(6u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x07)))),

 OS_STATUS_STATE_NO_RESTART = (((uint32) (((uint32)(7u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x07)))),

 OS_STATUS_STATE_ALREADY_TERMINATED = (((uint32) (((uint32)(8u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x07)))),

 OS_STATUS_STATE_RESTARTING_NO_MEMBER = (((uint32) (((uint32)(9u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x07)))),

 OS_STATUS_STATE_ALREADY_RESTARTING = (((uint32) (((uint32)(10u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x07)))),

 OS_STATUS_VALUE_IS_ZERO_1 = (((uint32) (((uint32)(1u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x08)))),

 OS_STATUS_VALUE_IS_ZERO_2 = (((uint32) (((uint32)(2u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x08)))),

 OS_STATUS_VALUE_IS_TOO_HIGH_1 = (((uint32) (((uint32)(3u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x08)))),

 OS_STATUS_VALUE_IS_TOO_HIGH_2 = (((uint32) (((uint32)(4u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x08)))),

 OS_STATUS_VALUE_IS_TOO_HIGH_3 = (((uint32) (((uint32)(5u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x08)))),

 OS_STATUS_VALUE_IS_OUT_OF_BOUNDS_1 = (((uint32) (((uint32)(6u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x08)))),

 OS_STATUS_VALUE_IS_OUT_OF_BOUNDS_2 = (((uint32) (((uint32)(7u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x08)))),

 OS_STATUS_VALUE_IS_TOO_LOW_1 = (((uint32) (((uint32)(8u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x08)))),

 OS_STATUS_VALUE_IS_TOO_LOW_2 = (((uint32) (((uint32)(9u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x08)))),

 OS_STATUS_VALUE_IS_TOO_LOW_3 = (((uint32) (((uint32)(10u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x08)))),

 OS_STATUS_VALUE_IS_NOT_BOOLEAN = (((uint32) (((uint32)(11u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x08)))),

 OS_STATUS_CORE_CROSS_DATA = (((uint32) (((uint32)(1u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x16)))),

 OS_STATUS_PARAM_POINTER_1 = (((uint32) (((uint32)(1u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x17)))),

 OS_STATUS_PARAM_POINTER_2 = (((uint32) (((uint32)(2u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x17)))),

 OS_STATUS_PARAM_POINTER_3 = (((uint32) (((uint32)(3u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0x17)))),

 OS_STATUS_NO_NTFSTACK_POOL_EMPTY = (((uint32) (((uint32)(1u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0xF4)))),

 OS_STATUS_NO_NTFSTACK_APPLIMIT_EXCEEDED = (((uint32) (((uint32)(2u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0xF4)))),

 OS_STATUS_UNIMPLEMENTED_CLEARPENDING = (((uint32) (((uint32)(1u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0xF3)))),

 OS_STATUS_UNIMPLEMENTED_EXCEPTIONCONTEXT = (((uint32) (((uint32)(2u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0xF3)))),

 OS_STATUS_NO_BARRIER_PARTICIPANT = (((uint32) (((uint32)(1u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0xF2)))),

 OS_STATUS_STACKUSAGE_DISABLED_BY_CONFIG = (((uint32) (((uint32)(1u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0xF1)))),

 OS_STATUS_EVENT_DISABLED_BY_CONFIG = (((uint32) (((uint32)(2u)) << (sizeof(StatusType)*8u)) | (uint32)(((StatusType)0xF1))))

} Os_StatusType;




typedef enum
{
 PRO_IGNORE,
 PRO_IGNORE_EXCEPTION,
 PRO_TERMINATETASKISR,
 PRO_TERMINATEAPPL,
 PRO_TERMINATEAPPL_RESTART,

 PRO_SHUTDOWN,
 OS_PROTECTIONREACTION_COUNT
} ProtectionReturnType;



typedef enum
{
 OS_ERRORPARAMINDEX_1 = 0,
 OS_ERRORPARAMINDEX_2 = 1,
 OS_ERRORPARAMINDEX_3 = 2,
 OS_ERRORPARAMINDEX_COUNT = 3
}Os_ErrorParmIndexType;



typedef struct
{

 OSServiceIdType Service;


 StatusType Error;


 Os_StatusType DetailedError;
} Os_ErrorInformationType;



typedef Os_ErrorInformationType * Os_ErrorInformationRefType;
# 816 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Types.h"
typedef enum
{


 SCHEDULETABLE_STOPPED = 0,


 SCHEDULETABLE_NEXT = 1,


 SCHEDULETABLE_WAITING = 2,


 SCHEDULETABLE_RUNNING = 3,


 SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS = 4
} ScheduleTableStatusType;


typedef ScheduleTableStatusType *ScheduleTableStatusRefType;



typedef Os_Hal_AddressType Os_AccessCheckAddress;



typedef const void * MemoryStartAddressType;



typedef Os_AccessCheckAddress MemorySizeType;



typedef enum
{
 OS_MEM_ACCESS_TYPE_NON = 0,
 OS_MEM_ACCESS_TYPE_READ = 1,
 OS_MEM_ACCESS_TYPE_R = 1,
 OS_MEM_ACCESS_TYPE_WRITE = 2,
 OS_MEM_ACCESS_TYPE_W = 2,
 OS_MEM_ACCESS_TYPE_RW = 3,
 OS_MEM_ACCESS_TYPE_EXECUTE = 4,
 OS_MEM_ACCESS_TYPE_X = 4,
 OS_MEM_ACCESS_TYPE_RX = 5,
 OS_MEM_ACCESS_TYPE_WX = 6,
 OS_MEM_ACCESS_TYPE_RWX = 7,
 OS_MEM_ACCESS_TYPE_STACK = 8,
 OS_MEM_ACCESS_TYPE_S = 8,
 OS_MEM_ACCESS_TYPE_RS = 9,
 OS_MEM_ACCESS_TYPE_WS = 10,
 OS_MEM_ACCESS_TYPE_RWS = 11,
 OS_MEM_ACCESS_TYPE_XS = 12,
 OS_MEM_ACCESS_TYPE_RXS = 13,
 OS_MEM_ACCESS_TYPE_WXS = 14,
 OS_MEM_ACCESS_TYPE_RWXS = 15
} Os_MemAccessType;

typedef Os_MemAccessType AccessType;



typedef void * Os_AddressType;

typedef const void * Os_AddressOfConstType;
# 891 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Types.h"
typedef enum
{

 OS_CORESTARTSTATE_START_UNREQUESTED = 0,

 OS_CORESTARTSTATE_START_REQUESTED_ASR,

 OS_CORESTARTSTATE_START_REQUESTED_NONASR,

 OS_CORESTARTSTATE_STARTED_ASR,

 OS_CORESTARTSTATE_STARTED_NONASR
}Os_CoreStartStateType;
# 56 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Types_Lcfg.h" 1
# 57 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Hal_Lcfg.h" 1
# 85 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Hal_Lcfg.h"
typedef enum
{
 OS_CORE_ID_MASTER = 0,
 OS_CORE_ID_0 = 0,
 OS_COREID_COUNT = 1
} CoreIdType;
# 62 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2
# 91 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 156 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code "OS_ApplBackgroundTask_Core0_CODE"
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 92 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2




extern void Os_Task_ApplBackgroundTask_Core0(void);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 169 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code restore
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 100 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 181 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code "OS_ApplInitTask_Core0_CODE"
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 104 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2




extern void Os_Task_ApplInitTask_Core0(void);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code restore
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 112 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 206 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code "OS_ApplTask_Core0_HighPrio_CODE"
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 116 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2




extern void Os_Task_ApplTask_Core0_HighPrio(void);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 219 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code restore
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 124 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 231 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code "OS_ApplTask_Core0_LowPrio_CODE"
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 128 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2




extern void Os_Task_ApplTask_Core0_LowPrio(void);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 244 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code restore
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 136 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 256 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code "OS_BackgroundTask_Core0_CODE"
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 140 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2




extern void Os_Task_BackgroundTask_Core0(void);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 269 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code restore
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 148 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 281 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code "OS_BswTask_Core0_HighPrio_CODE"
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 152 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2




extern void Os_Task_BswTask_Core0_HighPrio(void);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 294 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code restore
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 160 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 306 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code "OS_BswTask_Core0_LowPrio_CODE"
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 164 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2




extern void Os_Task_BswTask_Core0_LowPrio(void);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 319 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code restore
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 172 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 356 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code "OS_Default_Init_Task_CODE"
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 176 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2




extern void Os_Task_Default_Init_Task(void);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 369 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code restore
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 184 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 381 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code "OS_Default_Init_Task_Trusted_CODE"
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 188 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2




extern void Os_Task_Default_Init_Task_Trusted(void);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 394 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code restore
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 196 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 406 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code "OS_OsTask_ALV_BeltFunctionAlgo_CODE"
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 200 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2




extern void Os_Task_OsTask_ALV_BeltFunctionAlgo(void);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 419 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code restore
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 208 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 331 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code "OS_CanIsr_1_CODE"
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 212 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2




extern void Os_Isr_CanIsr_1(void);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 344 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code restore
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 220 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 431 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code "OS_vHsmResponseIsr_CODE"
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 224 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2




extern void Os_Isr_vHsmResponseIsr(void);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 444 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code restore
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 232 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Lcfg.h" 2
# 40 "S:/COMPON~1/APPLIC~1/Supplier/Os/OsInt.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Types.h" 1
# 41 "S:/COMPON~1/APPLIC~1/Supplier/Os/OsInt.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Hal_OsInt.h" 1
# 48 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Hal_OsInt.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Hal_Cfg.h" 1
# 49 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Hal_OsInt.h" 2
# 71 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Hal_OsInt.h"
struct Os_ExceptionContextType_Tag
{

 uint32 AddressRegisters[16];


 uint32 DataRegisters[16];


 uint32 Ra;


 uint32 Psw;


 uint32 ExceptionSource;


 uint32 Pcpn;


 uint32 Pie;


 uint32 MpuRegionForStackLow;


 uint32 MpuRegionForStackUpper;


 uint32 RawPCXI;
};
# 46 "S:/COMPON~1/APPLIC~1/Supplier/Os/OsInt.h" 2
# 325 "S:/COMPON~1/APPLIC~1/Supplier/Os/OsInt.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 131 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code "OS_SHUTDOWNHOOK_CODE"
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 326 "S:/COMPON~1/APPLIC~1/Supplier/Os/OsInt.h" 2
# 344 "S:/COMPON~1/APPLIC~1/Supplier/Os/OsInt.h"
void ShutdownHook(StatusType Fatalerror);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 144 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code restore
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 347 "S:/COMPON~1/APPLIC~1/Supplier/Os/OsInt.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 56 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code "OS_ERRORHOOK_CODE"
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 353 "S:/COMPON~1/APPLIC~1/Supplier/Os/OsInt.h" 2
# 374 "S:/COMPON~1/APPLIC~1/Supplier/Os/OsInt.h"
void ErrorHook(StatusType Error);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 69 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code restore
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 378 "S:/COMPON~1/APPLIC~1/Supplier/Os/OsInt.h" 2
# 420 "S:/COMPON~1/APPLIC~1/Supplier/Os/OsInt.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 106 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code "OS_PRETASKHOOK_CODE"
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 421 "S:/COMPON~1/APPLIC~1/Supplier/Os/OsInt.h" 2
# 439 "S:/COMPON~1/APPLIC~1/Supplier/Os/OsInt.h"
void PreTaskHook(void);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 119 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h"
#pragma section code restore
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 443 "S:/COMPON~1/APPLIC~1/Supplier/Os/OsInt.h" 2
# 442 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_Cfg.h" 1
# 443 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_Hal_Os.h" 1
# 449 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h" 2
# 551 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap_OsCode.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap_OsCode.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMap_OsCodeInt.h" 1
# 54 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMap_OsCodeInt.h"
#pragma section code "OS_CODE"
# 39 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap_OsCode.h" 2
# 552 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h" 2
# 571 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_GetVersionInfo
(
 Std_VersionInfoType *versioninfo
);
# 600 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType Os_GetExceptionContext
(
 Os_ExceptionContextRefType Context
);
# 629 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType Os_SetExceptionContext
(
 Os_ExceptionContextRefType Context
);
# 653 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
Os_AddressOfConstType Os_GetExceptionAddress
(
 void
);
# 679 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_InitMemory
(
 void
);
# 712 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_Init
(
 void
);
# 739 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_InitInterruptOnly
(
 void
);
# 767 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_EnterPreStartTask
(
 void
);
# 799 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void StartCore
(
 CoreIdType CoreID,
 StatusType *Status
);
# 828 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void StartNonAutosarCore
(
 CoreIdType CoreID,
 StatusType *Status
);
# 856 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
CoreIdType GetCoreID
(
 void
);
# 882 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
uint32 GetNumberOfActivatedCores
(
 void
);
# 905 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
AppModeType GetActiveApplicationMode
(
 void
);
# 929 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void StartOS
(
 AppModeType Mode
);
# 954 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void ShutdownOS
(
 StatusType Error
);
# 978 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void ShutdownAllCores
(
 StatusType Error
);
# 1008 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType ControlIdle
(
 CoreIdType CoreID,
 IdleModeType IdleMode
);
# 1037 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType Os_GetUnhandledIrq
(
 Os_InterruptSourceIdRefType InterruptSource
);
# 1065 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType Os_GetUnhandledExc
(
 Os_ExceptionSourceIdRefType ExceptionSource
);
# 1091 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
uint32 Os_GetTaskStackUsage
(
 TaskType TaskID
);
# 1117 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
uint32 Os_GetISRStackUsage
(
 ISRType IsrID
);
# 1144 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
uint32 Os_GetKernelStackUsage
(
 CoreIdType CoreID
);
# 1172 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
uint32 Os_GetStartupHookStackUsage
(
 CoreIdType CoreID
);
# 1200 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
uint32 Os_GetErrorHookStackUsage
(
 CoreIdType CoreID
);
# 1228 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
uint32 Os_GetShutdownHookStackUsage
(
 CoreIdType CoreID
);
# 1256 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
uint32 Os_GetProtectionHookStackUsage
(
 CoreIdType CoreID
);
# 1284 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
uint32 Os_GetNonTrustedFunctionStackUsage
(
 Os_NonTrustedFunctionIndexType FunctionIndex
);
# 1314 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType GetSpinlock(SpinlockIdType SpinlockId);
# 1343 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType ReleaseSpinlock(SpinlockIdType SpinlockId);
# 1371 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType TryToGetSpinlock
(
 SpinlockIdType SpinlockId,
 TryToGetSpinlockType* Success
);
# 1394 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void DisableAllInterrupts(void);
# 1412 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void EnableAllInterrupts(void);
# 1431 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void SuspendAllInterrupts(void);
# 1450 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void ResumeAllInterrupts(void);
# 1469 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void SuspendOSInterrupts(void);
# 1488 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void ResumeOSInterrupts(void);
# 1509 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_DisableLevelAM(void);
# 1531 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_DisableLevelKM(void);
# 1552 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_DisableLevelUM(void);
# 1573 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_EnableLevelAM(void);
# 1595 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_EnableLevelKM(void);
# 1616 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_EnableLevelUM(void);
# 1637 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_DisableGlobalAM(void);
# 1659 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_DisableGlobalKM(void);
# 1680 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_DisableGlobalUM(void);
# 1701 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_EnableGlobalAM(void);
# 1723 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_EnableGlobalKM(void);
# 1744 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_EnableGlobalUM(void);
# 1775 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType Os_DisableInterruptSource
(
 ISRType ISRID
);
# 1810 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType Os_InitialEnableInterruptSources
(
 boolean ClearPending
);
# 1843 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType Os_EnableInterruptSource
(
 ISRType ISRID,
 boolean ClearPending
);
# 1880 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType Os_ClearPendingInterrupt
(
 ISRType ISRID
);
# 1911 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType Os_IsInterruptSourceEnabled
(
 ISRType ISRID,
 boolean * IsEnabled
);
# 1945 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType Os_IsInterruptPending
(
 ISRType ISRID,
 boolean * IsPending
);
# 1979 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType Os_BarrierSynchronize
(
 Os_BarrierIdType BarrierID
);
# 2012 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType ActivateTask
(
 TaskType TaskID
);
# 2040 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType TerminateTask
(
 void
);
# 2074 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType ChainTask
(
 TaskType TaskID
);
# 2111 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType Schedule(void);
# 2138 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType GetTaskID(TaskRefType TaskID);
# 2169 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType GetTaskState(TaskType TaskID, TaskStateRefType State);
# 2193 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ISRType GetISRID(void);
# 2227 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType SetEvent
(
 TaskType TaskID,
 EventMaskType Mask
);
# 2258 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType ClearEvent
(
 EventMaskType Mask
);
# 2299 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType GetEvent
(
 TaskType TaskID,
 EventMaskRefType Mask
);
# 2336 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType WaitEvent
(
 EventMaskType Mask
);
# 2367 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType IncrementCounter
(
 CounterType CounterID
);
# 2405 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType GetCounterValue
(
 CounterType CounterID,
 TickRefType Value
);
# 2446 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType GetElapsedValue
(
 CounterType CounterID,
 TickRefType Value,
 TickRefType ElapsedValue
);
# 2483 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType GetAlarmBase
(
 AlarmType AlarmID,
 AlarmBaseRefType Info
);
# 2521 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType GetAlarm
(
 AlarmType AlarmID,
 TickRefType Tick
);
# 2565 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType SetRelAlarm
(
 AlarmType AlarmID,
 TickType Increment,
 TickType Cycle
);
# 2609 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType SetAbsAlarm
(
 AlarmType AlarmID,
 TickType Start,
 TickType Cycle
);
# 2643 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType CancelAlarm
(
 AlarmType AlarmID
);
# 2679 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType GetResource
(
 ResourceType ResID
);
# 2713 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType ReleaseResource
(
 ResourceType ResID
);
# 2746 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType StartScheduleTableRel
(
 ScheduleTableType ScheduleTableID,
 TickType Offset
);
# 2779 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType StartScheduleTableAbs
(
 ScheduleTableType ScheduleTableID,
 TickType Start
);
# 2810 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType StopScheduleTable
(
 ScheduleTableType ScheduleTableID
);
# 2844 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType NextScheduleTable
(
 ScheduleTableType ScheduleTableID_From,
 ScheduleTableType ScheduleTableID_To
);
# 2878 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType GetScheduleTableStatus
(
 ScheduleTableType ScheduleTableID,
 ScheduleTableStatusRefType ScheduleStatus
);
# 2911 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType StartScheduleTableSynchron
(
 ScheduleTableType ScheduleTableID
);
# 2944 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType SyncScheduleTable
(
 ScheduleTableType ScheduleTableID,
 TickType Value
);
# 2979 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType SetScheduleTableAsync
(
 ScheduleTableType ScheduleTableID
);
# 3006 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ApplicationType GetApplicationID
(
 void
);
# 3033 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ApplicationType GetCurrentApplicationID
(
 void
);
# 3063 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType GetApplicationState
(
 ApplicationType Application,
 ApplicationStateRefType Value
);
# 3101 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ObjectAccessType CheckObjectAccess
(
 ApplicationType ApplID,
 ObjectTypeType ObjectType,
 Os_ObjectIdType ObjectID
);
# 3136 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ApplicationType CheckObjectOwnership
(
 ObjectTypeType ObjectType,
 Os_ObjectIdType ObjectID
);
# 3162 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType AllowAccess(void);
# 3198 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType TerminateApplication
(
 ApplicationType Application,
 RestartType RestartOption
);
# 3232 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
uint8 Os_ReadPeripheral8Legacy
(
 Os_PeripheralIdType PeripheralID,
 uint32 Address
);
# 3266 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
uint16 Os_ReadPeripheral16Legacy
(
 Os_PeripheralIdType PeripheralID,
 uint32 Address
);
# 3300 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
uint32 Os_ReadPeripheral32Legacy
(
 Os_PeripheralIdType PeripheralID,
 uint32 Address
);
# 3333 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_WritePeripheral8Legacy
(
 Os_PeripheralIdType PeripheralID,
 uint32 Address,
 uint8 Value
);
# 3367 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_WritePeripheral16Legacy
(
 Os_PeripheralIdType PeripheralID,
 uint32 Address,
 uint16 Value
);
# 3401 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_WritePeripheral32Legacy
(
 Os_PeripheralIdType PeripheralID,
 uint32 Address,
 uint32 Value
);
# 3436 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_ModifyPeripheral8Legacy
(
 Os_PeripheralIdType PeripheralID,
 uint32 Address,
 uint8 ClearMask,
 uint8 SetMask
);
# 3472 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_ModifyPeripheral16Legacy
(
 Os_PeripheralIdType PeripheralID,
 uint32 Address,
 uint16 ClearMask,
 uint16 SetMask
);
# 3508 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_ModifyPeripheral32Legacy
(
 Os_PeripheralIdType PeripheralID,
 uint32 Address,
 uint32 ClearMask,
 uint32 SetMask
);
# 3542 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
uint8 Os_ReadPeripheral8
(
 Os_PeripheralIdType PeripheralID,
 const uint8 * Address
);
# 3574 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
uint16 Os_ReadPeripheral16
(
 Os_PeripheralIdType PeripheralID,
 const uint16 * Address
);
# 3606 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
uint32 Os_ReadPeripheral32
(
 Os_PeripheralIdType PeripheralID,
 const uint32 * Address
);
# 3637 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_WritePeripheral8
(
 Os_PeripheralIdType PeripheralID,
 uint8 * Address,
 uint8 Value
);
# 3669 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_WritePeripheral16
(
 Os_PeripheralIdType PeripheralID,
 uint16 * Address,
 uint16 Value
);
# 3701 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_WritePeripheral32
(
 Os_PeripheralIdType PeripheralID,
 uint32 * Address,
 uint32 Value
);
# 3734 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_ModifyPeripheral8
(
 Os_PeripheralIdType PeripheralID,
 uint8 * Address,
 uint8 ClearMask,
 uint8 SetMask
);
# 3768 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_ModifyPeripheral16
(
 Os_PeripheralIdType PeripheralID,
 uint16 * Address,
 uint16 ClearMask,
 uint16 SetMask
);
# 3802 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_ModifyPeripheral32
(
 Os_PeripheralIdType PeripheralID,
 uint32 * Address,
 uint32 ClearMask,
 uint32 SetMask
);
# 3836 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType CallTrustedFunction
(
 TrustedFunctionIndexType FunctionIndex,
 TrustedFunctionParameterRefType FunctionParams
);
# 3870 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType Os_CallNonTrustedFunction
(
 Os_NonTrustedFunctionIndexType FunctionIndex,
 Os_NonTrustedFunctionParameterRefType FunctionParams
);
# 3900 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType Os_CallFastTrustedFunction
(
 Os_FastTrustedFunctionIndexType FunctionIndex,
 Os_FastTrustedFunctionParameterRefType FunctionParams
);
# 3932 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
AccessType CheckTaskMemoryAccess
(
 TaskType TaskID,
 MemoryStartAddressType Address,
 MemorySizeType Size
);
# 3965 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
AccessType CheckISRMemoryAccess
(
 ISRType ISRID,
 MemoryStartAddressType Address,
 MemorySizeType Size
);
# 3997 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
void Os_GetCoreStartState(
 CoreIdType CoreID,
 Os_CoreStartStateType *CoreState,
 StatusType *Status
);
# 4025 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
StatusType Os_GetDetailedError(Os_ErrorInformationRefType ErrorRef);
# 4043 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
OSServiceIdType OSErrorGetServiceId(void);
# 4064 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ISRType OSError_Os_DisableInterruptSource_ISRID(void);
# 4085 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ISRType OSError_Os_EnableInterruptSource_ISRID(void);
# 4106 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
boolean OSError_Os_EnableInterruptSource_ClearPending(void);
# 4127 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ISRType OSError_Os_ClearPendingInterrupt_ISRID(void);
# 4148 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ISRType OSError_Os_IsInterruptSourceEnabled_ISRID(void);
# 4169 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
 boolean * OSError_Os_IsInterruptSourceEnabled_IsEnabled(void);
# 4190 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ISRType OSError_Os_IsInterruptPending_ISRID(void);
# 4211 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
 boolean * OSError_Os_IsInterruptPending_IsPending(void);
# 4232 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TrustedFunctionIndexType OSError_CallTrustedFunction_FunctionIndex(void);
# 4253 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TrustedFunctionParameterRefType
OSError_CallTrustedFunction_FunctionParams(void);
# 4275 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
Os_FastTrustedFunctionIndexType OSError_CallFastTrustedFunction_FunctionIndex(void);
# 4296 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
Os_FastTrustedFunctionParameterRefType
OSError_CallFastTrustedFunction_FunctionParams(void);
# 4319 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
Os_NonTrustedFunctionIndexType OSError_CallNonTrustedFunction_FunctionIndex(void);
# 4340 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
Os_NonTrustedFunctionParameterRefType
OSError_CallNonTrustedFunction_FunctionParams(void);
# 4362 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ScheduleTableType OSError_StartScheduleTableRel_ScheduleTableID(void);
# 4383 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TickType OSError_StartScheduleTableRel_Offset(void);
# 4404 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ScheduleTableType OSError_StartScheduleTableAbs_ScheduleTableID(void);
# 4425 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TickType OSError_StartScheduleTableAbs_Start(void);
# 4446 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ScheduleTableType OSError_StopScheduleTable_ScheduleTableID(void);
# 4467 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ScheduleTableType OSError_NextScheduleTable_ScheduleTableID_From(void);
# 4488 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ScheduleTableType OSError_NextScheduleTable_ScheduleTableID_To(void);
# 4509 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ScheduleTableType OSError_StartScheduleTableSynchron_ScheduleTableID(void);
# 4530 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ScheduleTableType OSError_SyncScheduleTable_ScheduleTableID(void);
# 4551 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TickType OSError_SyncScheduleTable_Value(void);
# 4572 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ScheduleTableType OSError_SetScheduleTableAsync_ScheduleTableID(void);
# 4593 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ScheduleTableType OSError_GetScheduleTableStatus_ScheduleTableID(void);
# 4614 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ScheduleTableStatusRefType OSError_GetScheduleTableStatus_ScheduleStatus(void);
# 4635 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
CounterType OSError_IncrementCounter_CounterID(void);
# 4656 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
CounterType OSError_GetCounterValue_CounterID(void);
# 4677 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TickRefType OSError_GetCounterValue_Value(void);
# 4698 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
CounterType OSError_GetElapsedValue_CounterID(void);
# 4719 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TickRefType OSError_GetElapsedValue_Value(void);
# 4740 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TickRefType OSError_GetElapsedValue_ElapsedValue(void);
# 4761 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ApplicationType OSError_TerminateApplication_Application(void);
# 4782 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
RestartType OSError_TerminateApplication_RestartOption(void);
# 4803 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ApplicationType OSError_GetApplicationState_Application(void);
# 4824 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ApplicationStateRefType OSError_GetApplicationState_Value(void);
# 4845 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
SpinlockIdType OSError_GetSpinlock_SpinlockId(void);
# 4866 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
SpinlockIdType OSError_ReleaseSpinlock_SpinlockId(void);
# 4887 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
SpinlockIdType OSError_TryToGetSpinlock_SpinlockId(void);
# 4908 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TryToGetSpinlockType const * OSError_TryToGetSpinlock_Success(void);
# 4929 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
CoreIdType OSError_ControlIdle_CoreID(void);
# 4950 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
Os_ExceptionContextRefType OSError_Os_GetExceptionContext_Context(void);
# 4971 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
Os_ExceptionContextRefType OSError_Os_SetExceptionContext_Context(void);
# 4992 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
IdleModeType OSError_ControlIdle_IdleMode(void);
# 5013 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
Os_BarrierIdType OSError_BarrierSynchronize_BarrierID(void);
# 5035 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TaskType OSError_ActivateTask_TaskID(void);
# 5057 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TaskType OSError_ChainTask_TaskID(void);
# 5079 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TaskRefType OSError_GetTaskID_TaskID(void);
# 5101 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TaskType OSError_GetTaskState_TaskID(void);
# 5123 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TaskStateRefType OSError_GetTaskState_State(void);
# 5145 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TaskType OSError_SetEvent_TaskID(void);
# 5167 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
EventMaskType OSError_SetEvent_Mask(void);
# 5189 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
EventMaskType OSError_ClearEvent_Mask(void);
# 5211 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TaskType OSError_GetEvent_TaskID(void);
# 5233 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
EventMaskRefType OSError_GetEvent_Mask(void);
# 5255 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
EventMaskType OSError_WaitEvent_Mask(void);
# 5277 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
AlarmType OSError_GetAlarmBase_AlarmID(void);
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
AlarmBaseRefType OSError_GetAlarmBase_Info(void);
# 5321 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
AlarmType OSError_GetAlarm_AlarmID(void);
# 5343 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TickRefType OSError_GetAlarm_Tick(void);
# 5365 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
AlarmType OSError_SetRelAlarm_AlarmID(void);
# 5387 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TickType OSError_SetRelAlarm_increment(void);
# 5409 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TickType OSError_SetRelAlarm_cycle(void);
# 5431 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
AlarmType OSError_SetAbsAlarm_AlarmID(void);
# 5453 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TickType OSError_SetAbsAlarm_start(void);
# 5475 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
TickType OSError_SetAbsAlarm_cycle(void);
# 5497 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
AlarmType OSError_CancelAlarm_AlarmID(void);
# 5519 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ResourceType OSError_GetResource_ResID(void);
# 5541 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
ResourceType OSError_ReleaseResource_ResID(void);
# 5562 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
Os_InterruptSourceIdRefType OSError_Os_GetUnhandledIrq_InterruptSource(void);
# 5583 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h"
Os_ExceptionSourceIdRefType OSError_Os_GetUnhandledExc_ExceptionSource(void);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap_OsCode.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap_OsCode.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMap_OsCodeInt.h" 1
# 67 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMap_OsCodeInt.h"
#pragma section code restore
# 39 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap_OsCode.h" 2
# 5588 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os.h" 2
# 33 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/SchM_Dem.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 36 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/SchM_Dem.h" 2

void Dem_MasterMainFunction(void);
void Dem_SatelliteMainFunction(void);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 42 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/SchM_Dem.h" 2
# 65 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/SchM_Dem.h"
}
# 47 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Int.h" 2
# 183 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Int.h"
typedef uint16 Dem_HandleType;


typedef uint16_least Dem_SimpleIterType;


struct Dem_ComplexIterType_s
{
 uint16_least mIdx;
 uint16_least mEndIdx;
};

typedef struct Dem_ComplexIterType_s Dem_ComplexIterType;
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_SatelliteData_Types.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Infrastructure_Types.h" 1
# 41 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Infrastructure_Types.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_ExtCom_Types.h" 1
# 58 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_ExtCom_Types.h"
typedef uint16 Dem_ExtCom_FiMFunctionIdType;







typedef uint32 Dem_ExtCom_ApplicationType;
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Infrastructure_Types.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Com_Types.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Infrastructure_Types.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_EventQueue_Types.h" 1
# 90 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_EventQueue_Types.h"
typedef uint8 Dem_EventQueue_StatusType;
# 44 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Infrastructure_Types.h" 2
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_SatelliteData_Types.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_DebounceBase_Fwd.h" 1
# 48 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_DebounceBase_Fwd.h"
typedef uint16 Dem_Debounce_DataType;
typedef uint8 Dem_Debounce_StatusType;
# 44 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_SatelliteData_Types.h" 2
# 97 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_SatelliteData_Types.h"
struct Dem_SatelliteData_Data_s
{
 Dem_Debounce_DataType DebounceData;
 Dem_EventQueue_StatusType QueueStatus;
 uint8 SharedStatus;
};


struct Dem_SatelliteData_ExtendedData_s
{
 uint32 SharedData;
};



union Dem_SatelliteData_ExtendedData_u
{
 volatile struct Dem_SatelliteData_ExtendedData_s Data;
 volatile Dem_Com_ProcessorWordType Raw;
};


typedef union Dem_SatelliteData_ExtendedData_u Dem_SatelliteData_ExtendedDataType;


union Dem_SatelliteData_Data_u
{
 volatile struct Dem_SatelliteData_Data_s Data;
 volatile Dem_Com_ProcessorWordType Raw;
};


typedef union Dem_SatelliteData_Data_u Dem_SatelliteData_DataType;

typedef Dem_SatelliteData_DataType * Dem_SatelliteData_DataPtrType;

typedef const Dem_SatelliteData_DataType * Dem_SatelliteData_ConstDataPtrType;
# 70 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_DTCSelector_Types.h" 1
# 55 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_DTCSelector_Types.h"
typedef uint8 Dem_DTCSelector_HandleType;







typedef uint8 Dem_DTCSelector_ResultType;
# 80 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_DTCSelector_Types.h"
typedef uint8 Dem_DTCSelector_GroupIdType;
# 91 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_DTCSelector_Types.h"
union Dem_DTCSelector_Selection_u
{
 Dem_EventIdType EventId;
 Dem_DTCSelector_GroupIdType GroupId;
 uint8 GroupMask;
};

typedef union Dem_DTCSelector_Selection_u Dem_DTCSelector_SelectionType;


struct Dem_DTCSelector_RequestType_s
{
 uint32 DTC;
 Dem_DTCFormatType DTCFormat;
 Dem_DTCOriginType DTCOrigin;
};

typedef struct Dem_DTCSelector_RequestType_s Dem_DTCSelector_RequestType;


struct Dem_DTCSelector_DataType_s
{
 Dem_DTCSelector_RequestType Request;
 Dem_DTCSelector_SelectionType Selection;
 uint8 MemoryId;
 Dem_DTCSelector_ResultType SelectorState;
 uint8 ActiveAsyncOps;
};

typedef struct Dem_DTCSelector_DataType_s Dem_DTCSelector_DataType;


typedef Dem_DTCSelector_DataType * Dem_DTCSelector_DataPtrType;
# 71 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_FilterData_Types.h" 1
# 44 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_FilterData_Types.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_FilterDataIF_Types.h" 1
# 83 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_FilterDataIF_Types.h"
typedef uint8 Dem_FilterData_HandleType;


typedef uint8 Dem_FilterData_FilterType;


typedef Dem_EventIdType ( * Dem_FilterData_FuncPtrType) (
 Dem_FilterData_HandleType FilterId
 );


enum Dem_FilterData_DTCFilteringStrategy
{
 Dem_FilterData_Invalid = 0,
 Dem_FilterData_FilterChronological,
 Dem_FilterData_FilterEventBased,
 Dem_FilterData_FilterEventBased_PermanentMemory,
 Dem_FilterData_FilterEventBased_ReadinessGroup,
 Dem_FilterData_FilterEventBased_ExtendendDataRecord
};


typedef enum Dem_FilterData_DTCFilteringStrategy Dem_FilterData_DTCFilteringStrategyType;


struct Dem_FilterData_ResultType_s
{
 uint32 DTC;
 sint8 FDC;
 uint8 DTCStatus;
 Dem_DTCSeverityType Severity;
 uint8 FunctionalUnit;
 uint8 OccurrenceCounter;
 Dem_J1939DcmLampStatusType LampStatus;
};

typedef struct Dem_FilterData_ResultType_s Dem_FilterData_ResultType;
# 45 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_FilterData_Types.h" 2
# 72 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_FreezeFrameIterator_Types.h" 1
# 57 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_FreezeFrameIterator_Types.h"
typedef uint8 Dem_FreezeFrameIterator_HandleType;






typedef uint8 Dem_FreezeFrameIterator_DTCFormatType;
# 73 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_ClearDTC_Types.h" 1
# 41 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_ClearDTC_Types.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_DTCSelector_Types.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_ClearDTC_Types.h" 2
# 55 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_ClearDTC_Types.h"
typedef uint8 Dem_ClearDTC_HandleType;






typedef uint8 Dem_ClearDTC_StatusType;
# 74 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_ClearDTC_Types.h"
struct Dem_ClearDTC_DataType_s
{
 Dem_ClearDTC_StatusType ClearDTCStatus;
 Dem_DTCSelector_HandleType DTCSelector;
};


typedef struct Dem_ClearDTC_DataType_s Dem_ClearDTC_DataType;
# 74 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Event_Types.h" 1
# 44 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Event_Types.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_EventInternalStatus_Types.h" 1
# 135 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_EventInternalStatus_Types.h"
typedef uint8 Dem_Event_InternalStatusType;

typedef uint8 Dem_Event_ExtendedStatusType;
# 45 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Event_Types.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_EventIF_Types.h" 1
# 41 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_EventIF_Types.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_UDSStatus_Types.h" 1
# 59 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_UDSStatus_Types.h"
typedef uint8 Dem_UDSStatus_Type;
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_EventIF_Types.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Cfg_Types.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Cfg_Types.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Prestore_Types.h" 1
# 72 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Prestore_Types.h"
typedef uint8 Dem_Prestore_QueueActionType;
# 40 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Cfg_Types.h" 2
# 310 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Cfg_Types.h"
typedef uint8 Dem_EventOBDReadinessGroupType;


typedef uint16 Dem_Cfg_CombinedGroupIndexType;

typedef uint16 Dem_Cfg_DataIndexType;

typedef uint16 Dem_Cfg_ERecIndexType;

typedef uint16 Dem_Cfg_DidIndexType;

typedef uint16 Dem_Cfg_SRecIndexType;

typedef uint16 Dem_Cfg_J1939NodeIndexType;


typedef uint16 Dem_Cfg_StorageTriggerType;


typedef uint16_least Dem_Cfg_SimpleIterType;

struct Dem_Cfg_ComplexIterType_s
{
 uint16_least mIdx;
 uint16_least mEndIdx;
};


struct Dem_Cfg_ComplexIterType32Bit_s
{
 uint32_least mIdx;
 uint32_least mEndIdx;
};


typedef struct Dem_Cfg_ComplexIterType_s Dem_Cfg_ComplexIterType;

typedef struct Dem_Cfg_ComplexIterType32Bit_s Dem_Cfg_DidDataIterType;

typedef struct Dem_Cfg_ComplexIterType_s Dem_Cfg_EventCbkStatusIterType;

typedef struct Dem_Cfg_ComplexIterType32Bit_s Dem_Cfg_EventDidIterType;

typedef struct Dem_Cfg_ComplexIterType32Bit_s Dem_Cfg_GlobalSnapshotDidIterType;

typedef struct Dem_Cfg_ComplexIterType_s Dem_Cfg_EventERecIterType;

typedef struct Dem_Cfg_ComplexIterType_s Dem_Cfg_EventNormalIndicatorIterType;

typedef struct Dem_Cfg_ComplexIterType_s Dem_Cfg_EventSpecialIndicatorIterType;

typedef struct Dem_Cfg_ComplexIterType_s Dem_Cfg_EventJ1939NodeIterType;

typedef struct Dem_Cfg_ComplexIterType32Bit_s Dem_Cfg_EventObdDidIterType;

typedef struct Dem_Cfg_ComplexIterType_s Dem_Cfg_EventSRecIterType;

typedef struct Dem_Cfg_ComplexIterType_s Dem_Cfg_EventSPNIterType;

typedef struct Dem_Cfg_ComplexIterType_s Dem_Cfg_CombinedGroupIterType;

typedef struct Dem_Cfg_ComplexIterType_s Dem_Cfg_ObdFimFidIterType;

typedef struct Dem_Cfg_ComplexIterType_s Dem_Cfg_EventCbkInitFuncIterType;

typedef struct Dem_Cfg_ComplexIterType_s Dem_Cfg_EventDtrIterType;

typedef struct Dem_Cfg_ComplexIterType_s Dem_Cfg_GlobalCbkJ1939DtcIterType;

typedef struct Dem_Cfg_ComplexIterType_s Dem_Cfg_DTCFreezeFrameIterType;

typedef struct Dem_Cfg_ComplexIterType_s Dem_Cfg_DTCExtendedDataRecordIterType;

typedef struct Dem_Cfg_ComplexIterType_s Dem_Cfg_ExtendedDataRecordEventIterType;

typedef struct Dem_Cfg_ComplexIterType_s Dem_Cfg_FreezeFrameRecordEventIterType;


typedef Dem_Cfg_SimpleIterType Dem_Cfg_GlobalCbkDtcIterType;

typedef Dem_Cfg_SimpleIterType Dem_Cfg_ObdRatioIdIterType;

typedef Dem_Cfg_SimpleIterType Dem_Cfg_GlobalPidIterType;

typedef Dem_Cfg_SimpleIterType Dem_Cfg_TimeSeriesDidFastIterType;

typedef Dem_Cfg_SimpleIterType Dem_Cfg_TimeSeriesDidNormalIterType;

typedef Dem_Cfg_SimpleIterType Dem_Cfg_ReadoutBufferMemoryEntryIterType;


typedef Std_ReturnType ( * Dem_OemCbkGetCurrentOdometerFptrType)(
 uint32 * Odometer
 );

typedef Std_ReturnType ( * Dem_OemCbkGetExternalTesterStatusFptrType)(
 boolean * TesterPresent
 );
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_EventIF_Types.h" 2
# 65 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_EventIF_Types.h"
struct Dem_Event_Context_s
{
 Dem_EventIdType EventId;
 Dem_UDSStatus_Type OldEventStatus;
 Dem_UDSStatus_Type OldExternalEventStatus;
 Dem_UDSStatus_Type NewEventStatus;
 Dem_Cfg_StorageTriggerType EventEffects;
 boolean DataModified;
 boolean QualifyEvent;
};


typedef struct Dem_Event_Context_s Dem_Event_ContextType;
# 46 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Event_Types.h" 2
# 75 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_DTCReadoutBuffer_Types.h" 1
# 60 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_DTCReadoutBuffer_Types.h"
typedef uint8 Dem_DTCReadoutBuffer_HandleType;
# 71 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_DTCReadoutBuffer_Types.h"
typedef uint8 Dem_DTCReadoutBuffer_ReadoutBufferDataIndexType;
# 82 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_DTCReadoutBuffer_Types.h"
typedef uint8 Dem_DTCReadoutBuffer_StatusType;






typedef enum
{
 Dem_DTCReadoutBuffer_SnapshotSource_Obd,
 Dem_DTCReadoutBuffer_SnapshotSource_Srec,
 Dem_DTCReadoutBuffer_SnapshotSource_TimeSeries_Fast,
 Dem_DTCReadoutBuffer_SnapshotSource_TimeSeries_Normal,
 Dem_DTCReadoutBuffer_SnapshotSource_TimeSeries_PowerTrain,
 Dem_DTCReadoutBuffer_SnapshotSource_Global,
 Dem_DTCReadoutBuffer_SnapshotSource_Srec_GreaterThan_0x30,

 Dem_DTCReadoutBuffer_SnapshotSource_Invalid
} Dem_DTCReadoutBuffer_SnapshotSourceType;



typedef struct
{
 uint8 Dummy;
} Dem_DTCReadoutBuffer_EventIteratorType;



typedef Dem_Cfg_ComplexIterType Dem_DTCReadoutBuffer_RecordNumberIteratorType;
# 76 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemoryEntry_Types.h" 1
# 44 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemoryEntry_Types.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_ExtendedEntry_Types.h" 1
# 55 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_ExtendedEntry_Types.h"
typedef struct Dem_Cfg_ComplexIterType_s Dem_ExtendedEntry_IterType;


typedef Dem_ExtendedEntry_IterType * Dem_ExtendedEntry_IterPtrType;
# 45 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemoryEntry_Types.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemoryEntryIF_Types.h" 1
# 106 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemoryEntryIF_Types.h"
typedef uint8 Dem_MemoryEntry_OccurrenceCounterType;
# 46 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemoryEntry_Types.h" 2
# 77 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_ERec_Types.h" 1
# 57 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_ERec_Types.h"
typedef uint8 Dem_Dcm_ERec_0x1916_RecordNumberFilter_HandleType;


typedef Dem_Cfg_ComplexIterType Dem_Dcm_ERec_ERecNumberIterType;


typedef Dem_Cfg_ComplexIterType Dem_Dcm_ERec_DataCollectionERecIterType;
# 78 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_0x1956_Types.h" 1
# 68 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_0x1956_Types.h"
typedef Dem_ComplexIterType Dem_FilterData_0x1956_ReadinessGroupIterType;
# 79 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 3116 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
typedef uint8 Dem_Cfg_NormalIndicatorIndexType;

typedef struct Dem_Cfg_TimeSeriesEntryCompanionType_s {
 uint8 ClientCounter;
 uint8 ReadoutStatus;
} Dem_Cfg_TimeSeriesEntryCompanionType;

typedef uint16 Dem_Cfg_MaxDebounceValuesType;

typedef uint8 Dem_Cfg_DebounceLoResTimerType;

typedef volatile Dem_Com_ProcessorWordType * Dem_Cfg_ProcessorWordPtrType;

typedef volatile Dem_SatelliteData_DataType * Dem_Cfg_SatelliteDataPtrType;

typedef volatile Dem_SatelliteData_ExtendedDataType * Dem_Cfg_SatelliteExtendedDataPtrType;

typedef volatile const Dem_SatelliteData_ExtendedDataType * Dem_Cfg_SatelliteExtendedDataConstPtrType;

typedef volatile Dem_Cfg_MaxDebounceValuesType * Dem_Cfg_MaxDebounceValuesPtrType;

typedef volatile const Dem_Cfg_MaxDebounceValuesType * Dem_Cfg_MaxDebounceValuesConstPtrType;

typedef Dem_Cfg_DebounceLoResTimerType * Dem_Cfg_DebounceLoResTimerPtrType;

typedef const Dem_Cfg_DebounceLoResTimerType * Dem_Cfg_DebounceLoResTimerConstPtrType;

typedef struct Dem_Cfg_SatelliteInfoType0_s {
 volatile Dem_SatelliteData_DataType SatelliteData[ 41 ];
 volatile Dem_Com_ProcessorWordType SatelliteStatus;
} Dem_Cfg_SatelliteInfoType0;


typedef uint8 Dem_RatioIdIndexType;

typedef struct Dem_Cfg_AdminDataType_s {
 uint16 ImplementationVersion;
 uint16 ConfigurationId;
 uint16 CycleCounter[ 2 ];
 uint8 MemoryOverflow;
} Dem_Cfg_AdminDataType;

typedef struct Dem_Cfg_StatusDataType_s {
 uint16 FirstFailedEvent;
 uint16 FirstConfirmedEvent;
 uint16 MostRecentFailedEvent;
 uint16 MostRecentConfmdEvent;
 volatile uint8 EventStatus[ 41 ];
} Dem_Cfg_StatusDataType;

typedef struct Dem_Cfg_PrimaryEntryType_s {
 uint32 Timestamp;
 uint16 AgingCounter;
 uint16 EventId;
 uint8 StdEnvData[ 5 ];
 uint8 ExtendedData[ 1 ][ 1 ];
 uint8 SnapshotData[ 2 ][ 9 ];
 uint8 OccurrenceCounter;
 uint8 ExtendedHeader;
 uint8 SnapshotHeader;
} Dem_Cfg_PrimaryEntryType;

typedef Dem_Cfg_PrimaryEntryType * Dem_SharedMemoryEntryPtrType;

typedef const Dem_Cfg_PrimaryEntryType * Dem_ConstSharedMemoryEntryPtrType;

typedef struct Dem_Cfg_TimeSeriesEntryType_s {
 uint32 Timestamp;
 uint16 EventId;
} Dem_Cfg_TimeSeriesEntryType;

typedef struct Dem_Cfg_PermanentDataEntryType_s {
 uint16 EventId;
 uint8 Status;
} Dem_Cfg_PermanentDataEntryType;

typedef struct Dem_Cfg_PermanentDataType_s {
 Dem_Cfg_PermanentDataEntryType PermanentDataEntry[ 1 ];
 uint16 InitPattern;
} Dem_Cfg_PermanentDataType;

typedef struct Dem_Cfg_FreezeFrameDataEntryType_s {
 uint32 Timestamp;
 volatile uint16 EventId;
 uint8 FreezeFrameData[ 1 ];
 boolean IsVisible;
} Dem_Cfg_FreezeFrameDataEntryType;

typedef Dem_Cfg_FreezeFrameDataEntryType Dem_Cfg_FreezeFrameDataType[1];

typedef sint16 Dem_Cfg_DebounceDataType[1];

typedef uint8 Dem_Cfg_EventAvailableDataType[6];

typedef struct Dem_Cfg_ObdIumprDataType_s {
 uint16 Numerator[ 1 ];
 uint16 Denominator[ 1 ];
 uint16 GeneralDenominator;
 volatile uint8 Status[ 1 ];
 uint8 DenominatorConditionStatusReached;
 uint8 DenominatorConditionStatusInhibited;
 uint8 GlobalHybridStatus;
 uint8 GlobalNumeratorsLocked;
} Dem_Cfg_ObdIumprDataType;

typedef struct Dem_Cfg_DtrDataType_s {
 uint16 TestValue[ 1 ];
 uint16 LowLimValue[ 1 ];
 uint16 UppLimValue[ 1 ];
} Dem_Cfg_DtrDataType;

typedef struct Dem_Cfg_AgingDataType_s {
 uint8 AgedCounter[ 1 ];
} Dem_Cfg_AgingDataType;

typedef struct Dem_Cfg_CycleCounterDataType_s {
 uint8 FaultPendingCounter[ 1 ];
} Dem_Cfg_CycleCounterDataType;

typedef struct Dem_Cfg_PrestorageEntryType_s {
 uint16 EventId;
 uint8 SnapshotData[ 9 ];
 uint8 State;
} Dem_Cfg_PrestorageEntryType;

typedef Dem_Cfg_PrestorageEntryType Dem_Cfg_PrestorageType[1];

typedef uint8 Dem_Cfg_MemoryEntryHandleType;

typedef uint8 Dem_Cfg_MemoryIndexType;

typedef uint8_least Dem_Cfg_MemoryIndexIterType;

typedef uint8 Dem_Cfg_DtrStatusType;


typedef union Dem_Cfg_Union_ChronoIterType_u {
 Dem_Cfg_MemoryIndexType ChronoIter;
 uint16 EventIndex;
 uint8 PermanentIndex;
 Dem_FilterData_0x1956_ReadinessGroupIterType ReadinessGroupIter;
 Dem_Dcm_ERec_ERecNumberIterType ERecIterator;
} Dem_Cfg_Union_ChronoIterType;


typedef union Dem_Cfg_Union_TableIndexType_u {
 uint8 ReadinessGroupIdx;
 Dem_Cfg_ERecIndexType DataCollectionTableIdx;
} Dem_Cfg_Union_TableIndexType;

typedef Dem_Com_ProcessorWordType Dem_Cfg_ProcessedCombinedDTCGroupType[1];


typedef struct Dem_Cfg_FilterData_InfoType_s {
 Dem_Cfg_Union_ChronoIterType Iterator;
 Dem_FilterData_DTCFilteringStrategyType FilterDtcStrategy;
 uint16 EventId;
 uint16 NumberOfDTCsTested;
 Dem_Cfg_Union_TableIndexType TableIndex;
 Dem_DTCSeverityType SeverityMask;
 Dem_FilterData_FilterType FilterState;
 Dem_J1939DcmDTCStatusFilterType DTCStatusFilterType;
 sint8 FaultDetectionCounter;
 uint8 StatusMask;
 uint8 MemoryId;
 uint8 FilterFlags;
 uint8 NodeId;
} Dem_Cfg_FilterData_InfoType;


typedef struct Dem_Cfg_SnapshotEntry_Handle_s {
 uint16 EventId;
 Dem_Cfg_MemoryEntryHandleType MemoryEntryId;
 Dem_Cfg_SRecIndexType SnapshotIteratorIndex;
 uint8 SnapshotEntryIndex;
} Dem_Cfg_SnapshotEntry_IterType;

typedef Dem_Cfg_SnapshotEntry_IterType * Dem_Cfg_SnapshotEntry_IterPtrType;


typedef struct Dem_Cfg_FreezeFrameIterator_FilterType_s {
 Dem_Cfg_SnapshotEntry_IterType SnapshotEntryIter;
 uint16 EventId;
 Dem_FreezeFrameIterator_DTCFormatType FilterDTCFormat;
 Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind;
 Dem_Cfg_MemoryIndexType MemoryIndex;
 uint8 TimeSeriesRecordNumber;
 uint8 NodeId;
 uint8 FilterState;
} Dem_Cfg_FreezeFrameIterator_FilterType;


typedef struct Dem_Cfg_ExtendedDataRecordIterator_FilterType_s {
 Dem_Dcm_ERec_ERecNumberIterType ERecIterator;
 Dem_DTCOriginType DTCOrigin;
 Dem_Cfg_ERecIndexType DataCollectionTableIdx;
 Dem_DTCFormatType DTCFormat;
 Dem_Cfg_MemoryIndexType StoredMemoryIndex;
} Dem_Cfg_ExtendedDataRecordIterator_FilterType;

typedef Dem_Com_ProcessorWordType Dem_Cfg_ReportedEventsType[2];

typedef uint16 Dem_Cfg_IndicatorContinuousType[1];

typedef uint16 Dem_Cfg_IndicatorBlinkingType[1];

typedef uint16 Dem_Cfg_IndicatorFastFlashType[1];

typedef uint16 Dem_Cfg_IndicatorSlowFlashType[1];

typedef uint8 Dem_Cfg_GlobalIndicatorStatesType[1];

typedef uint8 Dem_Cfg_PrestorageIndexType;


typedef union Dem_Cfg_CommitBufferType_u {
 uint8 mRaw[ 1 ];
 Dem_Cfg_AdminDataType mAdmin;
 Dem_Cfg_StatusDataType mStatus;
 Dem_Cfg_PrimaryEntryType mPrimary;
} Dem_Cfg_CommitBufferType;


typedef struct Dem_Cfg_DTCReadoutBuffer_ExtendedDataIteratorType_s {
 Dem_ExtendedEntry_IterType ExtendedEntryIter;
 uint8 ExtendedEntryIndex;
} Dem_Cfg_DTCReadoutBuffer_ExtendedDataIteratorType;

typedef Dem_Cfg_DTCReadoutBuffer_ExtendedDataIteratorType * Dem_Cfg_DTCReadoutBuffer_ExtendedDataIteratorPtrType;

typedef const Dem_Cfg_DTCReadoutBuffer_ExtendedDataIteratorType * Dem_Cfg_DTCReadoutBuffer_ExtendedDataIteratorConstPtrType;


typedef struct Dem_Cfg_DTCReadoutBuffer_SnapshotDataIteratorType_s {
 Dem_Cfg_ComplexIterType SourceIterator;
 Dem_Cfg_SnapshotEntry_IterType SnapshotEntryIter;
} Dem_Cfg_DTCReadoutBuffer_SnapshotDataIteratorType;

typedef Dem_Cfg_DTCReadoutBuffer_SnapshotDataIteratorType * Dem_Cfg_DTCReadoutBuffer_SnapshotDataIteratorPtrType;

typedef const Dem_Cfg_DTCReadoutBuffer_SnapshotDataIteratorType * Dem_Cfg_DTCReadoutBuffer_SnapshotDataIteratorConstPtrType;


typedef struct Dem_Cfg_ReadOutBufferFreezeFrameDataEntryType_s {
 uint8 ObdFreezeFrame[ 1 ];
 boolean IsStored;
} Dem_Cfg_ReadOutBufferFreezeFrameDataEntryType;

typedef Dem_Cfg_ReadOutBufferFreezeFrameDataEntryType * Dem_Cfg_ReadOutBufferFreezeFrameDataEntryPtrType;


typedef struct Dem_Cfg_ReadoutBufferDataType_s {
 Dem_Cfg_PrimaryEntryType Data;
 Dem_Cfg_DTCReadoutBuffer_ExtendedDataIteratorType ExtendedIterator;
 Dem_Cfg_DTCReadoutBuffer_SnapshotDataIteratorType SnapshotIterator;
 uint16 EventId;
} Dem_Cfg_ReadoutBufferDataType;

typedef Dem_Cfg_ReadoutBufferDataType * Dem_Cfg_ReadoutBufferDataPtrType;


typedef struct Dem_Cfg_ReadoutMemIndeCounterType_s {
 uint8 FaultPendingCounter;
} Dem_Cfg_ReadoutMemIndeCounterType;

typedef const Dem_Cfg_ReadoutMemIndeCounterType * Dem_Cfg_ReadoutMemIndeCounterPtrType;


typedef struct Dem_Cfg_ReadoutBufferEntryType_s {
 Dem_Cfg_ReadoutBufferDataType ReadOutBufferData[ 1 ];
 Dem_DTCReadoutBuffer_SnapshotSourceType Source;
 uint8 MemoryId;
 uint8 State;
 Dem_Cfg_ReadOutBufferFreezeFrameDataEntryType OBDFreezeFrameData;
 uint8 SelectedSnapshotRecordNumber;
 boolean SnapshotSelected;
 uint8 SelectedExtendedDataNumber;
 boolean ExtendedRecordSelected;
} Dem_Cfg_ReadoutBufferEntryType;

typedef Dem_Cfg_ReadoutBufferEntryType * Dem_Cfg_ReadoutBufferEntryPtrType;
# 3408 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
typedef uint8_least Dem_Cfg_CallbackClearEventAllowedIterType;


typedef uint8_least Dem_Cfg_CallbackDtcStatusChangedIterType;


typedef uint8_least Dem_Cfg_CallbackGetFdcIterType;


typedef uint8_least Dem_Cfg_CallbackJ1939DtcStatusChangedIterType;


typedef uint8_least Dem_Cfg_ClearDTCTableIterType;


typedef uint8_least Dem_Cfg_ClearDtcNotificationFinishTableIterType;


typedef uint8_least Dem_Cfg_ClearDtcNotificationStartTableIterType;


typedef uint8_least Dem_Cfg_ClientTableIterType;


typedef uint8_least Dem_Cfg_CycleIdTableIterType;


typedef uint8_least Dem_Cfg_DTCSelectorTableIterType;


typedef uint8_least Dem_Cfg_DataCollectionTableIterType;


typedef uint8_least Dem_Cfg_DataCollectionTableEdr2CollIndIterType;


typedef uint8_least Dem_Cfg_DataCollectionTableErec2CollIndIterType;


typedef uint8_least Dem_Cfg_DataCollectionTableFfm2CollIndIterType;


typedef uint8_least Dem_Cfg_DataCollectionTableJ19392CollIndIterType;


typedef uint8_least Dem_Cfg_DataCollectionTablePid2CollIndIterType;


typedef uint8_least Dem_Cfg_DataElementTableIterType;


typedef uint8_least Dem_Cfg_DataElementTableCol2ElmtIndIterType;


typedef uint8_least Dem_Cfg_DebounceHiResTableIterType;


typedef uint8_least Dem_Cfg_DebounceLoResTableIterType;


typedef uint8_least Dem_Cfg_DebounceTableIterType;


typedef uint8_least Dem_Cfg_DtcGroupMaskIterType;


typedef uint8_least Dem_Cfg_DtcTableIterType;


typedef uint8_least Dem_Cfg_DtrStatusIterType;


typedef uint8_least Dem_Cfg_DtrTableIterType;


typedef uint8_least Dem_Cfg_DtrTableIndIterType;


typedef uint8_least Dem_Cfg_EnableConditionGroupTableIterType;


typedef uint8_least Dem_Cfg_EnableConditionGroupTableIndIterType;


typedef uint8_least Dem_Cfg_EnableConditionInitTableIterType;


typedef uint8_least Dem_Cfg_EnableConditionTableIterType;


typedef uint8_least Dem_Cfg_EventAvailableDefaultIterType;


typedef uint8_least Dem_Cfg_EventAvailableInVariantIterType;


typedef uint8_least Dem_Cfg_EventDataChangedIterType;


typedef uint8_least Dem_Cfg_EventDataCommitNumberIterType;


typedef uint8_least Dem_Cfg_EventStatusChangedIterType;


typedef uint8_least Dem_Cfg_EventTableIterType;


typedef uint8_least Dem_Cfg_EventTableIndIterType;


typedef uint8_least Dem_Cfg_EventTable_ERec2EventIdIndIterType;


typedef uint8_least Dem_Cfg_EventTable_ObdRdyGroup2EventIdIndIterType;


typedef uint8_least Dem_Cfg_ExtendedDataRecordIteratorTableIterType;


typedef uint8_least Dem_Cfg_ExtendedDataRecordTableIterType;


typedef uint8_least Dem_Cfg_ExtendedDataTableIterType;


typedef uint8_least Dem_Cfg_FilterInfoTableIterType;


typedef uint8_least Dem_Cfg_FilterReportedEventsIterType;


typedef uint8_least Dem_Cfg_FreezeFrameIteratorTableIterType;


typedef uint8_least Dem_Cfg_FreezeFrameNumTableIterType;


typedef uint8_least Dem_Cfg_FreezeFrameTableIterType;


typedef uint8_least Dem_Cfg_GeneralJ1939TableIterType;


typedef uint8_least Dem_Cfg_GeneralObdInputIterType;


typedef uint8_least Dem_Cfg_GlobalIndicatorStatesIterType;


typedef uint8_least Dem_Cfg_IndicatorBlinkingIterType;


typedef uint8_least Dem_Cfg_IndicatorContinuousIterType;


typedef uint8_least Dem_Cfg_IndicatorFastFlashIterType;


typedef uint8_least Dem_Cfg_IndicatorSlowFlashIterType;


typedef uint8_least Dem_Cfg_InitMonListForFuncIterType;


typedef uint8_least Dem_Cfg_InitMonitorForEventIterType;


typedef uint8_least Dem_Cfg_InitMonitorsForFuncIterType;


typedef uint8_least Dem_Cfg_J1939NodeIdIterType;


typedef uint8_least Dem_Cfg_J1939NodeIdIndIterType;


typedef uint8_least Dem_Cfg_J1939NodeIndicatorIterType;


typedef uint8_least Dem_Cfg_MemoryBlockIdIterType;


typedef uint8_least Dem_Cfg_MemoryBlockIdToMemoryEntryIdIterType;


typedef uint8_least Dem_Cfg_MemoryDataPtrIterType;


typedef uint8_least Dem_Cfg_MemoryDataSizeIterType;


typedef uint8_least Dem_Cfg_MemoryEntryIterType;


typedef uint8_least Dem_Cfg_MemoryStatusIterType;


typedef uint8_least Dem_Cfg_MidTableIterType;


typedef uint8_least Dem_Cfg_NormalIndicatorTableIterType;


typedef uint8_least Dem_Cfg_ObdIumprUpdatePendingIterType;


typedef uint8_least Dem_Cfg_PidTableIterType;


typedef uint8_least Dem_Cfg_PrestorageIndexIterType;


typedef uint8_least Dem_Cfg_PrimaryChronologyIterType;


typedef uint8_least Dem_Cfg_RatioIdTableIterType;


typedef uint8_least Dem_Cfg_ReadinessGroupTableIterType;


typedef uint8_least Dem_Cfg_ReadoutBufferIterType;


typedef uint8_least Dem_Cfg_ReportedEventsOfFilterIterType;


typedef uint8_least Dem_Cfg_SatelliteInfoIterType;


typedef uint8_least Dem_Cfg_SatelliteTimeDebounceInfoIterType;


typedef uint8_least Dem_Cfg_SecondaryChronologyIterType;


typedef uint8_least Dem_Cfg_SpecialIndicatorTableIterType;


typedef uint8_least Dem_Cfg_StartIdx500miDenRatioTableIterType;


typedef uint8_least Dem_Cfg_StorageConditionGroupTableIterType;


typedef uint8_least Dem_Cfg_StorageConditionGroupTableIndIterType;


typedef uint8_least Dem_Cfg_StorageConditionInitTableIterType;


typedef uint8_least Dem_Cfg_StorageConditionTableIterType;


typedef uint8_least Dem_Cfg_SupportedMidsTableIterType;


typedef uint8_least Dem_Cfg_TimeSeriesChronologyIterType;
# 3678 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
typedef Dem_Cfg_EnableConditionTableIterType Dem_Cfg_EnableConditionFulfilledIterType;


typedef Dem_Cfg_EnableConditionGroupTableIterType Dem_Cfg_EnableConditionGroupCounterIterType;


typedef Dem_Cfg_EnableConditionGroupTableIterType Dem_Cfg_EnableConditionGroupStateIterType;


typedef Dem_Cfg_EventTableIterType Dem_Cfg_EventCycleStatusIterType;


typedef Dem_Cfg_EventTableIterType Dem_Cfg_EventDebounceValueIterType;


typedef Dem_Cfg_EventTableIterType Dem_Cfg_EventInternalStatusIterType;


typedef Dem_Cfg_StorageConditionTableIterType Dem_Cfg_StorageConditionFulfilledIterType;


typedef Dem_Cfg_StorageConditionGroupTableIterType Dem_Cfg_StorageConditionGroupCounterIterType;
# 3711 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
typedef uint8 Dem_Cfg_ClearDTCIndexOfClientTableType;


typedef uint8 Dem_Cfg_FilterIndexOfClientTableType;


typedef uint8 Dem_Cfg_FreezeFrameIteratorIndexOfClientTableType;


typedef uint16 Dem_Cfg_NmNodeIdOfClientTableType;


typedef uint8 Dem_Cfg_ReadoutBufferIndexOfClientTableType;


typedef uint8 Dem_Cfg_SelectorIndexOfClientTableType;


typedef uint16 Dem_Cfg_ConfigurationIdType;


typedef boolean Dem_Cfg_EndsOnInitOfCycleIdTableType;


typedef uint8 Dem_Cfg_MaskedBitsOfCycleIdTableType;


typedef uint8 Dem_Cfg_OpCycleTypeOfCycleIdTableType;


typedef boolean Dem_Cfg_UsedForAgingOfCycleIdTableType;


typedef uint8 Dem_Cfg_CollectionSizeOfDataCollectionTableType;


typedef uint8 Dem_Cfg_DataElementTableCol2ElmtIndEndIdxOfDataCollectionTableType;


typedef uint8 Dem_Cfg_DataElementTableCol2ElmtIndStartIdxOfDataCollectionTableType;


typedef boolean Dem_Cfg_DataElementTableCol2ElmtIndUsedOfDataCollectionTableType;


typedef uint8 Dem_Cfg_DidOffsetFastOfDataCollectionTableType;


typedef uint8 Dem_Cfg_DidOffsetNormalOfDataCollectionTableType;


typedef uint8 Dem_Cfg_EventTable_ERec2EventIdIndEndIdxOfDataCollectionTableType;


typedef uint8 Dem_Cfg_EventTable_ERec2EventIdIndStartIdxOfDataCollectionTableType;


typedef boolean Dem_Cfg_EventTable_ERec2EventIdIndUsedOfDataCollectionTableType;


typedef uint16 Dem_Cfg_IdNumberOfDataCollectionTableType;


typedef uint8 Dem_Cfg_StorageKindOfDataCollectionTableType;


typedef uint16 Dem_Cfg_TriggerOfDataCollectionTableType;


typedef boolean Dem_Cfg_UpdateOfDataCollectionTableType;


typedef uint8 Dem_Cfg_DataCollectionTableEdr2CollIndType;


typedef uint8 Dem_Cfg_DataCollectionTableErec2CollIndType;


typedef uint8 Dem_Cfg_DataCollectionTableFfm2CollIndType;


typedef uint8 Dem_Cfg_DataCollectionTableJ19392CollIndType;


typedef uint8 Dem_Cfg_DataCollectionTablePid2CollIndType;


typedef boolean Dem_Cfg_DataIsStoredInNVOfDataElementTableType;


typedef uint8 Dem_Cfg_ElementKindOfDataElementTableType;


typedef uint8 Dem_Cfg_ElementSizeOfDataElementTableType;


typedef uint8 Dem_Cfg_DataElementTableCol2ElmtIndType;


typedef uint8 Dem_Cfg_DebounceHiResTableType;


typedef uint8 Dem_Cfg_DebounceLoResTableType;


typedef boolean Dem_Cfg_DebounceContinuousOfDebounceTableType;


typedef sint8 Dem_Cfg_DecrementStepSizeOfDebounceTableType;


typedef uint8 Dem_Cfg_EventDebounceAlgorithmOfDebounceTableType;


typedef boolean Dem_Cfg_EventDebounceBehaviorOfDebounceTableType;


typedef sint16 Dem_Cfg_FailTimerCyclesOfDebounceTableType;


typedef sint8 Dem_Cfg_FailedThresholdOfDebounceTableType;


typedef sint8 Dem_Cfg_IncrementStepSizeOfDebounceTableType;


typedef boolean Dem_Cfg_JumpDownOfDebounceTableType;


typedef sint8 Dem_Cfg_JumpDownValueOfDebounceTableType;


typedef boolean Dem_Cfg_JumpUpOfDebounceTableType;


typedef sint8 Dem_Cfg_JumpUpValueOfDebounceTableType;


typedef uint8 Dem_Cfg_MaskedBitsOfDebounceTableType;


typedef sint8 Dem_Cfg_PassTimerCyclesOfDebounceTableType;


typedef sint8 Dem_Cfg_PassedThresholdOfDebounceTableType;


typedef uint8 Dem_Cfg_PreconfirmedThresholdOfDebounceTableType;


typedef boolean Dem_Cfg_StorageOfDebounceTableType;


typedef uint8 Dem_Cfg_StorageThresholdOfDebounceTableType;


typedef sint8 Dem_Cfg_StorageTimerCyclesOfDebounceTableType;


typedef uint8 Dem_Cfg_GroupMaskOfDtcGroupMaskType;


typedef uint8 Dem_Cfg_UdsGroupDtcOfDtcGroupMaskType;


typedef uint8 Dem_Cfg_DtcSeverityOfDtcTableType;


typedef uint8 Dem_Cfg_FunctionalUnitOfDtcTableType;


typedef boolean Dem_Cfg_ImmediateNvStorageOfDtcTableType;


typedef uint8 Dem_Cfg_J1939DtcOfDtcTableType;


typedef uint8 Dem_Cfg_J1939NodeIdIndEndIdxOfDtcTableType;


typedef uint8 Dem_Cfg_J1939NodeIdIndStartIdxOfDtcTableType;


typedef boolean Dem_Cfg_J1939NodeIdIndUsedOfDtcTableType;


typedef uint8 Dem_Cfg_ObdDtcOfDtcTableType;


typedef uint32 Dem_Cfg_UdsDtcOfDtcTableType;


typedef float32 Dem_Cfg_DivisorOfDtrTableType;


typedef uint8 Dem_Cfg_EventTableIdxOfDtrTableType;


typedef float32 Dem_Cfg_LinearFactorOfDtrTableType;


typedef float32 Dem_Cfg_OffsetOfDtrTableType;


typedef uint8 Dem_Cfg_UasidOfDtrTableType;


typedef uint8 Dem_Cfg_UpdateKindOfDtrTableType;


typedef uint8 Dem_Cfg_DtrTableIndType;


typedef boolean Dem_Cfg_EnableConditionFulfilledType;


typedef uint8 Dem_Cfg_EnableConditionGroupCounterType;


typedef uint8 Dem_Cfg_EnableConditionGroupStateType;


typedef uint8 Dem_Cfg_IndexOfEnableConditionGroupTableType;


typedef uint8 Dem_Cfg_EnableConditionGroupTableIndType;


typedef boolean Dem_Cfg_FulfilledAtInitOfEnableConditionInitTableType;


typedef uint8 Dem_Cfg_EnableConditionGroupTableIndEndIdxOfEnableConditionTableType;


typedef uint8 Dem_Cfg_EnableConditionGroupTableIndStartIdxOfEnableConditionTableType;


typedef boolean Dem_Cfg_EnableConditionGroupTableIndUsedOfEnableConditionTableType;


typedef boolean Dem_Cfg_EventAvailableDefaultType;


typedef boolean Dem_Cfg_EventAvailableInVariantType;


typedef uint8 Dem_Cfg_EventCycleStatusType;


typedef uint8 Dem_Cfg_EventDataCommitNumberType;


typedef sint16 Dem_Cfg_EventDebounceValueType;


typedef boolean Dem_Cfg_AgingAllowedOfEventTableType;


typedef uint8 Dem_Cfg_AgingCycleCounterThresholdOfEventTableType;


typedef uint8 Dem_Cfg_AgingCycleIdOfEventTableType;


typedef uint8 Dem_Cfg_CallbackGetFdcIdxOfEventTableType;


typedef uint8 Dem_Cfg_DebounceTableIdxOfEventTableType;


typedef uint8 Dem_Cfg_DtcTableIdxOfEventTableType;


typedef uint8 Dem_Cfg_DtrTableIndEndIdxOfEventTableType;


typedef uint8 Dem_Cfg_DtrTableIndStartIdxOfEventTableType;


typedef boolean Dem_Cfg_DtrTableIndUsedOfEventTableType;


typedef uint8 Dem_Cfg_EnableConditionGroupTableIdxOfEventTableType;


typedef uint8 Dem_Cfg_EventDestinationOfEventTableType;


typedef uint8 Dem_Cfg_EventFailureCycleCounterThresholdOfEventTableType;


typedef uint8 Dem_Cfg_EventKindOfEventTableType;


typedef boolean Dem_Cfg_EventLatchTFOfEventTableType;


typedef uint8 Dem_Cfg_EventPriorityOfEventTableType;


typedef uint8 Dem_Cfg_EventSignificanceOfEventTableType;


typedef uint8 Dem_Cfg_ExtendedDataTableIdxOfEventTableType;


typedef uint8 Dem_Cfg_FailedCycleCounterIndexOfEventTableType;


typedef uint8 Dem_Cfg_FaultPendingCounterIndexOfEventTableType;


typedef uint8 Dem_Cfg_FreezeFrameNumTableEndIdxOfEventTableType;


typedef uint8 Dem_Cfg_FreezeFrameNumTableStartIdxOfEventTableType;


typedef boolean Dem_Cfg_FreezeFrameNumTableUsedOfEventTableType;


typedef uint8 Dem_Cfg_FreezeFrameTableStdFFIdxOfEventTableType;


typedef uint8 Dem_Cfg_HealingTargetOfEventTableType;


typedef uint8 Dem_Cfg_InitMonitorForEventIdxOfEventTableType;


typedef boolean Dem_Cfg_InitMonitorForEventUsedOfEventTableType;


typedef uint8 Dem_Cfg_MaskedBitsOfEventTableType;


typedef uint8 Dem_Cfg_NormalIndicatorTableEndIdxOfEventTableType;


typedef uint8 Dem_Cfg_NormalIndicatorTableStartIdxOfEventTableType;


typedef boolean Dem_Cfg_NormalIndicatorTableUsedOfEventTableType;


typedef boolean Dem_Cfg_OBDVisibilityDelayedUntilDcyQualificationOfEventTableType;


typedef uint8 Dem_Cfg_OperationCycleIdOfEventTableType;


typedef uint8 Dem_Cfg_SatelliteEventIdxOfEventTableType;


typedef uint8 Dem_Cfg_SatelliteInfoIdxOfEventTableType;


typedef uint8 Dem_Cfg_SpecialIndicatorTableEndIdxOfEventTableType;


typedef uint8 Dem_Cfg_SpecialIndicatorTableStartIdxOfEventTableType;


typedef boolean Dem_Cfg_SpecialIndicatorTableUsedOfEventTableType;


typedef uint8 Dem_Cfg_EventTableIndType;


typedef uint8 Dem_Cfg_EventTable_ERec2EventIdIndType;


typedef uint8 Dem_Cfg_EventTable_ObdRdyGroup2EventIdIndType;


typedef uint8 Dem_Cfg_DataCollectionTableErec2CollIndEndIdxOfExtendedDataRecordTableType;


typedef uint8 Dem_Cfg_DataCollectionTableErec2CollIndStartIdxOfExtendedDataRecordTableType;


typedef boolean Dem_Cfg_DataCollectionTableErec2CollIndUsedOfExtendedDataRecordTableType;


typedef uint8 Dem_Cfg_DataCollectionTableEdr2CollIndEndIdxOfExtendedDataTableType;


typedef uint8 Dem_Cfg_DataCollectionTableEdr2CollIndStartIdxOfExtendedDataTableType;


typedef boolean Dem_Cfg_DataCollectionTableEdr2CollIndUsedOfExtendedDataTableType;


typedef uint8 Dem_Cfg_MaxRecordSizeOfExtendedDataTableType;


typedef uint8 Dem_Cfg_FilterReportedEventsType;


typedef uint16 Dem_Cfg_FinalMagicNumberType;


typedef uint8 Dem_Cfg_FFNumberOfFreezeFrameNumTableType;


typedef uint16 Dem_Cfg_FFTriggerOfFreezeFrameNumTableType;


typedef boolean Dem_Cfg_FFUpdateOfFreezeFrameNumTableType;


typedef uint8 Dem_Cfg_DataCollectionTableFfm2CollIndEndIdxOfFreezeFrameTableType;


typedef uint8 Dem_Cfg_DataCollectionTableFfm2CollIndStartIdxOfFreezeFrameTableType;


typedef boolean Dem_Cfg_DataCollectionTableFfm2CollIndUsedOfFreezeFrameTableType;


typedef uint8 Dem_Cfg_RecordSizeOfFreezeFrameTableType;


typedef uint8 Dem_Cfg_RecordSizeUdsOfFastRateTimeSeriesPowertrainOfFreezeFrameTableType;


typedef uint8 Dem_Cfg_RecordSizeUdsOfFreezeFrameTableType;


typedef uint8 Dem_Cfg_RecordSizeUdsOfNormalRateTimeSeriesPowertrainOfFreezeFrameTableType;


typedef uint8 Dem_Cfg_DataCollectionTableJ19392CollIndEndIdxOfGeneralJ1939TableType;


typedef uint8 Dem_Cfg_DataCollectionTableJ19392CollIndStartIdxOfGeneralJ1939TableType;


typedef boolean Dem_Cfg_DataCollectionTableJ19392CollIndUsedOfGeneralJ1939TableType;


typedef uint8 Dem_Cfg_RecordSizeOfGeneralJ1939TableType;


typedef uint8 Dem_Cfg_DataElementTableIdxOfGeneralObdInputType;


typedef uint8 Dem_Cfg_GlobalObdRequirementsType;


typedef uint8 Dem_Cfg_GlobalSeverityMaskType;


typedef sint32 Dem_Cfg_InitDataHashCodeType;


typedef uint8 Dem_Cfg_J1939NodeIdType;


typedef uint8 Dem_Cfg_J1939NodeIdIndType;


typedef uint8 Dem_Cfg_J1939NodeIndicatorType;


typedef uint16 Dem_Cfg_MemoryBlockIdType;


typedef uint16 Dem_Cfg_MemoryDataSizeType;


typedef uint8 Dem_Cfg_MemoryStatusType;


typedef uint8 Dem_Cfg_DtrTableIdxOfMidTableType;


typedef uint8 Dem_Cfg_MidOfMidTableType;


typedef uint8 Dem_Cfg_TidOfMidTableType;


typedef uint8 Dem_Cfg_MirrorDataType;


typedef uint8 Dem_Cfg_BehaviorOfNormalIndicatorTableType;


typedef uint8 Dem_Cfg_IdOfNormalIndicatorTableType;


typedef boolean Dem_Cfg_ObdIumprUpdatePendingType;


typedef uint8 Dem_Cfg_DataCollectionTablePid2CollIndEndIdxOfPidTableType;


typedef uint8 Dem_Cfg_DataCollectionTablePid2CollIndStartIdxOfPidTableType;


typedef boolean Dem_Cfg_DataCollectionTablePid2CollIndUsedOfPidTableType;


typedef uint8 Dem_Cfg_EventTable_ObdRdyGroup2EventIdIndEndIdxOfReadinessGroupTableType;


typedef uint8 Dem_Cfg_EventTable_ObdRdyGroup2EventIdIndStartIdxOfReadinessGroupTableType;


typedef boolean Dem_Cfg_EventTable_ObdRdyGroup2EventIdIndUsedOfReadinessGroupTableType;


typedef uint8 Dem_Cfg_ReadinessGroupOfReadinessGroupTableType;


typedef uint8 Dem_Cfg_EventCountOfSatelliteInfoType;


typedef uint8 Dem_Cfg_EventTableIndEndIdxOfSatelliteInfoType;


typedef uint8 Dem_Cfg_EventTableIndStartIdxOfSatelliteInfoType;


typedef boolean Dem_Cfg_EventTableIndUsedOfSatelliteInfoType;


typedef uint8 Dem_Cfg_DebounceHiResTableEndIdxOfSatelliteTimeDebounceInfoType;


typedef uint8 Dem_Cfg_DebounceHiResTableStartIdxOfSatelliteTimeDebounceInfoType;


typedef boolean Dem_Cfg_DebounceHiResTableUsedOfSatelliteTimeDebounceInfoType;


typedef uint8 Dem_Cfg_DebounceLoResTableEndIdxOfSatelliteTimeDebounceInfoType;


typedef uint8 Dem_Cfg_DebounceLoResTableStartIdxOfSatelliteTimeDebounceInfoType;


typedef boolean Dem_Cfg_DebounceLoResTableUsedOfSatelliteTimeDebounceInfoType;


typedef uint8 Dem_Cfg_SizeOfCallbackClearEventAllowedType;


typedef uint8 Dem_Cfg_SizeOfCallbackDtcStatusChangedType;


typedef uint8 Dem_Cfg_SizeOfCallbackGetFdcType;


typedef uint8 Dem_Cfg_SizeOfCallbackJ1939DtcStatusChangedType;


typedef uint8 Dem_Cfg_SizeOfClearDTCTableType;


typedef uint8 Dem_Cfg_SizeOfClearDtcNotificationFinishTableType;


typedef uint8 Dem_Cfg_SizeOfClearDtcNotificationStartTableType;


typedef uint8 Dem_Cfg_SizeOfClientTableType;


typedef uint8 Dem_Cfg_SizeOfDTCSelectorTableType;


typedef uint8 Dem_Cfg_SizeOfDataElementTableType;


typedef uint8 Dem_Cfg_SizeOfDebounceHiResTableType;


typedef uint8 Dem_Cfg_SizeOfDebounceLoResTableType;


typedef uint8 Dem_Cfg_SizeOfDtcGroupMaskType;


typedef uint8 Dem_Cfg_SizeOfDtrStatusType;


typedef uint8 Dem_Cfg_SizeOfDtrTableType;


typedef uint8 Dem_Cfg_SizeOfEnableConditionFulfilledType;


typedef uint8 Dem_Cfg_SizeOfEnableConditionGroupCounterType;


typedef uint8 Dem_Cfg_SizeOfEnableConditionGroupStateType;


typedef uint8 Dem_Cfg_SizeOfEnableConditionGroupTableType;


typedef uint8 Dem_Cfg_SizeOfEnableConditionTableType;


typedef uint8 Dem_Cfg_SizeOfEventCycleStatusType;


typedef uint8 Dem_Cfg_SizeOfEventDataChangedType;


typedef uint8 Dem_Cfg_SizeOfEventDataCommitNumberType;


typedef uint8 Dem_Cfg_SizeOfEventDebounceValueType;


typedef uint8 Dem_Cfg_SizeOfEventInternalStatusType;


typedef uint8 Dem_Cfg_SizeOfEventStatusChangedType;


typedef uint8 Dem_Cfg_SizeOfEventTableType;


typedef uint8 Dem_Cfg_SizeOfExtendedDataRecordIteratorTableType;


typedef uint8 Dem_Cfg_SizeOfFilterInfoTableType;


typedef uint8 Dem_Cfg_SizeOfFilterReportedEventsType;


typedef uint8 Dem_Cfg_SizeOfFreezeFrameIteratorTableType;


typedef uint8 Dem_Cfg_SizeOfGlobalIndicatorStatesType;


typedef uint8 Dem_Cfg_SizeOfIndicatorBlinkingType;


typedef uint8 Dem_Cfg_SizeOfIndicatorContinuousType;


typedef uint8 Dem_Cfg_SizeOfIndicatorFastFlashType;


typedef uint8 Dem_Cfg_SizeOfIndicatorSlowFlashType;


typedef uint8 Dem_Cfg_SizeOfInitMonitorForEventType;


typedef uint8 Dem_Cfg_SizeOfInitMonitorsForFuncType;


typedef uint8 Dem_Cfg_SizeOfMemoryBlockIdToMemoryEntryIdType;


typedef uint8 Dem_Cfg_SizeOfMemoryEntryType;


typedef uint8 Dem_Cfg_SizeOfMemoryStatusType;


typedef uint8 Dem_Cfg_SizeOfObdIumprUpdatePendingType;


typedef uint8 Dem_Cfg_SizeOfPrestorageIndexType;


typedef uint8 Dem_Cfg_SizeOfPrimaryChronologyType;


typedef uint8 Dem_Cfg_SizeOfReadinessGroupTableType;


typedef uint8 Dem_Cfg_SizeOfReadoutBufferType;


typedef uint8 Dem_Cfg_SizeOfReportedEventsOfFilterType;


typedef uint8 Dem_Cfg_SizeOfSatelliteInfoType;


typedef uint8 Dem_Cfg_SizeOfSecondaryChronologyType;


typedef uint8 Dem_Cfg_SizeOfSpecialIndicatorTableType;


typedef uint8 Dem_Cfg_SizeOfStartIdx500miDenRatioTableType;


typedef uint8 Dem_Cfg_SizeOfStorageConditionFulfilledType;


typedef uint8 Dem_Cfg_SizeOfStorageConditionGroupCounterType;


typedef uint8 Dem_Cfg_SizeOfStorageConditionGroupTableType;


typedef uint8 Dem_Cfg_SizeOfStorageConditionTableType;


typedef uint8 Dem_Cfg_SizeOfSupportedMidsTableType;


typedef uint8 Dem_Cfg_SizeOfTimeSeriesChronologyType;


typedef uint8 Dem_Cfg_BehaviorOfSpecialIndicatorTableType;


typedef uint8 Dem_Cfg_IdOfSpecialIndicatorTableType;


typedef boolean Dem_Cfg_StorageConditionFulfilledType;


typedef uint8 Dem_Cfg_StorageConditionGroupCounterType;


typedef uint8 Dem_Cfg_IndexOfStorageConditionGroupTableType;


typedef uint8 Dem_Cfg_StorageConditionGroupTableIndType;


typedef boolean Dem_Cfg_FulfilledAtInitOfStorageConditionInitTableType;


typedef uint8 Dem_Cfg_StorageConditionGroupTableIndEndIdxOfStorageConditionTableType;


typedef uint8 Dem_Cfg_StorageConditionGroupTableIndStartIdxOfStorageConditionTableType;


typedef boolean Dem_Cfg_StorageConditionGroupTableIndUsedOfStorageConditionTableType;


typedef uint8 Dem_Cfg_StartIdxMidTableOfSupportedMidsTableType;


typedef uint8 Dem_Cfg_SupportedMidMaskOfSupportedMidsTableType;


typedef boolean Dem_Cfg_UseOBDIIInVariantType;


typedef boolean Dem_Cfg_UsePermanentInVariantType;


typedef boolean Dem_Cfg_UseWWHOBDInVariantType;
# 4486 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
typedef struct sDem_Cfg_ClientTableType
{
 uint8 Dem_Cfg_ClientTableNeverUsed;
} Dem_Cfg_ClientTableType;


typedef struct sDem_Cfg_CycleIdTableType
{
 Dem_Cfg_OpCycleTypeOfCycleIdTableType OpCycleTypeOfCycleIdTable;
} Dem_Cfg_CycleIdTableType;


typedef struct sDem_Cfg_DataCollectionTableType
{
 Dem_Cfg_IdNumberOfDataCollectionTableType IdNumberOfDataCollectionTable;
 Dem_Cfg_TriggerOfDataCollectionTableType TriggerOfDataCollectionTable;
 Dem_Cfg_CollectionSizeOfDataCollectionTableType CollectionSizeOfDataCollectionTable;
 Dem_Cfg_DataElementTableCol2ElmtIndEndIdxOfDataCollectionTableType DataElementTableCol2ElmtIndEndIdxOfDataCollectionTable;
 Dem_Cfg_DataElementTableCol2ElmtIndStartIdxOfDataCollectionTableType DataElementTableCol2ElmtIndStartIdxOfDataCollectionTable;
 Dem_Cfg_StorageKindOfDataCollectionTableType StorageKindOfDataCollectionTable;
} Dem_Cfg_DataCollectionTableType;


typedef struct sDem_Cfg_DataElementTableType
{
 Dem_Cfg_ElementKindOfDataElementTableType ElementKindOfDataElementTable;
 Dem_Cfg_ElementSizeOfDataElementTableType ElementSizeOfDataElementTable;
 Dem_ReadDataFPtrType ReadDataFuncOfDataElementTable;
} Dem_Cfg_DataElementTableType;


typedef struct sDem_Cfg_DebounceTableType
{
 Dem_Cfg_FailTimerCyclesOfDebounceTableType FailTimerCyclesOfDebounceTable;
 Dem_Cfg_DecrementStepSizeOfDebounceTableType DecrementStepSizeOfDebounceTable;
 Dem_Cfg_FailedThresholdOfDebounceTableType FailedThresholdOfDebounceTable;
 Dem_Cfg_IncrementStepSizeOfDebounceTableType IncrementStepSizeOfDebounceTable;
 Dem_Cfg_PassTimerCyclesOfDebounceTableType PassTimerCyclesOfDebounceTable;
 Dem_Cfg_PassedThresholdOfDebounceTableType PassedThresholdOfDebounceTable;
 Dem_Cfg_EventDebounceAlgorithmOfDebounceTableType EventDebounceAlgorithmOfDebounceTable;
 Dem_Cfg_MaskedBitsOfDebounceTableType MaskedBitsOfDebounceTable;
} Dem_Cfg_DebounceTableType;


typedef struct sDem_Cfg_DtcGroupMaskType
{
 uint8 Dem_Cfg_DtcGroupMaskNeverUsed;
} Dem_Cfg_DtcGroupMaskType;


typedef struct sDem_Cfg_DtcTableType
{
 Dem_Cfg_UdsDtcOfDtcTableType UdsDtcOfDtcTable;
 Dem_Cfg_DtcSeverityOfDtcTableType DtcSeverityOfDtcTable;
 Dem_Cfg_FunctionalUnitOfDtcTableType FunctionalUnitOfDtcTable;
} Dem_Cfg_DtcTableType;


typedef struct sDem_Cfg_DtrTableType
{
 uint8 Dem_Cfg_DtrTableNeverUsed;
} Dem_Cfg_DtrTableType;


typedef struct sDem_Cfg_EnableConditionGroupTableType
{
 uint8 Dem_Cfg_EnableConditionGroupTableNeverUsed;
} Dem_Cfg_EnableConditionGroupTableType;


typedef struct sDem_Cfg_EnableConditionInitTableType
{
 Dem_Cfg_FulfilledAtInitOfEnableConditionInitTableType FulfilledAtInitOfEnableConditionInitTable;
} Dem_Cfg_EnableConditionInitTableType;


typedef struct sDem_Cfg_EnableConditionTableType
{
 Dem_Cfg_EnableConditionGroupTableIndEndIdxOfEnableConditionTableType EnableConditionGroupTableIndEndIdxOfEnableConditionTable;
 Dem_Cfg_EnableConditionGroupTableIndStartIdxOfEnableConditionTableType EnableConditionGroupTableIndStartIdxOfEnableConditionTable;
} Dem_Cfg_EnableConditionTableType;






typedef struct sDem_Cfg_EventTableType
{
 Dem_Cfg_AgingCycleCounterThresholdOfEventTableType AgingCycleCounterThresholdOfEventTable;
 Dem_Cfg_AgingCycleIdOfEventTableType AgingCycleIdOfEventTable;
 Dem_Cfg_DebounceTableIdxOfEventTableType DebounceTableIdxOfEventTable;
 Dem_Cfg_DtcTableIdxOfEventTableType DtcTableIdxOfEventTable;
 Dem_Cfg_EnableConditionGroupTableIdxOfEventTableType EnableConditionGroupTableIdxOfEventTable;
 Dem_Cfg_EventKindOfEventTableType EventKindOfEventTable;
 Dem_Cfg_EventPriorityOfEventTableType EventPriorityOfEventTable;
 Dem_Cfg_EventSignificanceOfEventTableType EventSignificanceOfEventTable;
 Dem_Cfg_ExtendedDataTableIdxOfEventTableType ExtendedDataTableIdxOfEventTable;
 Dem_Cfg_FreezeFrameNumTableEndIdxOfEventTableType FreezeFrameNumTableEndIdxOfEventTable;
 Dem_Cfg_FreezeFrameNumTableStartIdxOfEventTableType FreezeFrameNumTableStartIdxOfEventTable;
 Dem_Cfg_FreezeFrameTableStdFFIdxOfEventTableType FreezeFrameTableStdFFIdxOfEventTable;
 Dem_Cfg_InitMonitorForEventIdxOfEventTableType InitMonitorForEventIdxOfEventTable;
 Dem_Cfg_MaskedBitsOfEventTableType MaskedBitsOfEventTable;
 Dem_Cfg_NormalIndicatorTableEndIdxOfEventTableType NormalIndicatorTableEndIdxOfEventTable;
 Dem_Cfg_NormalIndicatorTableStartIdxOfEventTableType NormalIndicatorTableStartIdxOfEventTable;
} Dem_Cfg_EventTableType;


typedef struct sDem_Cfg_ExtendedDataRecordTableType
{
 uint8 Dem_Cfg_ExtendedDataRecordTableNeverUsed;
} Dem_Cfg_ExtendedDataRecordTableType;


typedef struct sDem_Cfg_ExtendedDataTableType
{
 Dem_Cfg_DataCollectionTableEdr2CollIndEndIdxOfExtendedDataTableType DataCollectionTableEdr2CollIndEndIdxOfExtendedDataTable;
 Dem_Cfg_DataCollectionTableEdr2CollIndStartIdxOfExtendedDataTableType DataCollectionTableEdr2CollIndStartIdxOfExtendedDataTable;
 Dem_Cfg_MaxRecordSizeOfExtendedDataTableType MaxRecordSizeOfExtendedDataTable;
} Dem_Cfg_ExtendedDataTableType;


typedef struct sDem_Cfg_FreezeFrameNumTableType
{
 Dem_Cfg_FFTriggerOfFreezeFrameNumTableType FFTriggerOfFreezeFrameNumTable;
 Dem_Cfg_FFNumberOfFreezeFrameNumTableType FFNumberOfFreezeFrameNumTable;
} Dem_Cfg_FreezeFrameNumTableType;


typedef struct sDem_Cfg_FreezeFrameTableType
{
 Dem_Cfg_DataCollectionTableFfm2CollIndEndIdxOfFreezeFrameTableType DataCollectionTableFfm2CollIndEndIdxOfFreezeFrameTable;
 Dem_Cfg_DataCollectionTableFfm2CollIndStartIdxOfFreezeFrameTableType DataCollectionTableFfm2CollIndStartIdxOfFreezeFrameTable;
 Dem_Cfg_RecordSizeOfFreezeFrameTableType RecordSizeOfFreezeFrameTable;
 Dem_Cfg_RecordSizeUdsOfFreezeFrameTableType RecordSizeUdsOfFreezeFrameTable;
} Dem_Cfg_FreezeFrameTableType;


typedef struct sDem_Cfg_GeneralJ1939TableType
{
 uint8 Dem_Cfg_GeneralJ1939TableNeverUsed;
} Dem_Cfg_GeneralJ1939TableType;


typedef struct sDem_Cfg_GeneralObdInputType
{
 uint8 Dem_Cfg_GeneralObdInputNeverUsed;
} Dem_Cfg_GeneralObdInputType;


typedef struct sDem_Cfg_InitMonListForFuncType
{
 uint8 Dem_Cfg_InitMonListForFuncNeverUsed;
} Dem_Cfg_InitMonListForFuncType;


typedef struct sDem_Cfg_MidTableType
{
 uint8 Dem_Cfg_MidTableNeverUsed;
} Dem_Cfg_MidTableType;


typedef struct sDem_Cfg_NormalIndicatorTableType
{
 uint8 Dem_Cfg_NormalIndicatorTableNeverUsed;
} Dem_Cfg_NormalIndicatorTableType;


typedef struct sDem_Cfg_PidTableType
{
 uint8 Dem_Cfg_PidTableNeverUsed;
} Dem_Cfg_PidTableType;


typedef struct sDem_Cfg_RatioIdTableType
{
 uint8 Dem_Cfg_RatioIdTableNeverUsed;
} Dem_Cfg_RatioIdTableType;


typedef struct sDem_Cfg_ReadinessGroupTableType
{
 uint8 Dem_Cfg_ReadinessGroupTableNeverUsed;
} Dem_Cfg_ReadinessGroupTableType;


typedef struct sDem_Cfg_SatelliteInfoType
{
 uint8 Dem_Cfg_SatelliteInfoNeverUsed;
} Dem_Cfg_SatelliteInfoType;


typedef struct sDem_Cfg_SatelliteTimeDebounceInfoType
{
 uint8 Dem_Cfg_SatelliteTimeDebounceInfoNeverUsed;
} Dem_Cfg_SatelliteTimeDebounceInfoType;


typedef struct sDem_Cfg_SpecialIndicatorTableType
{
 uint8 Dem_Cfg_SpecialIndicatorTableNeverUsed;
} Dem_Cfg_SpecialIndicatorTableType;


typedef struct sDem_Cfg_StartIdx500miDenRatioTableType
{
 uint8 Dem_Cfg_StartIdx500miDenRatioTableNeverUsed;
} Dem_Cfg_StartIdx500miDenRatioTableType;


typedef struct sDem_Cfg_StorageConditionGroupTableType
{
 uint8 Dem_Cfg_StorageConditionGroupTableNeverUsed;
} Dem_Cfg_StorageConditionGroupTableType;


typedef struct sDem_Cfg_StorageConditionInitTableType
{
 uint8 Dem_Cfg_StorageConditionInitTableNeverUsed;
} Dem_Cfg_StorageConditionInitTableType;


typedef struct sDem_Cfg_StorageConditionTableType
{
 uint8 Dem_Cfg_StorageConditionTableNeverUsed;
} Dem_Cfg_StorageConditionTableType;


typedef struct sDem_Cfg_SupportedMidsTableType
{
 uint8 Dem_Cfg_SupportedMidsTableNeverUsed;
} Dem_Cfg_SupportedMidsTableType;
# 4729 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
typedef Dem_Cfg_AdminDataType * Dem_Cfg_AdminDataPtrType;


typedef Dem_Cfg_AgingDataType * Dem_Cfg_AgingDataPtrType;


typedef const Dem_ClearEventAllowedFPtrType * Dem_Cfg_CallbackClearEventAllowedPtrType;


typedef const Dem_DtcStatusChangedFPtrType * Dem_Cfg_CallbackDtcStatusChangedPtrType;


typedef const Dem_GetFDCFPtrType * Dem_Cfg_CallbackGetFdcPtrType;


typedef const Dem_DtcStatusChangedFPtrType * Dem_Cfg_CallbackJ1939DtcStatusChangedPtrType;


typedef Dem_ClearDTC_DataType * Dem_Cfg_ClearDTCTablePtrType;


typedef const Dem_ClearDtcNotificationFPtrType * Dem_Cfg_ClearDtcNotificationFinishTablePtrType;


typedef const Dem_ClearDtcNotificationFPtrType * Dem_Cfg_ClearDtcNotificationStartTablePtrType;


typedef const Dem_Cfg_ClientTableType * Dem_Cfg_ClientTablePtrType;


typedef Dem_Cfg_CommitBufferType * Dem_Cfg_CommitBufferPtrType;


typedef Dem_Cfg_CycleCounterDataType * Dem_Cfg_CycleCounterDataPtrType;


typedef const Dem_Cfg_CycleIdTableType * Dem_Cfg_CycleIdTablePtrType;


typedef Dem_DTCSelector_DataType * Dem_Cfg_DTCSelectorTablePtrType;


typedef const Dem_Cfg_DataCollectionTableType * Dem_Cfg_DataCollectionTablePtrType;


typedef const Dem_Cfg_DataCollectionTableEdr2CollIndType * Dem_Cfg_DataCollectionTableEdr2CollIndPtrType;


typedef const Dem_Cfg_DataCollectionTableErec2CollIndType * Dem_Cfg_DataCollectionTableErec2CollIndPtrType;


typedef const Dem_Cfg_DataCollectionTableFfm2CollIndType * Dem_Cfg_DataCollectionTableFfm2CollIndPtrType;


typedef const Dem_Cfg_DataCollectionTableJ19392CollIndType * Dem_Cfg_DataCollectionTableJ19392CollIndPtrType;


typedef const Dem_Cfg_DataCollectionTablePid2CollIndType * Dem_Cfg_DataCollectionTablePid2CollIndPtrType;


typedef const Dem_ReadDataFPtrType * Dem_Cfg_ReadDataFuncOfDataElementTablePtrType;


typedef const Dem_Cfg_DataElementTableType * Dem_Cfg_DataElementTablePtrType;


typedef const Dem_Cfg_DataElementTableCol2ElmtIndType * Dem_Cfg_DataElementTableCol2ElmtIndPtrType;


typedef Dem_Cfg_DebounceDataType * Dem_Cfg_DebounceDataPtrType;


typedef const Dem_Cfg_DebounceHiResTableType * Dem_Cfg_DebounceHiResTablePtrType;


typedef const Dem_Cfg_DebounceLoResTableType * Dem_Cfg_DebounceLoResTablePtrType;


typedef const Dem_Cfg_DebounceTableType * Dem_Cfg_DebounceTablePtrType;


typedef const Dem_Cfg_DtcGroupMaskType * Dem_Cfg_DtcGroupMaskPtrType;


typedef const Dem_Cfg_DtcTableType * Dem_Cfg_DtcTablePtrType;


typedef Dem_Cfg_DtrDataType * Dem_Cfg_DtrDataPtrType;


typedef volatile Dem_Cfg_DtrStatusType * Dem_Cfg_DtrStatusPtrType;


typedef const Dem_Cfg_DtrTableType * Dem_Cfg_DtrTablePtrType;


typedef const Dem_Cfg_DtrTableIndType * Dem_Cfg_DtrTableIndPtrType;


typedef Dem_Cfg_EnableConditionFulfilledType * Dem_Cfg_EnableConditionFulfilledPtrType;


typedef Dem_Cfg_EnableConditionGroupCounterType * Dem_Cfg_EnableConditionGroupCounterPtrType;


typedef volatile Dem_Cfg_EnableConditionGroupStateType * Dem_Cfg_EnableConditionGroupStatePtrType;


typedef const Dem_Cfg_EnableConditionGroupTableType * Dem_Cfg_EnableConditionGroupTablePtrType;


typedef const Dem_Cfg_EnableConditionGroupTableIndType * Dem_Cfg_EnableConditionGroupTableIndPtrType;


typedef const Dem_Cfg_EnableConditionInitTableType * Dem_Cfg_EnableConditionInitTablePtrType;


typedef const Dem_Cfg_EnableConditionTableType * Dem_Cfg_EnableConditionTablePtrType;


typedef Dem_Cfg_EventAvailableDataType * Dem_Cfg_EventAvailableDataPtrType;


typedef const Dem_Cfg_EventAvailableDefaultType * Dem_Cfg_EventAvailableDefaultPtrType;


typedef const Dem_Cfg_EventAvailableInVariantType * Dem_Cfg_EventAvailableInVariantPtrType;


typedef volatile Dem_Cfg_EventCycleStatusType * Dem_Cfg_EventCycleStatusPtrType;


typedef const Dem_EventDataChangedFPtrType * Dem_Cfg_EventDataChangedPtrType;


typedef volatile Dem_Cfg_EventDataCommitNumberType * Dem_Cfg_EventDataCommitNumberPtrType;


typedef volatile Dem_Cfg_EventDebounceValueType * Dem_Cfg_EventDebounceValuePtrType;


typedef volatile Dem_Event_InternalStatusType * Dem_Cfg_EventInternalStatusPtrType;


typedef const Dem_EventStatusChangedFPtrType * Dem_Cfg_EventStatusChangedPtrType;


typedef const Dem_Cfg_EventTableType * Dem_Cfg_EventTablePtrType;


typedef const Dem_Cfg_EventTableIndType * Dem_Cfg_EventTableIndPtrType;


typedef const Dem_Cfg_EventTable_ERec2EventIdIndType * Dem_Cfg_EventTable_ERec2EventIdIndPtrType;


typedef const Dem_Cfg_EventTable_ObdRdyGroup2EventIdIndType * Dem_Cfg_EventTable_ObdRdyGroup2EventIdIndPtrType;


typedef Dem_Cfg_ExtendedDataRecordIterator_FilterType * Dem_Cfg_ExtendedDataRecordIteratorTablePtrType;


typedef const Dem_Cfg_ExtendedDataRecordTableType * Dem_Cfg_ExtendedDataRecordTablePtrType;


typedef const Dem_Cfg_ExtendedDataTableType * Dem_Cfg_ExtendedDataTablePtrType;


typedef Dem_Cfg_FilterData_InfoType * Dem_Cfg_FilterInfoTablePtrType;


typedef Dem_Cfg_FilterReportedEventsType * Dem_Cfg_FilterReportedEventsPtrType;


typedef Dem_Cfg_FreezeFrameDataType * Dem_Cfg_FreezeFrameDataPtrType;


typedef Dem_Cfg_FreezeFrameIterator_FilterType * Dem_Cfg_FreezeFrameIteratorTablePtrType;


typedef const Dem_Cfg_FreezeFrameNumTableType * Dem_Cfg_FreezeFrameNumTablePtrType;


typedef const Dem_Cfg_FreezeFrameTableType * Dem_Cfg_FreezeFrameTablePtrType;


typedef const Dem_Cfg_GeneralJ1939TableType * Dem_Cfg_GeneralJ1939TablePtrType;


typedef const Dem_Cfg_GeneralObdInputType * Dem_Cfg_GeneralObdInputPtrType;


typedef Dem_Cfg_GlobalIndicatorStatesType * Dem_Cfg_GlobalIndicatorStatesPtrType;


typedef Dem_Cfg_IndicatorBlinkingType * Dem_Cfg_IndicatorBlinkingPtrType;


typedef Dem_Cfg_IndicatorContinuousType * Dem_Cfg_IndicatorContinuousPtrType;


typedef Dem_Cfg_IndicatorFastFlashType * Dem_Cfg_IndicatorFastFlashPtrType;


typedef Dem_Cfg_IndicatorSlowFlashType * Dem_Cfg_IndicatorSlowFlashPtrType;


typedef const Dem_Cfg_InitMonListForFuncType * Dem_Cfg_InitMonListForFuncPtrType;


typedef const Dem_InitMonitorForEventFPtrType * Dem_Cfg_InitMonitorForEventPtrType;


typedef const Dem_InitMonitorForFuncFPtrType * Dem_Cfg_InitMonitorsForFuncPtrType;


typedef const Dem_Cfg_J1939NodeIdType * Dem_Cfg_J1939NodeIdPtrType;


typedef const Dem_Cfg_J1939NodeIdIndType * Dem_Cfg_J1939NodeIdIndPtrType;


typedef const Dem_Cfg_J1939NodeIndicatorType * Dem_Cfg_J1939NodeIndicatorPtrType;


typedef const Dem_Cfg_MemoryBlockIdType * Dem_Cfg_MemoryBlockIdPtrType;


typedef const Dem_Cfg_MemoryEntryHandleType * Dem_Cfg_MemoryBlockIdToMemoryEntryIdPtrType;


typedef const Dem_NvDataPtrType * Dem_Cfg_MemoryDataPtrPtrType;


typedef const Dem_Cfg_MemoryDataSizeType * Dem_Cfg_MemoryDataSizePtrType;


typedef const Dem_SharedMemoryEntryPtrType * Dem_Cfg_MemoryEntryPtrType;


typedef const Dem_Cfg_PrimaryEntryType * Dem_Cfg_MemoryEntryInitPtrType;


typedef Dem_Cfg_MemoryStatusType * Dem_Cfg_MemoryStatusPtrType;


typedef const Dem_Cfg_MidTableType * Dem_Cfg_MidTablePtrType;


typedef Dem_Cfg_MirrorDataType * Dem_Cfg_MirrorDataPtrType;


typedef const Dem_Cfg_NormalIndicatorTableType * Dem_Cfg_NormalIndicatorTablePtrType;


typedef Dem_Cfg_ObdIumprDataType * Dem_Cfg_ObdIumprDataPtrType;


typedef Dem_Cfg_ObdIumprUpdatePendingType * Dem_Cfg_ObdIumprUpdatePendingPtrType;


typedef Dem_Cfg_PermanentDataType * Dem_Cfg_PermanentDataPtrType;


typedef const Dem_Cfg_PidTableType * Dem_Cfg_PidTablePtrType;


typedef Dem_Cfg_PrestorageType * Dem_Cfg_PrestoragePtrType;


typedef Dem_Cfg_PrestorageIndexType * Dem_Cfg_PrestorageIndexPtrType;


typedef Dem_Cfg_MemoryIndexType * Dem_Cfg_PrimaryChronologyPtrType;


typedef Dem_Cfg_PrimaryEntryType * Dem_Cfg_PrimaryEntry_0PtrType;


typedef const Dem_Cfg_RatioIdTableType * Dem_Cfg_RatioIdTablePtrType;


typedef const Dem_Cfg_ReadinessGroupTableType * Dem_Cfg_ReadinessGroupTablePtrType;


typedef Dem_Cfg_ReadoutBufferEntryType * Dem_Cfg_ReadoutBufferPtrType;


typedef Dem_Cfg_ReportedEventsType * Dem_Cfg_ReportedEventsOfFilterPtrType;


typedef const Dem_Cfg_SatelliteInfoType * Dem_Cfg_SatelliteInfoPtrType;


typedef Dem_Cfg_SatelliteInfoType0 * Dem_Cfg_SatelliteInfo0PtrType;


typedef const Dem_Cfg_SatelliteTimeDebounceInfoType * Dem_Cfg_SatelliteTimeDebounceInfoPtrType;


typedef Dem_Cfg_MemoryIndexType * Dem_Cfg_SecondaryChronologyPtrType;


typedef const Dem_Cfg_SpecialIndicatorTableType * Dem_Cfg_SpecialIndicatorTablePtrType;


typedef const Dem_Cfg_StartIdx500miDenRatioTableType * Dem_Cfg_StartIdx500miDenRatioTablePtrType;


typedef Dem_Cfg_StatusDataType * Dem_Cfg_StatusDataPtrType;


typedef Dem_Cfg_StorageConditionFulfilledType * Dem_Cfg_StorageConditionFulfilledPtrType;


typedef Dem_Cfg_StorageConditionGroupCounterType * Dem_Cfg_StorageConditionGroupCounterPtrType;


typedef const Dem_Cfg_StorageConditionGroupTableType * Dem_Cfg_StorageConditionGroupTablePtrType;


typedef const Dem_Cfg_StorageConditionGroupTableIndType * Dem_Cfg_StorageConditionGroupTableIndPtrType;


typedef const Dem_Cfg_StorageConditionInitTableType * Dem_Cfg_StorageConditionInitTablePtrType;


typedef const Dem_Cfg_StorageConditionTableType * Dem_Cfg_StorageConditionTablePtrType;


typedef const Dem_Cfg_SupportedMidsTableType * Dem_Cfg_SupportedMidsTablePtrType;


typedef Dem_Cfg_MemoryIndexType * Dem_Cfg_TimeSeriesChronologyPtrType;


typedef const Dem_Cfg_TimeSeriesEntryType * Dem_Cfg_TimeSeriesEntryInitPtrType;
# 5077 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
typedef struct sDem_PCConfigType
{
 uint8 Dem_PCConfigNeverUsed;
} Dem_PCConfigType;

typedef Dem_PCConfigType Dem_ConfigType;
# 5110 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5111 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_DtcStatusChangedFPtrType Dem_Cfg_CallbackDtcStatusChanged[1];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5116 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5129 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5130 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_CycleIdTableType Dem_Cfg_CycleIdTable[2];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5135 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5153 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5154 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_DataCollectionTableType Dem_Cfg_DataCollectionTable[5];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5159 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5170 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5171 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_DataCollectionTableFfm2CollIndType Dem_Cfg_DataCollectionTableFfm2CollInd[5];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5176 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5191 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5192 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_DataElementTableType Dem_Cfg_DataElementTable[9];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5197 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5208 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5209 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_DataElementTableCol2ElmtIndType Dem_Cfg_DataElementTableCol2ElmtInd[8];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5214 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5225 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5226 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_DebounceHiResTableType Dem_Cfg_DebounceHiResTable[6];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5231 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5251 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5252 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_DebounceTableType Dem_Cfg_DebounceTable[13];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5257 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5272 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5273 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_DtcTableType Dem_Cfg_DtcTable[37];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5278 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5289 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5290 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_EnableConditionGroupTableIndType Dem_Cfg_EnableConditionGroupTableInd[11];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5295 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5308 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5309 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_EnableConditionInitTableType Dem_Cfg_EnableConditionInitTable[7];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5314 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5329 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5330 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_EnableConditionTableType Dem_Cfg_EnableConditionTable[7];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5335 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5363 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5364 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_EventTableType Dem_Cfg_EventTable[41];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5369 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5384 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5385 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_ExtendedDataTableType Dem_Cfg_ExtendedDataTable[2];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5390 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5404 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5405 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_FreezeFrameNumTableType Dem_Cfg_FreezeFrameNumTable[2];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5410 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5426 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5427 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_FreezeFrameTableType Dem_Cfg_FreezeFrameTable[3];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5432 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5440 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_InitMonitorForEventFPtrType Dem_Cfg_InitMonitorForEvent[5];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5445 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5456 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5457 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_MemoryEntryHandleType Dem_Cfg_MemoryBlockIdToMemoryEntryId[3];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5462 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5473 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5474 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_NvDataPtrType Dem_Cfg_MemoryDataPtr[3];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5479 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5490 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5491 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_MemoryDataSizeType Dem_Cfg_MemoryDataSize[3];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5496 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5507 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5508 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_SharedMemoryEntryPtrType Dem_Cfg_MemoryEntry[2];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5513 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5521 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_PrimaryEntryType Dem_Cfg_MemoryEntryInit;
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5526 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5534 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern const Dem_Cfg_TimeSeriesEntryType Dem_Cfg_TimeSeriesEntryInit;
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5539 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5547 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_Cfg_AdminDataType Dem_Cfg_AdminData;
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5552 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5563 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5564 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_ClearDTC_DataType Dem_Cfg_ClearDTCTable[1];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5569 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5577 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_Cfg_CommitBufferType Dem_Cfg_CommitBuffer;
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5582 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5593 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5594 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_DTCSelector_DataType Dem_Cfg_DTCSelectorTable[1];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5599 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5610 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5611 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_Cfg_EnableConditionFulfilledType Dem_Cfg_EnableConditionFulfilled[7];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5616 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5627 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5628 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_Cfg_EnableConditionGroupCounterType Dem_Cfg_EnableConditionGroupCounter[6];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5633 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5644 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5645 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern volatile Dem_Cfg_EnableConditionGroupStateType Dem_Cfg_EnableConditionGroupState[6];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5650 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5661 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5662 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern volatile Dem_Cfg_EventDataCommitNumberType Dem_Cfg_EventDataCommitNumber[41];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5667 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5678 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5679 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern volatile Dem_Cfg_EventDebounceValueType Dem_Cfg_EventDebounceValue[41];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5684 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5695 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5696 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern volatile Dem_Event_InternalStatusType Dem_Cfg_EventInternalStatus[41];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5701 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5712 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5713 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_Cfg_ExtendedDataRecordIterator_FilterType Dem_Cfg_ExtendedDataRecordIteratorTable[1];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5718 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5729 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5730 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_Cfg_FilterData_InfoType Dem_Cfg_FilterInfoTable[1];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5735 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5746 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5747 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_Cfg_FilterReportedEventsType Dem_Cfg_FilterReportedEvents[6];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5752 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5763 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5764 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_Cfg_FreezeFrameIterator_FilterType Dem_Cfg_FreezeFrameIteratorTable[1];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5769 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5780 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5781 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_Cfg_GlobalIndicatorStatesType Dem_Cfg_GlobalIndicatorStates[1];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5786 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5797 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5798 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_Cfg_IndicatorBlinkingType Dem_Cfg_IndicatorBlinking[1];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5803 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5814 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5815 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_Cfg_IndicatorContinuousType Dem_Cfg_IndicatorContinuous[1];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5820 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5831 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5832 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_Cfg_MemoryStatusType Dem_Cfg_MemoryStatus[3];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5837 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5848 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5849 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_Cfg_MemoryIndexType Dem_Cfg_PrimaryChronology[1];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5854 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5862 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_Cfg_PrimaryEntryType Dem_Cfg_PrimaryEntry_0;
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5867 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5875 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_Cfg_ReadoutBufferEntryType Dem_Cfg_ReadoutBuffer[1];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5880 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5891 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5892 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_Cfg_ReportedEventsType Dem_Cfg_ReportedEventsOfFilter[1];
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5897 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 5908 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5909 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_Cfg_SatelliteInfoType0 Dem_Cfg_SatelliteInfo0;
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5914 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5922 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2

extern Dem_Cfg_StatusDataType Dem_Cfg_StatusData;
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5927 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_Lcfg.h" 2
# 631 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_PBcfg.h" 1
# 173 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_PBcfg.h"
typedef uint8 Dem_Cfg_LTConfigIdxOfPBConfigType;


typedef uint8 Dem_Cfg_PCConfigIdxOfPBConfigType;
# 192 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Dem_PBcfg.h"
typedef struct sDem_PBConfigType
{
 uint8 Dem_PBConfigNeverUsed;
} Dem_PBConfigType;
# 632 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Cfg_Macros.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_Validation.h" 1
# 644 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h" 2
# 840 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 841 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 849 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 857 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h" 2
# 884 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
void
Dem_SatellitePreInit(
 Dem_SatelliteInfoType SatelliteId
 );
# 917 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
void
Dem_SafePreInit(
 const Dem_ConfigType * ConfigPtr
 );
# 949 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
void
Dem_MasterPreInit(
 const Dem_ConfigType * ConfigPtr
 );
# 991 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
void
Dem_PreInit(
 const Dem_ConfigType * ConfigPtr
 );
# 1020 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
void
Dem_SatelliteInit(
 Dem_SatelliteInfoType SatelliteId
 );
# 1053 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
void
Dem_SafeInit(
 const Dem_ConfigType * ConfigPtr
 );
# 1087 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
void
Dem_MasterInit(
 const Dem_ConfigType * ConfigPtr
 );
# 1125 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
void
Dem_Init(
 const Dem_ConfigType * ConfigPtr
 );
# 1152 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
void
Dem_Shutdown(
 void
 );
# 1171 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
void
Dem_MasterMainFunction(
 void
 );
# 1195 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
void
Dem_SatelliteMainFunction(
 void
 );
# 1478 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_SetEnableCondition(
 uint8 EnableConditionID,
 boolean ConditionFulfilled
 );
# 1584 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
void
Dem_ReportErrorStatus(
 Dem_EventIdType EventId,
 Dem_EventStatusType EventStatus
 );
# 1654 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_SetEventStatus(
 Dem_EventIdType EventId,
 Dem_EventStatusType EventStatus
 );
# 1699 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_ResetEventStatus(
 Dem_EventIdType EventId
 );
# 1757 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_PrestoreFreezeFrame(
 Dem_EventIdType EventId
 );
# 1805 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_ClearPrestoredFreezeFrame(
 Dem_EventIdType EventId
 );
# 1866 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_ResetEventDebounceStatus(
 Dem_EventIdType EventId,
 Dem_DebounceResetStatusType DebounceResetStatus
 );
# 1898 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetDebouncingOfEvent(
 Dem_EventIdType EventId,
 Dem_DebouncingStateType * DebouncingState
 );
# 1962 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_SetOperationCycleState(
 uint8 OperationCycleId,
 Dem_OperationCycleStateType CycleState
 );
# 1995 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetOperationCycleState(
 uint8 OperationCycleId,
 Dem_OperationCycleStateType * CycleState
 );
# 2032 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetIndicatorStatus(
 uint8 IndicatorId,
 Dem_IndicatorStatusType * IndicatorStatus
 );
# 2175 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_SelectDTC(
 uint8 ClientId,
 uint32 DTC,
 Dem_DTCFormatType DTCFormat,
 Dem_DTCOriginType DTCOrigin
 );
# 2213 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetDTCSelectionResult(
 uint8 ClientId
 );
# 2250 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetMonitorStatus(
 Dem_EventIdType EventId,
 Dem_MonitorStatusType * MonitorStatus
 );
# 2297 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetEventUdsStatus(
 Dem_EventIdType EventId,
 Dem_UdsStatusByteType * UDSStatusByte
 );
# 2335 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetEventFailed(
 Dem_EventIdType EventId,
 boolean * EventFailed
 );
# 2373 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetEventTested(
 Dem_EventIdType EventId,
 boolean * EventTested
 );
# 2439 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetEventFreezeFrameDataEx(
 Dem_EventIdType EventId,
 uint8 RecordNumber,
 uint16 DataId,
 uint8 * DestBuffer,
 uint16 * BufSize
 );
# 2496 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetEventExtendedDataRecordEx(
 Dem_EventIdType EventId,
 uint8 RecordNumber,
 uint8 * DestBuffer,
 uint16 * BufSize
 );
# 2540 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetEventMemoryOverflow(
uint8 ClientId,
Dem_DTCOriginType DTCOrigin,
 boolean * OverflowIndication
);
# 2583 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetNumberOfEventMemoryEntries(
uint8 ClientId,
Dem_DTCOriginType DTCOrigin,
 uint8 * NumberOfEventMemoryEntries
);
# 2625 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetEventIdOfDTC(
 uint8 ClientId,
 Dem_EventIdType * EventId
 );
# 2679 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_ClearDTC(
 uint8 ClientId
 );
# 2720 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_SetDTR(
 uint16 DTRId,
 sint32 TestResult,
 sint32 LowerLimit,
 sint32 UpperLimit,
 Dem_DTRControlType Ctrlval
 );
# 2753 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_UpdateAvailableOBDMIDs(
 void
 );
# 2791 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetEventEnableCondition(
 Dem_EventIdType EventId,
 boolean * ConditionFulfilled
 );
# 2908 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
void
Dem_InitMemory(
 void
 );
# 2937 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
void
Dem_MainFunction(
 void
);
# 2971 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_SetEventDisabled(
 Dem_EventIdType EventId
 );
# 3017 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetDTCOfEvent(
 Dem_EventIdType EventId,
 Dem_DTCFormatType DTCFormat,
 uint32 * DTCOfEvent
 );
# 3061 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetFaultDetectionCounter(
 Dem_EventIdType EventId,
 sint8 * FaultDetectionCounter
 );
# 3103 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_RepIUMPRFaultDetect(
 Dem_RatioIdType RatioID
 );
# 3131 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_IUMPRLockNumerators(
 void
 );
# 3172 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_RepIUMPRDenLock(
 Dem_RatioIdType RatioID
 );
# 3211 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_RepIUMPRDenRelease(
 Dem_RatioIdType RatioID
 );
# 3247 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_SetIUMPRDenCondition(
 Dem_IumprDenomCondIdType ConditionId,
 Dem_IumprDenomCondStatusType ConditionStatus
 );
# 3286 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_SetIUMPRFilter(
 Dem_IumprReadinessGroupType IumprReadinessGroup,
 Dem_DTCOriginType DTCOrigin
 );
# 3314 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetNumberOfFilteredIUMPR(
 uint16 * NumberOfFilteredRatios
 );
# 3348 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetIUMPRGeneralData(
 uint16 * GeneralDenominator,
 uint16 * IgnitionCycles,
 uint16 * IgnitionCyclesHybrid
 );
# 3395 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetNextIUMPRRatioDataAndDTC(
 uint32 * UdsDtcNumber,
 uint16 * ObdDtcNumber,
 uint16 * Denominator,
 uint16 * Numerator
 );
# 3442 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetCurrentIUMPRRatioDataAndDTC(
 uint32 * UdsDtcNumber,
 uint16 * ObdDtcNumber,
 uint16 * Denominator,
 uint16 * Numerator
 );
# 3750 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_PostRunRequested(
 boolean * IsRequested
 );
# 3783 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_SetSI30Symptom(
 Dem_EventIdType EventId
 );
# 3827 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h"
Std_ReturnType
Dem_GetSI30Status(
 Dem_EventIdType EventId,
 uint8 * Status
 );
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 3838 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem.h" 2
# 37 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c" 2
# 1 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/Nvp_Cfg.h" 1
# 27 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/Nvp_Cfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/Nvp_Generated.h" 1
# 28 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/Nvp_Cfg.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/NvM_Cfg.h" 1
# 63 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/NvM_Cfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/NvM/NvM_Types.h" 1
# 31 "S:/COMPON~1/APPLIC~1/Supplier/NvM/NvM_Types.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_NvM_Type.h" 1
# 29 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_NvM_Type.h"
extern "C"
{
# 104 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_NvM_Type.h"
}
# 32 "S:/COMPON~1/APPLIC~1/Supplier/NvM/NvM_Types.h" 2
# 64 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/NvM_Cfg.h" 2






typedef union
{
 uint16 Word_u16;
 uint8 Bytes_au8[2u];
} NvM_CompiledConfigIdType;
# 219 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/NvM_Cfg.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 220 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/NvM_Cfg.h" 2






extern const NvM_BlockIdType NvM_NoOfBlockIds_t;






extern const NvM_CompiledConfigIdType NvM_CompiledConfigId_t;
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 237 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/NvM_Cfg.h" 2
# 29 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/Nvp_Cfg.h" 2
# 72 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/Nvp_Cfg.h"
typedef uint8 (* tMemoryReadAddressFct) (const uint16 u16StartAddress, const uint16 u16Length, uint8 * const pu8Data);
typedef uint8 (* tMemoryWriteAddressFct) (const uint16 u16StartAddress, const uint16 u16Length, const uint8 * const pu8Data);
# 82 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/Nvp_Cfg.h"
extern uint8 NVP_u8JobOnAddressStatus;
extern uint8 NVP_u8JobOnAddressErrorCode;
# 44 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c" 2
# 1 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/NVP_Stubs.h" 1
# 19 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/NVP_Stubs.h"
extern uint16 NVP_au16TempTableVol[7];
extern uint16 NVP_au16TempTableLSB[7];
# 45 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c" 2
# 65 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c"
typedef enum
{
 MMG_KU8_IDX_HWSELFPROT = 0,
 MMG_KU8_IDX_MOTORCURRENT,
 MMG_KU8_IDX_MOTORTEMP,
 MMG_KU8_IDX_UNDERVOLTAGE,
 MMG_KU8_IDX_OVERVOLTAGE,
 MMG_KU8_NR_OF_AUTOTESTS
}MMG_KU8_IDX;
# 90 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 1
# 91 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c" 2


static boolean MMG_b8MMGHAsBeenInitialized = ((boolean)0x55);

static uint8 MMG_u8ErrorCounter[MMG_KU8_NR_OF_AUTOTESTS];
static u8TestResultType MMG_u8ATLocalResult[MMG_KU8_NR_OF_AUTOTESTS];

boolean MMG_bVoltageStatusIsOk = ((boolean)0x55);
boolean MMG_bInternalStatusIsOk = ((boolean)0x55);
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 1
# 103 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 1
# 109 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c" 2
# 118 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c"
uint32 MMG_u32ModesStatus;
uint32 MMG_u32ModesStatusComplement;
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 1
# 124 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 1
# 70 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 71 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 2
# 130 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c" 2


void MMG_Init(void)
{
 uint8 mmg_u8Index = ((uint8) 0x00);





 MMG_u32ModesStatus = ( (2147483648U) | (4194304U) | (2097152U) );



 MMG_u32ModesStatusComplement = ((MMG_u32ModesStatus)^((uint32)0xFFFFFFFFuL));



 MMG_astDelayAfterCycleThrsandModes[((uint8)0)].u16DelayThrs = 0;
 MMG_astDelayAfterCycleThrsandModes[((uint8)1)].u16DelayThrs = 0;



 for(mmg_u8Index = ((uint8) 0x00); mmg_u8Index < ((uint8)2); mmg_u8Index++)
 {
 if(MMG_astDelayAfterCycleThrsandModes[mmg_u8Index].u16DelayThrs >= MMG_u16MaxDelayAfterCycleActivation)
 {
 MMG_u16MaxDelayAfterCycleActivation = MMG_astDelayAfterCycleThrsandModes[mmg_u8Index].u16DelayThrs;
 }
 else
 {

 }
 }


 for(mmg_u8Index = ((uint8) 0x00); mmg_u8Index < ((uint8)2); mmg_u8Index++)
 {
 MMG_astDelayAfterCycleThrsandModes[mmg_u8Index].u16DelayThrs = MMG_u16MaxDelayAfterCycleActivation - MMG_astDelayAfterCycleThrsandModes[mmg_u8Index].u16DelayThrs;
 }



 for(mmg_u8Index = ((uint8) 0x00); mmg_u8Index < MMG_KU8_NR_OF_AUTOTESTS; mmg_u8Index++)
 {
 MMG_u8ErrorCounter[mmg_u8Index] = 0;
 MMG_u8ATLocalResult[mmg_u8Index] = (4U);
 }

 MMG_b8MMGHAsBeenInitialized = ((boolean)0xAA);
}
# 194 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c"
void MMG_runUpdateModeStatus(void)
{

 if(((boolean)0xAA) == MMG_b8MMGHAsBeenInitialized)
 {


 mmg_UpdateModeStatus_CriticalAutotestsNok();



 mmg_UpdateModeStatus_PowerVoltageUnstable();



 mmg_UpdateModeStatus_ExecutedCycleDelay();



 mmg_UpdateModeStatus_ExecutedCycle();



 mmg_UpdateModeStatus_ExecutedTensioningCycle();



 mmg_UpdateModeStatus_Cranking();



 mmg_UpdateModeStatus_BusOff();



 mmg_UpdateModeStatus_NoHallEffectSensor();



 mmg_UpdateModeStatus_DefaultValues();



 mmg_UpdateModeStatus_InhibitionOfCyclesByInternalFailure_AllCycles();



 mmg_UpdateModeStatus_InhibitionOfCyclesByInternalFailure_TensioningCycles();

 }
 else
 {

 }
}
# 261 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c"
void MMG_runManageModeDelays(void)
{

 if(((boolean)0xAA) == MMG_b8MMGHAsBeenInitialized)
 {


 mmg_ManageModeDelays_ExecutedCycle();

 }
 else
 {

 }
}

void MMG_runCheckModeStatus(u32ModeMaskType_5 u32ModesToCheck, u8ModeStatusType_5 * bModeStatus)
{

 if(((boolean)0xAA) == MMG_b8MMGHAsBeenInitialized)
 {

 if (((uint32) 4294967295uL) != (MMG_u32ModesStatus ^ MMG_u32ModesStatusComplement))
 {




 MMG_u32ModesStatus = ( (2147483648U) | (4194304U) | (2097152U) );
 MMG_u32ModesStatusComplement = ((MMG_u32ModesStatus)^((uint32)0xFFFFFFFFuL));


 (*bModeStatus) = ((uint8) 0x00);
 }
 else
 {



 if ( ((0U) != u32ModesToCheck)
 && (((uint32) 0) != (MMG_u32ModesStatus & u32ModesToCheck)))
 {

 (*bModeStatus) = (170U);
 }
 else
 {

 (*bModeStatus) = (85U);
 }
 }
 }
 else
 {


 (*bModeStatus) = ((uint8) 0x00);
 }
}

void MMG_runAutotestCall10ms(void)
{


 (void)(PAL_Autotest_CheckHWSelfProtection((u8TestResultType*)(&MMG_u8ATLocalResult[MMG_KU8_IDX_HWSELFPROT])), ((Std_ReturnType)(0U)));

 switch(MMG_u8ATLocalResult[MMG_KU8_IDX_HWSELFPROT])
 {

 case (1U):

 if (MMG_u8ErrorCounter[MMG_KU8_IDX_HWSELFPROT] > ((uint8) 0x00))
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_HWSELFPROT]--;
 }
 else
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_HWSELFPROT] = 0;

 (Rte_Irv_MMG_u8CheckHWSelfProtectionResult = (MMG_u8ATLocalResult[MMG_KU8_IDX_HWSELFPROT]));
 }
 break;

 case (2U):

 if (MMG_u8ErrorCounter[MMG_KU8_IDX_HWSELFPROT] < 1)
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_HWSELFPROT]++;
 }
 else
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_HWSELFPROT] = 1;

 (Rte_Irv_MMG_u8CheckHWSelfProtectionResult = (MMG_u8ATLocalResult[MMG_KU8_IDX_HWSELFPROT]));
 }
 break;

 default:

 break;
 }



 (void)(PAL_Autotest_CheckMotorCurrent((u8TestResultType*)(&MMG_u8ATLocalResult[MMG_KU8_IDX_MOTORCURRENT])), ((Std_ReturnType)(0U)));

 switch(MMG_u8ATLocalResult[MMG_KU8_IDX_MOTORCURRENT])
 {

 case (1U):

 if (MMG_u8ErrorCounter[MMG_KU8_IDX_MOTORCURRENT] > ((uint8) 0x00))
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_MOTORCURRENT]--;
 }
 else
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_MOTORCURRENT] = 0;

 (Rte_Irv_MMG_u8CheckMotorCurrentResult = (MMG_u8ATLocalResult[MMG_KU8_IDX_MOTORCURRENT]));
 }
 break;


 case (2U):

 if (MMG_u8ErrorCounter[MMG_KU8_IDX_MOTORCURRENT] < 1)
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_MOTORCURRENT]++;
 }
 else
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_MOTORCURRENT] = 1;

 (Rte_Irv_MMG_u8CheckMotorCurrentResult = (MMG_u8ATLocalResult[MMG_KU8_IDX_MOTORCURRENT]));
 }
 break;

 default:

 break;
 }



 (void)(PMP_Autotest_CheckPowerSupplyUV((u8TestResultType*)(&MMG_u8ATLocalResult[MMG_KU8_IDX_UNDERVOLTAGE])), ((Std_ReturnType)(0U)));

 switch(MMG_u8ATLocalResult[MMG_KU8_IDX_UNDERVOLTAGE])
 {

 case (1U):

 if (MMG_u8ErrorCounter[MMG_KU8_IDX_UNDERVOLTAGE] > ((uint8) 0x00))
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_UNDERVOLTAGE]--;
 }
 else
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_UNDERVOLTAGE] = 0;

 (Rte_Irv_MMG_u8CheckPowerSupplyUVResult = (MMG_u8ATLocalResult[MMG_KU8_IDX_UNDERVOLTAGE]));
 }
 break;


 case (2U):

 if (MMG_u8ErrorCounter[MMG_KU8_IDX_UNDERVOLTAGE] < 50)
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_UNDERVOLTAGE]++;
 }
 else
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_UNDERVOLTAGE] = 50;

 (Rte_Irv_MMG_u8CheckPowerSupplyUVResult = (MMG_u8ATLocalResult[MMG_KU8_IDX_UNDERVOLTAGE]));
 }
 break;

 default:

 break;
 }



 (void)(PMP_Autotest_CheckPowerSupplyOV((u8TestResultType*)(&MMG_u8ATLocalResult[MMG_KU8_IDX_OVERVOLTAGE])), ((Std_ReturnType)(0U)));

 switch(MMG_u8ATLocalResult[MMG_KU8_IDX_OVERVOLTAGE])
 {

 case (1U):

 if (MMG_u8ErrorCounter[MMG_KU8_IDX_OVERVOLTAGE] > ((uint8) 0x00))
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_OVERVOLTAGE]--;
 }
 else
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_OVERVOLTAGE] = 0;

 (Rte_Irv_MMG_u8CheckPowerSupplyOVResult = (MMG_u8ATLocalResult[MMG_KU8_IDX_OVERVOLTAGE]));
 }
 break;


 case (2U):

 if (MMG_u8ErrorCounter[MMG_KU8_IDX_OVERVOLTAGE] < 50)
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_OVERVOLTAGE]++;
 }
 else
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_OVERVOLTAGE] = 50;

 (Rte_Irv_MMG_u8CheckPowerSupplyOVResult = (MMG_u8ATLocalResult[MMG_KU8_IDX_OVERVOLTAGE]));
 }
 break;

 default:

 break;
 }
}

void MMG_runAutotestCall100ms(void)
{


 (void)(PAL_Autotest_CheckMotorThermalProctection((u8TestResultType*)(&MMG_u8ATLocalResult[MMG_KU8_IDX_MOTORTEMP])), ((Std_ReturnType)(0U)));

 switch(MMG_u8ATLocalResult[MMG_KU8_IDX_MOTORTEMP])
 {

 case (1U):

 if (MMG_u8ErrorCounter[MMG_KU8_IDX_MOTORTEMP] > ((uint8) 0x00))
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_MOTORTEMP]--;
 }
 else
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_MOTORTEMP] = 0;

 (Rte_Irv_MMG_u8CheckMotorThermalProctectionResult = (MMG_u8ATLocalResult[MMG_KU8_IDX_MOTORTEMP]));
 }
 break;


 case (2U):

 if (MMG_u8ErrorCounter[MMG_KU8_IDX_MOTORTEMP] < 1)
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_MOTORTEMP]++;
 }
 else
 {
 MMG_u8ErrorCounter[MMG_KU8_IDX_MOTORTEMP] = 1;

 (Rte_Irv_MMG_u8CheckMotorThermalProctectionResult = (MMG_u8ATLocalResult[MMG_KU8_IDX_MOTORTEMP]));
 }
 break;

 default:

 break;
 }
}

void MMG_runGetTestResult(u8AutoTestIdType u8AutoTestId, u8TestResultType * pu8TestResult)
{
 switch(u8AutoTestId)
 {

 case (6U):

 *pu8TestResult = MMG_u8ATLocalResult[MMG_KU8_IDX_HWSELFPROT];
 break;

 case (12U):

 *pu8TestResult = MMG_u8ATLocalResult[MMG_KU8_IDX_MOTORCURRENT];
 break;

 case (14U):

 *pu8TestResult = MMG_u8ATLocalResult[MMG_KU8_IDX_MOTORTEMP];
 break;

 case (19U):

 *pu8TestResult = MMG_u8ATLocalResult[MMG_KU8_IDX_OVERVOLTAGE];
 break;

 case (18U):

 *pu8TestResult = MMG_u8ATLocalResult[MMG_KU8_IDX_UNDERVOLTAGE];
 break;
 default:

 *pu8TestResult = (8U);
 break;
 }
}

void MMG_runMainFunction(void)
{
 u8TestResultType mmg_StatusUV, mmg_StatusOV, mmg_StatusMCurr, mmg_StatusMTher, mmg_StatusHWSelfP;


 mmg_StatusUV = Rte_Irv_MMG_u8CheckPowerSupplyUVResult;
 mmg_StatusOV = Rte_Irv_MMG_u8CheckPowerSupplyOVResult;
 mmg_StatusMCurr = Rte_Irv_MMG_u8CheckMotorCurrentResult;
 mmg_StatusMTher = Rte_Irv_MMG_u8CheckMotorThermalProctectionResult;
 mmg_StatusHWSelfP = Rte_Irv_MMG_u8CheckHWSelfProtectionResult;



 if (((2U) == mmg_StatusUV) || ((2U) == mmg_StatusOV))
 {

 MMG_bVoltageStatusIsOk = ((boolean)0x55);
 (void)Dem_SetEventStatus(39u,1u);
 }
 else
 {

 MMG_bVoltageStatusIsOk = ((boolean)0xAA);
 (void)Dem_SetEventStatus(39u,0u);
 }



 if (((2U) == mmg_StatusMCurr) || ((2U) == mmg_StatusMTher) || ((2U) == mmg_StatusHWSelfP))
 {

 MMG_bInternalStatusIsOk = ((boolean)0x55);
 (void)Dem_SetEventStatus(40u,1u);
 }
 else
 {

 MMG_bInternalStatusIsOk = ((boolean)0xAA);
 (void)Dem_SetEventStatus(40u,0u);
 }
}
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 1
# 147 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 1
# 188 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 1
# 38 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/ComXf_MemMap.h" 1
# 39 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/E2EXf_MemMap.h" 1
# 40 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Rte_MemMap.h" 2
# 189 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MBP.h" 1
# 190 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 1
# 2511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 2512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 4525 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 4526 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11482 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/FiM_MemMap.h" 1
# 11483 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 11494 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 11495 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MCP.h" 2
# 191 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MEP.h" 1
# 192 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 1
# 638 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 639 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MOP_Daimler.h" 2
# 193 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h" 1
# 194 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Fbl.h" 1
# 195 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 1021 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Dem/Dem_MemMap.h" 1
# 1022 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5298 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgIf_MemMap.h" 1
# 5299 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5354 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/WdgM_OsMemMap.h" 1
# 5355 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 5511 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 1
# 1764 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 1
# 42 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/Os_MemMapInt.h" 1
# 43 "S:/COMPON~1/APPLIC~1/Supplier/Os/Os_MemMap.h" 2
# 1765 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap_Common.h" 2
# 5512 "S:/COMPON~1/APPLIC~1/Supplier/_Common/MemMap.h" 2
# 148 "S:/COMPON~1/APPLIC~1/Supplier/DAVINC~1/MMG_AC_ModeManagement_MemMap.h" 2
# 611 "S:/COMPON~1/APPLIC~1/Autoliv/MMG/IMPLEM~1/src/MMG.c" 2
