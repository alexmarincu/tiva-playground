/*----------------------------------------------------------------------------*/
#include "ha_RightButton.h"
/*----------------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>
/*----------------------------------------------------------------------------*/
#include "../../lib/TivaWare/driverlib/gpio.h"
#include "../../lib/TivaWare/inc/hw_memmap.h"
#include "peripherals/ha_per_PortF.h"
/*----------------------------------------------------------------------------*/
#define ha_per_PortF_rightButtonPin GPIO_PIN_0
/*----------------------------------------------------------------------------*/
ha_RightButton * ha_RightButton_(void) {
    static ha_RightButton self;
    return &self;
}
/*----------------------------------------------------------------------------*/
ha_RightButton * ha_RightButton_init(ha_RightButton * const self) {
    ha_Button_init(
        (ha_Button *)self,
        (ha_ButtonSetIntTypeBothEdges)ha_RightButton_setIntTypeBothEdges,
        (ha_ButtonRegisterInt)ha_RightButton_registerInt,
        (ha_ButtonUnregisterInt)ha_RightButton_unregisterInt,
        (ha_ButtonEnableInt)ha_RightButton_enableInt,
        (ha_ButtonDisableInt)ha_RightButton_disableInt,
        (ha_ButtonClearIntFlag)ha_RightButton_clearIntFlag,
        (ha_ButtonIsPressed)ha_RightButton_isPressed
    );
    ha_per_PortF_init(ha_per_PortF_());
    GPIOUnlockPin(GPIO_PORTF_BASE, ha_per_PortF_rightButtonPin);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, ha_per_PortF_rightButtonPin);
    GPIOPadConfigSet(
        GPIO_PORTF_BASE,
        ha_per_PortF_rightButtonPin,
        GPIO_STRENGTH_2MA,
        GPIO_PIN_TYPE_STD_WPU
    );
    return self;
}
/*----------------------------------------------------------------------------*/
void ha_RightButton_setIntTypeBothEdges(ha_RightButton * const self) {
    GPIOIntTypeSet(
        GPIO_PORTF_BASE, ha_per_PortF_rightButtonPin, GPIO_BOTH_EDGES
    );
}
/*----------------------------------------------------------------------------*/
void ha_RightButton_registerInt(
    ha_RightButton * const self, ha_InterruptHandler const intHandler
) {
    ha_per_PortF_registerRightButtonInt(ha_per_PortF_(), intHandler);
}
/*----------------------------------------------------------------------------*/
void ha_RightButton_unregisterInt(ha_RightButton * const self) {
    GPIOIntUnregister(GPIO_PORTF_BASE);
}
/*----------------------------------------------------------------------------*/
void ha_RightButton_enableInt(ha_RightButton * const self) {
    GPIOIntEnable(GPIO_PORTF_BASE, ha_per_PortF_rightButtonPin);
}
/*----------------------------------------------------------------------------*/
void ha_RightButton_disableInt(ha_RightButton * const self) {
    GPIOIntDisable(GPIO_PORTF_BASE, ha_per_PortF_rightButtonPin);
}
/*----------------------------------------------------------------------------*/
void ha_RightButton_clearIntFlag(ha_RightButton * const self) {
    GPIOIntClear(GPIO_PORTF_BASE, ha_per_PortF_rightButtonPin);
}
/*----------------------------------------------------------------------------*/
bool ha_RightButton_isPressed(ha_RightButton * const self) {
    return (GPIOPinRead(GPIO_PORTF_BASE, ha_per_PortF_rightButtonPin) == 0);
}
