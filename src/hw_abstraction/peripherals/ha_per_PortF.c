#include "ha_per_PortF.h"

#include "../../lib/TivaWare/inc/hw_memmap.h"
#include "../../lib/TivaWare/inc/tm4c123gh6pm.h"

#include <stdbool.h>
#include <stdint.h>

#include "../../lib/TivaWare/driverlib/gpio.h"
#include "../../lib/TivaWare/driverlib/sysctl.h"

struct ha_per_PortF {
    bool isInitialized;
    bool isIntRegistered;
    ha_InterruptHandler leftButtonIntHandler;
    ha_InterruptHandler rightButtonIntHandler;
};

static void portFIntHandler(void) {
    ha_per_PortF * self = ha_per_PortF_();
    uint32_t intStatus = GPIOIntStatus(GPIO_PORTF_BASE, true);
    if (self->leftButtonIntHandler && (intStatus & ha_LeftButton_pin)) {
        self->leftButtonIntHandler();
    }
    if (self->rightButtonIntHandler && (intStatus & ha_RightButton_pin)) {
        self->rightButtonIntHandler();
    }
}

ha_per_PortF * ha_per_PortF_(void) {
    static ha_per_PortF self;
    return &self;
}

ha_per_PortF * ha_per_PortF_init(ha_per_PortF * const self) {
    if (self->isInitialized == false) {
        self->leftButtonIntHandler = 0;
        self->rightButtonIntHandler = 0;
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
        self->isInitialized = true;
    }
    return self;
}

static void ha_per_PortF_registerInternalInt(ha_per_PortF * const self) {
    if (self->isIntRegistered == false) {
        self->isIntRegistered = true;
        GPIOIntRegister(GPIO_PORTF_BASE, portFIntHandler);
    }
}

void ha_per_PortF_registerLeftButtonInt(ha_per_PortF * const self, ha_InterruptHandler const intHandler) {
    self->leftButtonIntHandler = intHandler;
    ha_per_PortF_registerInternalInt(self);
}

void ha_per_PortF_unregisterLeftButtonInt(ha_per_PortF * const self) {
    // todo
}

void ha_per_PortF_registerRightButtonInt(ha_per_PortF * const self, ha_InterruptHandler const intHandler) {
    self->rightButtonIntHandler = intHandler;
    ha_per_PortF_registerInternalInt(self);
}

void ha_per_PortF_unregisterRightButtonInt(ha_per_PortF * const self) {
    // todo
}
