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
    ha_per_PortFIntHandler lButtonInt;
    ha_per_PortFIntHandler rButtonInt;
};

static void ha_per_PortF_int(void) {
    ha_per_PortF * self = ha_per_PortF_();
    uint32_t intStatus = GPIOIntStatus(GPIO_PORTF_BASE, true);
    if (self->lButtonInt && (intStatus & ha_LeftButton_pin)) {
        self->lButtonInt();
    }
    if (self->rButtonInt && (intStatus & ha_RightButton_pin)) {
        self->rButtonInt();
    }
}

ha_per_PortF * ha_per_PortF_(void) {
    static ha_per_PortF self;
    return &self;
}

ha_per_PortF * ha_per_PortF_init(ha_per_PortF * const self) {
    if (self->isInitialized == false) {
        self->lButtonInt = 0;
        self->rButtonInt = 0;
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
        self->isInitialized = true;
    }
    return self;
}

static void ha_per_PortF_registerInternalInt(ha_per_PortF * const self) {
    if (self->isIntRegistered == false) {
        self->isIntRegistered = true;
        GPIOIntRegister(GPIO_PORTF_BASE, ha_per_PortF_int);
    }
}

void ha_per_PortF_registerLButtonInt(ha_per_PortF * const self, ha_per_PortFIntHandler const intHandler) {
    self->lButtonInt = intHandler;
    ha_per_PortF_registerInternalInt(self);
}

void ha_per_PortF_unregisterLButtonInt(ha_per_PortF * const self) {
    // todo
}

void ha_per_PortF_registerRButtonInt(ha_per_PortF * const self, ha_per_PortFIntHandler const intHandler) {
    self->rButtonInt = intHandler;
    ha_per_PortF_registerInternalInt(self);
}

void ha_per_PortF_unregisterRButtonInt(ha_per_PortF * const self) {
    // todo
}
