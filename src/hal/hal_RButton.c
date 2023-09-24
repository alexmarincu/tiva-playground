#include "hal_RButton.h"

#include "sup/hal_sup_PortF.h"

#include "../../lib/TivaWare/inc/hw_memmap.h"
#include "../../lib/TivaWare/inc/tm4c123gh6pm.h"

#include <stdbool.h>
#include <stdint.h>

#include "../../lib/TivaWare/driverlib/gpio.h"
#include "../../lib/TivaWare/driverlib/sysctl.h"

#define hal_RButton_port GPIO_PORTF_BASE

struct hal_RButton {
    hal_Button button;
};

hal_RButton * hal_RButton_(void) {
    static hal_RButton self;
    return &self;
}

hal_RButton * hal_RButton_init(hal_RButton * const self) {
    hal_Button_init(
        &self->button,
        self,
        (hal_ButtonSetIntTypeBothEdges)hal_RButton_setIntTypeBothEdges,
        (hal_ButtonRegisterInt)hal_RButton_registerInt,
        (hal_ButtonUnregisterInt)hal_RButton_unregisterInt,
        (hal_ButtonEnableInt)hal_RButton_enableInt,
        (hal_ButtonDisableInt)hal_RButton_disableInt,
        (hal_ButtonClearIntFlag)hal_RButton_clearIntFlag,
        (hal_ButtonIsPressed)hal_RButton_isPressed
    );
    hal_sup_PortF_init(hal_sup_PortF_());
    GPIOUnlockPin(hal_RButton_port, hal_RButton_pin);
    GPIOPinTypeGPIOInput(hal_RButton_port, hal_RButton_pin);
    GPIOPadConfigSet(hal_RButton_port, hal_RButton_pin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
    return self;
}

void hal_RButton_setIntTypeBothEdges(hal_RButton * const self) {
    GPIOIntTypeSet(hal_RButton_port, hal_RButton_pin, GPIO_BOTH_EDGES);
}

void hal_RButton_registerInt(hal_RButton * const self, void (*const fun)(void)) {
    hal_sup_PortF_registerRButtonInt(hal_sup_PortF_(), fun);
}

void hal_RButton_unregisterInt(hal_RButton * const self) {
    GPIOIntUnregister(hal_RButton_port);
}

void hal_RButton_enableInt(hal_RButton * const self) {
    GPIOIntEnable(hal_RButton_port, hal_RButton_pin);
}

void hal_RButton_disableInt(hal_RButton * const self) {
    GPIOIntDisable(hal_RButton_port, hal_RButton_pin);
}

void hal_RButton_clearIntFlag(hal_RButton * const self) {
    GPIOIntClear(hal_RButton_port, hal_RButton_pin);
}

bool hal_RButton_isPressed(hal_RButton * const self) {
    return (GPIOPinRead(hal_RButton_port, hal_RButton_pin) == 0);
}
