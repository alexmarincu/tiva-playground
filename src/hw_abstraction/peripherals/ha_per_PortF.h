/*----------------------------------------------------------------------------*/
#ifndef HA_PER_PORTF_H
#define HA_PER_PORTF_H
/*----------------------------------------------------------------------------*/
typedef struct ha_per_PortF ha_per_PortF;
/*----------------------------------------------------------------------------*/
#include <stdbool.h>
/*----------------------------------------------------------------------------*/
#include "../ha_Interrupt.h"
/*----------------------------------------------------------------------------*/
#define ha_per_PortF_rightButtonPin GPIO_PIN_0
#define ha_per_PortF_redLedPin GPIO_PIN_1
#define ha_per_PortF_blueLedPin GPIO_PIN_2
#define ha_per_PortF_greenLedPin GPIO_PIN_3
#define ha_per_PortF_leftButtonPin GPIO_PIN_4
/*----------------------------------------------------------------------------*/
struct ha_per_PortF {
    bool _isIntRegistered;
    struct {
        ha_InterruptHandler leftButton;
        ha_InterruptHandler rightButton;
    } _intHandlers;
};
/*----------------------------------------------------------------------------*/
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
