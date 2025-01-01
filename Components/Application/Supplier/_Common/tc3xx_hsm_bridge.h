#ifndef TC3XX_HSM_BRIDGE_H
#define TC3XX_HSM_BRIDGE_H

#include <stdint.h>

/*------------- BRIDGE Module   ----------------------------------------------*/
#define __IO volatile

typedef struct
{
       uint32_t RESERVED0[2]             ;
  __IO uint32_t HSM_ID                   ; // Module Identifier Register
       uint32_t RESERVED1[5]             ;
  __IO uint32_t HT2HSMF                  ; // Host to HSM Flag Register
  __IO uint32_t HT2HSMIE                 ; // Host to HSM Interrupt Enable
  __IO uint32_t HSM2HTF                  ; // HSM to Host Flag Register
  __IO uint32_t HSM2HTIE                 ; // HSM to Host Interrupt Enable
  __IO uint32_t HSM2HTIS                 ; // HSM to Host Interrupt Select
  __IO uint32_t HSM2HTS                  ; // HSM to Host Status
  __IO uint32_t HT2HSMS                  ; // Host to HSM Status
       uint32_t RESERVED2                ;
  __IO uint32_t CLKCTRL                  ; // Clock Control Register
       uint32_t RESERVED3[7]             ;
  __IO uint32_t DBGCTRL                  ; // Debug Control Register
  __IO uint32_t PINCTRL                  ; // Pin Control Register
       uint32_t RESERVED4[6]             ;
  __IO uint32_t ERRCTRL                  ; // Error Control Register
  __IO uint32_t ERRIE                    ; // Error Interrupt Enable Register
  __IO uint32_t ERRADDR                  ; // Error Address Register
       uint32_t RESERVED5[5]             ;
  __IO uint32_t EXTIF                    ; // External Interrupt Flag Register
  __IO uint32_t EXTIE                    ; // External Interrupt Enable
       uint32_t RESERVED6[6]             ;
  __IO uint32_t SAHBASE                  ; // Single Access to Host Base Address Register
       uint32_t RESERVED7[7]             ;
  __IO uint32_t RSTCTRL                  ; // Reset Control Register
  __IO uint32_t RSTPWD                   ; // Reset Password Register
       uint32_t RESERVED8[2]             ;
  __IO uint32_t SENSIF                   ; // Sensor Interrupt Flag Register
  __IO uint32_t SENSIE                   ; // Sensor Interrupt Enable Register
  __IO uint32_t SENSAPPRST               ; // Sensor Application Reset Enable Register
  __IO uint32_t SENSSYSRST               ; // Sensor System Reset Enable Register
       uint32_t RESERVED9[16320]         ;
  __IO uint32_t SAHMEM[16384]            ; // Single Access to Host Memory Window
} HSM_BRIDGE_TypeDef;

#define HSM_Bridge_BASE                (0xF0040000UL)
#define HSM_BRIDGE                     ((HSM_BRIDGE_TypeDef *) HSM_Bridge_BASE)

#endif /* TC3XX_HSM_BRIDGE_H */
