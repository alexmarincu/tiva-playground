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
        (hal_Button_intRegisterFun)hal_LButton_intRegister,
        (hal_Button_intUnregisterFun)hal_LButton_intUnregister,
        (hal_Button_intEnableFun)hal_LButton_intEnable,
        (hal_Button_intDisableFun)hal_LButton_intDisable
    );

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);
    return self;
}

void hal_LButton_intRegister(hal_LButton * const self, void (*const fun)(void)) {
    GPIOIntRegister(GPIO_PORTF_BASE, fun);
}

void hal_LButton_intUnregister(hal_LButton * const self) {
}
void hal_LButton_intEnable(hal_LButton * const self) {
}
void hal_LButton_intDisable(hal_LButton * const self) {
}
