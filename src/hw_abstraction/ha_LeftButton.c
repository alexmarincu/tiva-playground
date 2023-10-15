/*............................................................................*/
#include "ha_LeftButton.h"
#include <stdbool.h>
#include <stdint.h>
//
#include "../../lib/TivaWare/driverlib/gpio.h"
#include "../../lib/TivaWare/inc/hw_memmap.h"
#include "peripherals/ha_per_PortF.h"
/*............................................................................*/
#define ha_LeftButton_port GPIO_PORTF_BASE
/*............................................................................*/
ha_LeftButton * ha_LeftButton_(void) {
    static ha_LeftButton self;
    return &self;
}
/*............................................................................*/
ha_LeftButton * ha_LeftButton_init(
    ha_LeftButton * const self
) {
    ha_Button_init(
        &self->_super.button,
        self,
        (ha_ButtonSetIntTypeBothEdges)ha_LeftButton_setIntTypeBothEdges,
        (ha_ButtonRegisterInt)ha_LeftButton_registerInt,
        (ha_ButtonUnregisterInt)ha_LeftButton_unregisterInt,
        (ha_ButtonEnableInt)ha_LeftButton_enableInt,
        (ha_ButtonDisableInt)ha_LeftButton_disableInt,
        (ha_ButtonClearIntFlag)ha_LeftButton_clearIntFlag,
        (ha_ButtonIsPressed)ha_LeftButton_isPressed
    );
    ha_per_PortF_init(ha_per_PortF_());
    GPIOPinTypeGPIOInput(ha_LeftButton_port, ha_LeftButton_pin);
    GPIOPadConfigSet(
        ha_LeftButton_port,
        ha_LeftButton_pin,
        GPIO_STRENGTH_2MA,
        GPIO_PIN_TYPE_STD_WPU
    );
    return self;
}
/*............................................................................*/
void ha_LeftButton_setIntTypeBothEdges(
    ha_LeftButton * const self
) {
    GPIOIntTypeSet(ha_LeftButton_port, ha_LeftButton_pin, GPIO_BOTH_EDGES);
}
/*............................................................................*/
void ha_LeftButton_registerInt(
    ha_LeftButton * const self,
    ha_InterruptHandler const intHandler
) {
    ha_per_PortF_registerLeftButtonInt(ha_per_PortF_(), intHandler);
}
/*............................................................................*/
void ha_LeftButton_unregisterInt(
    ha_LeftButton * const self
) {
    GPIOIntUnregister(ha_LeftButton_pin);
}
/*............................................................................*/
void ha_LeftButton_enableInt(
    ha_LeftButton * const self
) {
    GPIOIntEnable(ha_LeftButton_port, ha_LeftButton_pin);
}
/*............................................................................*/
void ha_LeftButton_disableInt(
    ha_LeftButton * const self
) {
    GPIOIntDisable(ha_LeftButton_port, ha_LeftButton_pin);
}
/*............................................................................*/
void ha_LeftButton_clearIntFlag(
    ha_LeftButton * const self
) {
    GPIOIntClear(ha_LeftButton_port, ha_LeftButton_pin);
}
/*............................................................................*/
bool ha_LeftButton_isPressed(
    ha_LeftButton * const self
) {
    return (GPIOPinRead(ha_LeftButton_port, ha_LeftButton_pin) == 0);
}
