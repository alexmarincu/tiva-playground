#ifndef HAL_SUP_PORTF_H
#define HAL_SUP_PORTF_H
#include <stdbool.h>

typedef struct hal_sup_PortF hal_sup_PortF;
typedef void (*hal_sup_PortFIntHandler)(void);

#define hal_RButton_pin GPIO_PIN_0
#define hal_LButton_pin GPIO_PIN_4

hal_sup_PortF * hal_sup_PortF_(void);
hal_sup_PortF * hal_sup_PortF_init(hal_sup_PortF * const self);
void hal_sup_PortF_setLButtonIntTypeBothEdges(hal_sup_PortF * const self);
void hal_sup_PortF_registerLButtonInt(hal_sup_PortF * const self, hal_sup_PortFIntHandler const intHandler);
void hal_sup_PortF_unregisterLButtonInt(hal_sup_PortF * const self);
void hal_sup_PortF_enableLButtonInt(hal_sup_PortF * const self);
void hal_sup_PortF_disableLButtonInt(hal_sup_PortF * const self);
void hal_sup_PortF_clearLButtonIntFlag(hal_sup_PortF * const self);
void hal_sup_PortF_setRButtonIntTypeBothEdges(hal_sup_PortF * const self);
void hal_sup_PortF_registerRButtonInt(hal_sup_PortF * const self, hal_sup_PortFIntHandler const intHandler);
void hal_sup_PortF_unregisterRButtonInt(hal_sup_PortF * const self);
void hal_sup_PortF_enableRButtonInt(hal_sup_PortF * const self);
void hal_sup_PortF_disableRButtonInt(hal_sup_PortF * const self);
void hal_sup_PortF_clearRButtonIntFlag(hal_sup_PortF * const self);

#endif // HAL_SUP_PORTF_H
