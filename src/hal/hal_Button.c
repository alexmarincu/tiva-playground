#include "hal_Button.h"

hal_Button * hal_Button_init(
    hal_Button * const self,
    void * const impl,
    hal_ButtonRegisterInt const registerInt,
    hal_ButtonUnregisterInt const unregisterInt,
    hal_ButtonEnableInt const enableInt,
    hal_ButtonDisableInt const disableInt
) {
    self->impl = impl;
    self->registerInt = registerInt;
    self->unregisterInt = unregisterInt;
    self->enableInt = enableInt;
    self->disableInt = disableInt;
    return self;
}

void hal_Button_registerInt(hal_Button * const self, void (*const fun)(void)) {
    self->registerInt(self->impl, fun);
}

void hal_Button_unregisterInt(hal_Button * const self) {
    self->unregisterInt(self->impl);
}
void hal_Button_enableInt(hal_Button * const self) {
    self->enableInt(self->impl);
}
void hal_Button_disableInt(hal_Button * const self) {
    self->disableInt(self->impl);
}
