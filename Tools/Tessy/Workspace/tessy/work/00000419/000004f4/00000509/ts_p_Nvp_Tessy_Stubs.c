# 1 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/src/Nvp_Tessy_Stubs.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/src/Nvp_Tessy_Stubs.c"
# 37 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/src/Nvp_Tessy_Stubs.c"
# 1 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/Nvp_Generated.h" 1
# 24 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/Nvp_Generated.h"
# 1 "S:/COMPON~1/APPLIC~1/Supplier/_Common/common.h" 1
# 25 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/Nvp_Generated.h" 2
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
# 26 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/inc/Nvp_Generated.h" 2
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
# 38 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/src/Nvp_Tessy_Stubs.c" 2
# 54 "S:/COMPON~1/APPLIC~1/Autoliv/NVP/IMPLEM~1/src/Nvp_Tessy_Stubs.c"
NVP_BLOCK_ID_ECU_LOCATION_StorageType NVP_BLOCK_ID_ECU_LOCATION_RamBlockData ;

NVP_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN_StorageType NVP_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN_RamBlockData ;

NVP_BLOCK_ID_HB_CALIBRATION_StorageType NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData ;

NVP_BLOCK_ID_AEE_TRACEABILITY_StorageType NVP_BLOCK_ID_AEE_TRACEABILITY_RamBlockData ;

NVP_BLOCK_ID_EXECUTION_COUNTERS_StorageType NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData ;

NVP_BLOCK_ID_TESTS_PARAM_StorageType NVP_BLOCK_ID_TESTS_PARAM_RamBlockData ;

NVP_BLOCK_ID_CYCLE_0_StorageType NVP_BLOCK_ID_CYCLE_0_RamBlockData ;

NVP_BLOCK_ID_STEP_0_StorageType NVP_BLOCK_ID_STEP_0_RamBlockData ;







const NVP_BLOCK_ID_ECU_LOCATION_StorageType NVP_BLOCK_ID_ECU_LOCATION_DefaultData = {0U};

const NVP_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN_StorageType NVP_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN_DefaultData = {0U};

const NVP_BLOCK_ID_HB_CALIBRATION_StorageType NVP_BLOCK_ID_HB_CALIBRATION_DefaultData = {0U};

const NVP_BLOCK_ID_AEE_TRACEABILITY_StorageType NVP_BLOCK_ID_AEE_TRACEABILITY_DefaultData = {0U};

const NVP_BLOCK_ID_EXECUTION_COUNTERS_StorageType NVP_BLOCK_ID_EXECUTION_COUNTERS_DefaultData = {0U};

const NVP_BLOCK_ID_TESTS_PARAM_StorageType NVP_BLOCK_ID_TESTS_PARAM_DefaultData = {0U};

const NVP_BLOCK_ID_CYCLE_0_StorageType NVP_BLOCK_ID_CYCLE_0_DefaultData = {0U};

const NVP_BLOCK_ID_STEP_0_StorageType NVP_BLOCK_ID_STEP_0_DefaultData = {0U};







const CALIB_BLOCK_ID_EOL_PARAM_StorageType CALIB_BLOCK_ID_EOL_PARAM_RomBlockData = {0U};

const CALIB_BLOCK_ID_BFS_PRIO_PARAM_StorageType CALIB_BLOCK_ID_BFS_PRIO_PARAM_RomBlockData = {0U};

const CALIB_BLOCK_ID_PID_PARAM_StorageType CALIB_BLOCK_ID_PID_PARAM_RomBlockData = {0U};

const CALIB_BLOCK_ID_WEIGHT_REL_TABLE_StorageType CALIB_BLOCK_ID_WEIGHT_REL_TABLE_RomBlockData = {0U};

const CALIB_BLOCK_ID_WEIGHT_TENS0_TABLE_StorageType CALIB_BLOCK_ID_WEIGHT_TENS0_TABLE_RomBlockData = {0U};

const CALIB_BLOCK_ID_WEIGHT_TENS1_TABLE_StorageType CALIB_BLOCK_ID_WEIGHT_TENS1_TABLE_RomBlockData = {0U};

const CALIB_BLOCK_ID_WEIGHT_TENS2_TABLE_StorageType CALIB_BLOCK_ID_WEIGHT_TENS2_TABLE_RomBlockData = {0U};

const CALIB_BLOCK_ID_WEIGHT_TENS3_TABLE_StorageType CALIB_BLOCK_ID_WEIGHT_TENS3_TABLE_RomBlockData = {0U};

const CALIB_BLOCK_ID_INT_CURRENT_CORR_StorageType CALIB_BLOCK_ID_INT_CURRENT_CORR_RomBlockData = {0U};

const CALIB_BLOCK_ID_INT_CURRENT_TABLE_StorageType CALIB_BLOCK_ID_INT_CURRENT_TABLE_RomBlockData = {0U};

const CALIB_BLOCK_ID_POWER_DEGRADATION_StorageType CALIB_BLOCK_ID_POWER_DEGRADATION_RomBlockData = {0U};

const CALIB_BLOCK_ID_ECPL_ALPHA_TABLE_StorageType CALIB_BLOCK_ID_ECPL_ALPHA_TABLE_RomBlockData = {0U};

const CALIB_BLOCK_ID_ECPL_BETA_TABLE_StorageType CALIB_BLOCK_ID_ECPL_BETA_TABLE_RomBlockData = {0U};

const CALIB_BLOCK_ID_ECPL_OTHER_PARAM_StorageType CALIB_BLOCK_ID_ECPL_OTHER_PARAM_RomBlockData = {0U};

const CALIB_BLOCK_ID_BPA_MOTOR_CURRENT_StorageType CALIB_BLOCK_ID_BPA_MOTOR_CURRENT_RomBlockData = {0U};

const CALIB_BLOCK_ID_VOLT_THRS_StorageType CALIB_BLOCK_ID_VOLT_THRS_RomBlockData = {0U};

const CALIB_BLOCK_ID_BATTERY_LOSS_DETECTION_THRS_StorageType CALIB_BLOCK_ID_BATTERY_LOSS_DETECTION_THRS_RomBlockData = {0U};

const CALIB_BLOCK_ID_BOOST_StorageType CALIB_BLOCK_ID_BOOST_RomBlockData = {0U};

const CALIB_BLOCK_ID_ECU_PROPERTIES_StorageType CALIB_BLOCK_ID_ECU_PROPERTIES_RomBlockData = {0U};

const CALIB_BLOCK_ID_SW_SELF_PROTECTION_THRS_StorageType CALIB_BLOCK_ID_SW_SELF_PROTECTION_THRS_RomBlockData = {0U};

const CALIB_BLOCK_ID_MOTOR_RESIST_PARAM_StorageType CALIB_BLOCK_ID_MOTOR_RESIST_PARAM_RomBlockData = {0U};

const CALIB_BLOCK_ID_BOOST_ACTIVATION_StorageType CALIB_BLOCK_ID_BOOST_ACTIVATION_RomBlockData = {0U};
