#ifndef HAL_BUTTON_H
#define HAL_BUTTON_H

typedef struct hal_Button hal_Button;
typedef void (*hal_ButtonRegisterInt)(hal_Button * const self, void (*const fun)(void));
typedef void (*hal_ButtonUnregisterInt)(hal_Button * const self);
typedef void (*hal_ButtonEnableInt)(hal_Button * const self);
typedef void (*hal_ButtonDisableInt)(hal_Button * const self);
struct hal_Button {
    void * impl;
    hal_ButtonRegisterInt registerInt;
    hal_ButtonUnregisterInt unregisterInt;
    hal_ButtonEnableInt enableInt;
    hal_ButtonDisableInt disableInt;
};

hal_Button * hal_Button_init(
    hal_Button * const self,
    void * const impl,
    hal_ButtonRegisterInt const registerInt,
    hal_ButtonUnregisterInt const unregisterInt,
    hal_ButtonEnableInt const enableInt,
    hal_ButtonDisableInt const disableInt
);
void hal_Button_registerInt(hal_Button * const self, void (*const fun)(void));
void hal_Button_unregisterInt(hal_Button * const self);
void hal_Button_enableInt(hal_Button * const self);
void hal_Button_disableInt(hal_Button * const self);

#endif // HAL_BUTTON_H
