#ifndef HAL_BUTTON_H
#define HAL_BUTTON_H

typedef struct hal_Button hal_Button;
typedef void (*hal_Button_intRegisterFun)(hal_Button * const self, void (*const fun)(void));
typedef void (*hal_Button_intUnregisterFun)(hal_Button * const self);
typedef void (*hal_Button_intEnableFun)(hal_Button * const self);
typedef void (*hal_Button_intDisableFun)(hal_Button * const self);
struct hal_Button {
    void * impl;
    hal_Button_intRegisterFun intRegister;
    hal_Button_intUnregisterFun intUnregister;
    hal_Button_intEnableFun intEnable;
    hal_Button_intDisableFun intDisable;
};

hal_Button * hal_Button_init(
    hal_Button * const self,
    void * const impl,
    hal_Button_intRegisterFun const intRegister,
    hal_Button_intUnregisterFun const intUnregister,
    hal_Button_intEnableFun const intEnable,
    hal_Button_intDisableFun const intDisable
);
void hal_Button_intRegister(hal_Button * const self, void (*const fun)(void));
void hal_Button_intUnregister(hal_Button * const self);
void hal_Button_intEnable(hal_Button * const self);
void hal_Button_intDisable(hal_Button * const self);

#endif // HAL_BUTTON_H
