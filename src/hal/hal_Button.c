#include "hal_Button.h"

hal_Button * hal_Button_init(
    hal_Button * const self,
    void * const impl,
    hal_Button_intRegisterFun const intRegister,
    hal_Button_intUnregisterFun const intUnregister,
    hal_Button_intEnableFun const intEnable,
    hal_Button_intDisableFun const intDisable
) {
    self->impl = impl;
    self->intRegister = intRegister;
    self->intUnregister = intUnregister;
    self->intEnable = intEnable;
    self->intDisable = intDisable;
    return self;
}

void hal_Button_intRegister(hal_Button * const self, void (*const fun)(void)) {
    self->intRegister(self->impl, fun);
}

void hal_Button_intUnregister(hal_Button * const self) {
    self->intUnregister(self->impl);
}
void hal_Button_intEnable(hal_Button * const self) {
    self->intEnable(self->impl);
}
void hal_Button_intDisable(hal_Button * const self) {
    self->intDisable(self->impl);
}
