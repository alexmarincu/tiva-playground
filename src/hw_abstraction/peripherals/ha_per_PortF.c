/*............................................................................*/
#include "ha_per_PortF.h"
#include <stdint.h>
//
#include "../../lib/TivaWare/driverlib/gpio.h"
#include "../../lib/TivaWare/driverlib/sysctl.h"
#include "../../lib/TivaWare/inc/hw_memmap.h"
#include "../../lib/TivaWare/inc/tm4c123gh6pm.h"
#include <stdbool.h>
#include <stddef.h>
/*............................................................................*/
static void portFIntHandler(void);
static void ha_per_PortF_registerInternalInt(
    ha_per_PortF * const self
);
/*............................................................................*/
static void portFIntHandler(void) {
    ha_per_PortF * self = ha_per_PortF_();
    uint32_t intStatus = GPIOIntStatus(GPIO_PORTF_BASE, true);
    if (self->_intHandlers.leftButton && (intStatus & ha_LeftButton_pin)) {
        self->_intHandlers.leftButton();
    }
    if (self->_intHandlers.rightButton && (intStatus & ha_RightButton_pin)) {
        self->_intHandlers.rightButton();
    }
}
/*............................................................................*/
ha_per_PortF * ha_per_PortF_(void) {
    static ha_per_PortF self;
    return &self;
}
/*............................................................................*/
ha_per_PortF * ha_per_PortF_init(
    ha_per_PortF * const self
) {
    if (self->_isInitialized == false) {
        self->_intHandlers.leftButton = NULL;
        self->_intHandlers.rightButton = NULL;
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
        self->_isInitialized = true;
    }
    return self;
}
/*............................................................................*/
static void ha_per_PortF_registerInternalInt(
    ha_per_PortF * const self
) {
    if (self->_isIntRegistered == false) {
        self->_isIntRegistered = true;
        GPIOIntRegister(GPIO_PORTF_BASE, portFIntHandler);
    }
}
/*............................................................................*/
void ha_per_PortF_registerLeftButtonInt(
    ha_per_PortF * const self,
    ha_InterruptHandler const intHandler
) {
    self->_intHandlers.leftButton = intHandler;
    ha_per_PortF_registerInternalInt(self);
}
/*............................................................................*/
void ha_per_PortF_unregisterLeftButtonInt(
    ha_per_PortF * const self
) {
    // todo
}
/*............................................................................*/
void ha_per_PortF_registerRightButtonInt(
    ha_per_PortF * const self,
    ha_InterruptHandler const intHandler
) {
    self->_intHandlers.rightButton = intHandler;
    ha_per_PortF_registerInternalInt(self);
}
/*............................................................................*/
void ha_per_PortF_unregisterRightButtonInt(
    ha_per_PortF * const self
) {
    // todo
}
