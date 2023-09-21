#include "hal_LButton.h"

#include "../../lib/TivaWare/inc/hw_memmap.h"
#include "../../lib/TivaWare/inc/tm4c123gh6pm.h"

#include <stdbool.h>
#include <stdint.h>

#include "../../lib/TivaWare/driverlib/gpio.h"
#include "../../lib/TivaWare/driverlib/sysctl.h"

#define hal_LButton_peripheral SYSCTL_PERIPH_GPIOF
#define hal_LButton_port GPIO_PORTF_BASE
#define hal_LButton_pin GPIO_PIN_4 // todo: check correct pin

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
    SysCtlPeripheralEnable(hal_LButton_peripheral);
    GPIOPinTypeGPIOInput(hal_LButton_port, hal_LButton_pin);
    return self;
}

void hal_LButton_registerInt(hal_LButton * const self, void (*const fun)(void)) {
    GPIOIntRegister(hal_LButton_port, fun);
}

void hal_LButton_unregisterInt(hal_LButton * const self) {
}
void hal_LButton_enableInt(hal_LButton * const self) {
}
void hal_LButton_disableInt(hal_LButton * const self) {
}
