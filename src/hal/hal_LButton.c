#include "hal_LButton.h"

#include "sup/hal_sup_PortF.h"

#include "../../lib/TivaWare/inc/hw_memmap.h"
#include "../../lib/TivaWare/inc/tm4c123gh6pm.h"

#include <stdbool.h>
#include <stdint.h>

#include "../../lib/TivaWare/driverlib/gpio.h"
#include "../../lib/TivaWare/driverlib/sysctl.h"

#define hal_LButton_port GPIO_PORTF_BASE

struct hal_LButton {
    hal_Button button;
};

hal_LButton * hal_LButton_(void) {
    static hal_LButton self;
    return &self;
}

hal_LButton * hal_LButton_init(hal_LButton * const self) {
    hal_Button_init(
        &self->button,
        self,
        (hal_ButtonSetIntTypeBothEdges)hal_LButton_setIntTypeBothEdges,
        (hal_ButtonRegisterInt)hal_LButton_registerInt,
        (hal_ButtonUnregisterInt)hal_LButton_unregisterInt,
        (hal_ButtonEnableInt)hal_LButton_enableInt,
        (hal_ButtonDisableInt)hal_LButton_disableInt,
        (hal_ButtonClearIntFlag)hal_LButton_clearIntFlag,
        (hal_ButtonIsPressed)hal_LButton_isPressed
    );
    hal_sup_PortF_init(hal_sup_PortF_());
    GPIOPinTypeGPIOInput(hal_LButton_port, hal_LButton_pin);
    GPIOPadConfigSet(hal_LButton_port, hal_LButton_pin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
    return self;
}

void hal_LButton_setIntTypeBothEdges(hal_LButton * const self) {
    GPIOIntTypeSet(hal_LButton_port, hal_LButton_pin, GPIO_BOTH_EDGES);
}

void hal_LButton_registerInt(hal_LButton * const self, void (*const fun)(void)) {
    hal_sup_PortF_registerLButtonInt(hal_sup_PortF_(), fun);
}

void hal_LButton_unregisterInt(hal_LButton * const self) {
    GPIOIntUnregister(hal_LButton_pin);
}

void hal_LButton_enableInt(hal_LButton * const self) {
    GPIOIntEnable(hal_LButton_port, hal_LButton_pin);
}

void hal_LButton_disableInt(hal_LButton * const self) {
    GPIOIntDisable(hal_LButton_port, hal_LButton_pin);
}

void hal_LButton_clearIntFlag(hal_LButton * const self) {
    GPIOIntClear(hal_LButton_port, hal_LButton_pin);
}

bool hal_LButton_isPressed(hal_LButton * const self) {
    return (GPIOPinRead(hal_LButton_port, hal_LButton_pin) == 0);
}
