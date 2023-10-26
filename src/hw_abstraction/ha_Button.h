/*............................................................................*/
#ifndef HA_BUTTON_H
#define HA_BUTTON_H
/*............................................................................*/
typedef struct ha_Button ha_Button;
/*............................................................................*/
#include <stdbool.h>
/*............................................................................*/
#include "ha_Interrupt.h"
/*............................................................................*/
typedef void (*ha_ButtonSetIntTypeBothEdges)(ha_Button * const self);
typedef void (*ha_ButtonRegisterInt)(
    ha_Button * const self, ha_InterruptHandler const intHandler
);
typedef void (*ha_ButtonUnregisterInt)(ha_Button * const self);
typedef void (*ha_ButtonEnableInt)(ha_Button * const self);
typedef void (*ha_ButtonDisableInt)(ha_Button * const self);
typedef void (*ha_ButtonClearIntFlag)(ha_Button * const self);
typedef bool (*ha_ButtonIsPressed)(ha_Button * const self);
/*............................................................................*/
struct ha_Button {
    ha_ButtonSetIntTypeBothEdges _setIntTypeBothEdges;
    ha_ButtonRegisterInt _registerInt;
    ha_ButtonUnregisterInt _unregisterInt;
    ha_ButtonEnableInt _enableInt;
    ha_ButtonDisableInt _disableInt;
    ha_ButtonClearIntFlag _clearIntFlag;
    ha_ButtonIsPressed _isPressed;
};
/*............................................................................*/
ha_Button * ha_Button_init(
    ha_Button * const self,
    ha_ButtonSetIntTypeBothEdges const setIntTypeBothEdges,
    ha_ButtonRegisterInt const registerInt,
    ha_ButtonUnregisterInt const unregisterInt,
    ha_ButtonEnableInt const enableInt,
    ha_ButtonDisableInt const disableInt,
    ha_ButtonClearIntFlag const clearIntFlag,
    ha_ButtonIsPressed const isPressed
);
void ha_Button_setIntTypeBothEdges(ha_Button * const self);
void ha_Button_registerInt(
    ha_Button * const self, ha_InterruptHandler const intHandler
);
void ha_Button_unregisterInt(ha_Button * const self);
void ha_Button_enableInt(ha_Button * const self);
void ha_Button_disableInt(ha_Button * const self);
void ha_Button_clearIntFlag(ha_Button * const self);
bool ha_Button_isPressed(ha_Button * const self);
#endif // HA_BUTTON_H
