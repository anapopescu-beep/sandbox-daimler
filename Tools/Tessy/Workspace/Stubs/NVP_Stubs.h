#include "Std_Types.h"
/* @__CALIBRATION__ */
#define NVP_s8TempOffsetChamberNTC -6

/* @__RAM_SHADOW__ */
#define NVP_u16MinDiffVoltageToValidateBatterySurvey 1200
#define NVP_u8SWThermalProtecDecStep 50
#define NVP_u32SWThermalProtectionValidationThrs 160000
#define NVP_u8NbOccurenceToValidateBatteryVoltage 4
#define NVP_u16MotorDisengagementMinTemp 56
#define NVP_s16MotorDisengagementMinPowerOrder -768
#define NVP_s16MotorDisengagementMaxPowerOrder -4800
#define NVP_u8NbOccurenceToDeskillMotorBlocked 1
#define NVP_u8NbOccurenceToValidateMotorBlocked 5

#define NVP_u16DelayAfterCycleExecutionOrPOR 0 
#define NVP_u16DelayAfterCycleExecutionOrPOR_UV 0

extern uint16 NVP_au16TempTableVol[7];
extern uint16 NVP_au16TempTableLSB[7];
