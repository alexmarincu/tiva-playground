#include "ha_RightButton.h"

#include "peripherals/ha_per_PortF.h"

#include "../../lib/TivaWare/inc/hw_memmap.h"

#include <stdbool.h>
#include <stdint.h>

#include "../../lib/TivaWare/driverlib/gpio.h"

#define ha_RightButton_port GPIO_PORTF_BASE

struct ha_RightButton {
    ha_Button button;
};

ha_RightButton * ha_RightButton_(void) {
    static ha_RightButton self;
    return &self;
}

ha_RightButton * ha_RightButton_init(ha_RightButton * const self) {
    ha_Button_init(
        &self->button,
        self,
        (ha_ButtonSetIntTypeBothEdges)ha_RightButton_setIntTypeBothEdges,
        (ha_ButtonRegisterInt)ha_RightButton_registerInt,
        (ha_ButtonUnregisterInt)ha_RightButton_unregisterInt,
        (ha_ButtonEnableInt)ha_RightButton_enableInt,
        (ha_ButtonDisableInt)ha_RightButton_disableInt,
        (ha_ButtonClearIntFlag)ha_RightButton_clearIntFlag,
        (ha_ButtonIsPressed)ha_RightButton_isPressed
    );
    ha_per_PortF_init(ha_per_PortF_());
    GPIOUnlockPin(ha_RightButton_port, ha_RightButton_pin);
    GPIOPinTypeGPIOInput(ha_RightButton_port, ha_RightButton_pin);
    GPIOPadConfigSet(ha_RightButton_port, ha_RightButton_pin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
    return self;
}

void ha_RightButton_setIntTypeBothEdges(ha_RightButton * const self) {
    GPIOIntTypeSet(ha_RightButton_port, ha_RightButton_pin, GPIO_BOTH_EDGES);
}

void ha_RightButton_registerInt(ha_RightButton * const self, ha_InterruptHandler const intHandler) {
    ha_per_PortF_registerRightButtonInt(ha_per_PortF_(), intHandler);
}

void ha_RightButton_unregisterInt(ha_RightButton * const self) {
    GPIOIntUnregister(ha_RightButton_port);
}

void ha_RightButton_enableInt(ha_RightButton * const self) {
    GPIOIntEnable(ha_RightButton_port, ha_RightButton_pin);
}

void ha_RightButton_disableInt(ha_RightButton * const self) {
    GPIOIntDisable(ha_RightButton_port, ha_RightButton_pin);
}

void ha_RightButton_clearIntFlag(ha_RightButton * const self) {
    GPIOIntClear(ha_RightButton_port, ha_RightButton_pin);
}

bool ha_RightButton_isPressed(ha_RightButton * const self) {
    return (GPIOPinRead(ha_RightButton_port, ha_RightButton_pin) == 0);
}
