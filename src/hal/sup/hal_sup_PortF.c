#include "hal_sup_PortF.h"

#include "../../lib/TivaWare/inc/hw_memmap.h"
#include "../../lib/TivaWare/inc/tm4c123gh6pm.h"

#include <stdbool.h>
#include <stdint.h>

#include "../../lib/TivaWare/driverlib/gpio.h"
#include "../../lib/TivaWare/driverlib/sysctl.h"

struct hal_sup_PortF {
    bool isInitialized;
    bool isIntRegistered;
    hal_sup_PortFIntHandler lButtonInt;
    hal_sup_PortFIntHandler rButtonInt;
};

static void hal_sup_PortF_int(void) {
    hal_sup_PortF * self = hal_sup_PortF_();
    uint32_t intStatus = GPIOIntStatus(GPIO_PORTF_BASE, true);
    if (self->lButtonInt && (intStatus & hal_LButton_pin)) {
        self->lButtonInt();
    }
    if (self->rButtonInt && (intStatus & hal_RButton_pin)) {
        self->rButtonInt();
    }
}

hal_sup_PortF * hal_sup_PortF_(void) {
    static hal_sup_PortF self;
    return &self;
}

hal_sup_PortF * hal_sup_PortF_init(hal_sup_PortF * const self) {
    if (self->isInitialized == false) {
        self->lButtonInt = 0;
        self->rButtonInt = 0;
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
        self->isInitialized = true;
    }
    return self;
}

static void hal_sup_PortF_registerInternalInt(hal_sup_PortF * const self) {
    if (self->isIntRegistered == false) {
        self->isIntRegistered = true;
        GPIOIntRegister(GPIO_PORTF_BASE, hal_sup_PortF_int);
    }
}

void hal_sup_PortF_registerLButtonInt(hal_sup_PortF * const self, hal_sup_PortFIntHandler const intHandler) {
    self->lButtonInt = intHandler;
    hal_sup_PortF_registerInternalInt(self);
}

void hal_sup_PortF_unregisterLButtonInt(hal_sup_PortF * const self) {
    // todo
}

void hal_sup_PortF_registerRButtonInt(hal_sup_PortF * const self, hal_sup_PortFIntHandler const intHandler) {
    self->rButtonInt = intHandler;
    hal_sup_PortF_registerInternalInt(self);
}

void hal_sup_PortF_unregisterRButtonInt(hal_sup_PortF * const self) {
    // todo
}
