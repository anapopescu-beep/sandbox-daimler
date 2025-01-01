#ifndef _DEM_H
#define _DEM_H
#include "Std_Types.h"

#if !defined (Rte_TypeDef_Dem_EventIdType)                                 
typedef uint16                                   Dem_EventIdType;
#endif
#if !defined (Rte_TypeDef_Dem_DTCStatusMaskType)                           
typedef uint8                                    Dem_DTCStatusMaskType;
#endif
#if !defined (Rte_TypeDef_Dem_MonitorStatusType)                           
typedef uint8                                    Dem_MonitorStatusType;
#endif
#if !defined (DEM_MONITOR_STATUS_TF)                                       
# define DEM_MONITOR_STATUS_TF                   (0x01U)                   
#endif
#if !defined (DEM_MONITOR_STATUS_TNCTOC)                                   
# define DEM_MONITOR_STATUS_TNCTOC               (0x02U)                   
#endif
#if !defined (Rte_TypeDef_Dem_EventStatusType)                             
typedef uint8                                    Dem_EventStatusType;
#endif
#if !defined (DEM_EVENT_STATUS_PASSED)                                     
# define DEM_EVENT_STATUS_PASSED                 (0x00U)                   
#endif
#if !defined (DEM_EVENT_STATUS_FAILED)                                     
# define DEM_EVENT_STATUS_FAILED                 (0x01U)                   
#endif
#if !defined (DEM_EVENT_STATUS_PREPASSED)                                  
# define DEM_EVENT_STATUS_PREPASSED              (0x02U)                   
#endif
#if !defined (DEM_EVENT_STATUS_PREFAILED)                                  
# define DEM_EVENT_STATUS_PREFAILED              (0x03U)                   
#endif
#if !defined (DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED)                      
# define DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED                   (0x04U)  
#endif
#if !defined (DEM_EVENT_STATUS_PASSED_CONDITIONS_NOT_FULFILLED)            
# define DEM_EVENT_STATUS_PASSED_CONDITIONS_NOT_FULFILLED         (0x05U)  
#endif
#if !defined (DEM_EVENT_STATUS_FAILED_CONDITIONS_NOT_FULFILLED)            
# define DEM_EVENT_STATUS_FAILED_CONDITIONS_NOT_FULFILLED         (0x06U)  
#endif
#if !defined (DEM_EVENT_STATUS_PREPASSED_CONDITIONS_NOT_FULFILLED)         
# define DEM_EVENT_STATUS_PREPASSED_CONDITIONS_NOT_FULFILLED      (0x07U)  
#endif
#if !defined (DEM_EVENT_STATUS_PREFAILED_CONDITIONS_NOT_FULFILLED)         
# define DEM_EVENT_STATUS_PREFAILED_CONDITIONS_NOT_FULFILLED      (0x08U)  
#endif


/* Config Stub */
#define DemConf_DemEventParameter_DemEventParameter_Dummy     (0u)
#define DemConf_DemEventParameter_DemEventParameter_Dummy_001 (1u)
#define DemConf_DemEventParameter_DemEventParameter_Dummy_002 (2u)
#define DemConf_DemEventParameter_DemEventParameter_Dummy_003 (3u)
#define DemConf_DemEventParameter_DemEventParameter_Dummy_004 (4u)

#define DemConf_DemEventParameter_DemEventParameter           (0u)

/* Compatibility Defines */
#define DEM_AR_RELEASE_MAJOR_VERSION                          4u
#define DEM_AR_RELEASE_MINOR_VERSION                          0u

#define ENABLE_DEM_REPORT                                     1u
#define DISABLE_DEM_REPORT                                    2u

/* Function Stubs */
#define Dem_ReportErrorStatus(a,b)  (void)0


#endif
