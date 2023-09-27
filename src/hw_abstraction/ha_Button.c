#include "ha_Button.h"

ha_Button * ha_Button_init(
    ha_Button * const self,
    void * const impl,
    ha_ButtonSetIntTypeBothEdges const setIntTypeBothEdges,
    ha_ButtonRegisterInt const registerInt,
    ha_ButtonUnregisterInt const unregisterInt,
    ha_ButtonEnableInt const enableInt,
    ha_ButtonDisableInt const disableInt,
    ha_ButtonClearIntFlag const clearIntFlag,
    ha_ButtonIsPressed const isPressed
) {
    self->impl = impl;
    self->setIntTypeBothEdges = setIntTypeBothEdges;
    self->registerInt = registerInt;
    self->unregisterInt = unregisterInt;
    self->enableInt = enableInt;
    self->disableInt = disableInt;
    self->clearIntFlag = clearIntFlag;
    self->isPressed = isPressed;
    return self;
}

void ha_Button_setIntTypeBothEdges(ha_Button * const self) {
    self->setIntTypeBothEdges(self->impl);
}

void ha_Button_registerInt(ha_Button * const self, ha_InterruptHandler const intHandler) {
    self->registerInt(self->impl, intHandler);
}

void ha_Button_unregisterInt(ha_Button * const self) {
    self->unregisterInt(self->impl);
}

void ha_Button_enableInt(ha_Button * const self) {
    self->enableInt(self->impl);
}

void ha_Button_disableInt(ha_Button * const self) {
    self->disableInt(self->impl);
}

void ha_Button_clearIntFlag(ha_Button * const self) {
    self->clearIntFlag(self->impl);
}

bool ha_Button_isPressed(ha_Button * const self) {
    return self->isPressed(self->impl);
}
