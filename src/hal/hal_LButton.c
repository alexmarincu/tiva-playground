#include "hal_LButton.h"

#include "inc/hw_memmap.h"
#include "inc/tm4c123gh6pm.h"

#include <stdbool.h>
#include <stdint.h>

#include "../driverlib/gpio.h"
#include "../driverlib/sysctl.h"

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
        (hal_ButtonRegisterInt)hal_LButton_registerInt,
        (hal_ButtonUnregisterInt)hal_LButton_unregisterInt,
        (hal_ButtonEnableInt)hal_LButton_enableInt,
        (hal_ButtonDisableInt)hal_LButton_disableInt
    );

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);
    return self;
}

void hal_LButton_registerInt(hal_LButton * const self, void (*const fun)(void)) {
    GPIOIntRegister(GPIO_PORTF_BASE, fun);
}

void hal_LButton_unregisterInt(hal_LButton * const self) {
}
void hal_LButton_enableInt(hal_LButton * const self) {
}
void hal_LButton_disableInt(hal_LButton * const self) {
}
