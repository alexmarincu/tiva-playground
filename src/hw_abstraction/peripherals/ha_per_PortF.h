#ifndef HA_PER_PORTF_H
#define HA_PER_PORTF_H
#include <stdbool.h>

typedef struct ha_per_PortF ha_per_PortF;
typedef void (*ha_per_PortFIntHandler)(void);

#define ha_RightButton_pin GPIO_PIN_0
#define ha_LeftButton_pin GPIO_PIN_4

ha_per_PortF * ha_per_PortF_(void);
ha_per_PortF * ha_per_PortF_init(ha_per_PortF * const self);
void ha_per_PortF_setLButtonIntTypeBothEdges(ha_per_PortF * const self);
void ha_per_PortF_registerLButtonInt(ha_per_PortF * const self, ha_per_PortFIntHandler const intHandler);
void ha_per_PortF_unregisterLButtonInt(ha_per_PortF * const self);
void ha_per_PortF_enableLButtonInt(ha_per_PortF * const self);
void ha_per_PortF_disableLButtonInt(ha_per_PortF * const self);
void ha_per_PortF_clearLButtonIntFlag(ha_per_PortF * const self);
void ha_per_PortF_setRButtonIntTypeBothEdges(ha_per_PortF * const self);
void ha_per_PortF_registerRButtonInt(ha_per_PortF * const self, ha_per_PortFIntHandler const intHandler);
void ha_per_PortF_unregisterRButtonInt(ha_per_PortF * const self);
void ha_per_PortF_enableRButtonInt(ha_per_PortF * const self);
void ha_per_PortF_disableRButtonInt(ha_per_PortF * const self);
void ha_per_PortF_clearRButtonIntFlag(ha_per_PortF * const self);

#endif // HA_PER_PORTF_H
