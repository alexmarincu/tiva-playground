#ifndef HAL_BUTTON_H
#define HAL_BUTTON_H
#include <stdbool.h>

typedef struct hal_Button hal_Button;
typedef void (*hal_ButtonSetIntTypeBothEdges)(hal_Button * const self);
typedef void (*hal_ButtonRegisterInt)(hal_Button * const self, void (*const fun)(void));
typedef void (*hal_ButtonUnregisterInt)(hal_Button * const self);
typedef void (*hal_ButtonEnableInt)(hal_Button * const self);
typedef void (*hal_ButtonDisableInt)(hal_Button * const self);
typedef void (*hal_ButtonClearIntFlag)(hal_Button * const self);
typedef bool (*hal_ButtonIsPressed)(hal_Button * const self);
struct hal_Button {
    void * impl;
    hal_ButtonSetIntTypeBothEdges setIntTypeBothEdges;
    hal_ButtonRegisterInt registerInt;
    hal_ButtonUnregisterInt unregisterInt;
    hal_ButtonEnableInt enableInt;
    hal_ButtonDisableInt disableInt;
    hal_ButtonClearIntFlag clearIntFlag;
    hal_ButtonIsPressed isPressed;
};

hal_Button * hal_Button_init(
    hal_Button * const self,
    void * const impl,
    hal_ButtonSetIntTypeBothEdges const setIntTypeBothEdges,
    hal_ButtonRegisterInt const registerInt,
    hal_ButtonUnregisterInt const unregisterInt,
    hal_ButtonEnableInt const enableInt,
    hal_ButtonDisableInt const disableInt,
    hal_ButtonClearIntFlag const clearIntFlag,
    hal_ButtonIsPressed const isPressed
);
void hal_Button_setIntTypeBothEdges(hal_Button * const self);
void hal_Button_registerInt(hal_Button * const self, void (*const fun)(void));
void hal_Button_unregisterInt(hal_Button * const self);
void hal_Button_enableInt(hal_Button * const self);
void hal_Button_disableInt(hal_Button * const self);
void hal_Button_clearIntFlag(hal_Button * const self);
bool hal_Button_isPressed(hal_Button * const self);

#endif // HAL_BUTTON_H
