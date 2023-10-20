#ifndef HA_PER_PORTF_H
#define HA_PER_PORTF_H
/*............................................................................*/
typedef struct ha_per_PortF ha_per_PortF;
#include "../ha_Interrupt.h"
#include <stdbool.h>
/*............................................................................*/
struct ha_per_PortF {
    bool _isInitialized;
    bool _isIntRegistered;
    struct {
        ha_InterruptHandler leftButton;
        ha_InterruptHandler rightButton;
    } _intHandlers;
};
/*............................................................................*/
#define ha_RightButton_pin GPIO_PIN_0
#define ha_LeftButton_pin GPIO_PIN_4
/*............................................................................*/
ha_per_PortF * ha_per_PortF_(void);
ha_per_PortF * ha_per_PortF_init(ha_per_PortF * const self);
void ha_per_PortF_registerLeftButtonInt(
    ha_per_PortF * const self, ha_InterruptHandler const intHandler
);
void ha_per_PortF_unregisterLeftButtonInt(ha_per_PortF * const self);
void ha_per_PortF_registerRightButtonInt(
    ha_per_PortF * const self, ha_InterruptHandler const intHandler
);
void ha_per_PortF_unregisterRightButtonInt(ha_per_PortF * const self);
#endif // HA_PER_PORTF_H
