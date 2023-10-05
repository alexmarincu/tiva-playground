/*............................................................................*/
#include "ha_Button.h"
/*............................................................................*/
ha_Button * ha_Button_init(
    ha_Button * const self,
    void * const child,
    ha_ButtonSetIntTypeBothEdges const setIntTypeBothEdges,
    ha_ButtonRegisterInt const registerInt,
    ha_ButtonUnregisterInt const unregisterInt,
    ha_ButtonEnableInt const enableInt,
    ha_ButtonDisableInt const disableInt,
    ha_ButtonClearIntFlag const clearIntFlag,
    ha_ButtonIsPressed const isPressed
) {
    self->_child = child;
    self->_setIntTypeBothEdges = setIntTypeBothEdges;
    self->_registerInt = registerInt;
    self->_unregisterInt = unregisterInt;
    self->_enableInt = enableInt;
    self->_disableInt = disableInt;
    self->_clearIntFlag = clearIntFlag;
    self->_isPressed = isPressed;
    return self;
}
/*............................................................................*/
void ha_Button_setIntTypeBothEdges(
    ha_Button * const self
) {
    self->_setIntTypeBothEdges(self->_child);
}
/*............................................................................*/
void ha_Button_registerInt(
    ha_Button * const self,
    ha_InterruptHandler const intHandler
) {
    self->_registerInt(self->_child, intHandler);
}
/*............................................................................*/
void ha_Button_unregisterInt(
    ha_Button * const self
) {
    self->_unregisterInt(self->_child);
}
/*............................................................................*/
void ha_Button_enableInt(
    ha_Button * const self
) {
    self->_enableInt(self->_child);
}
/*............................................................................*/
void ha_Button_disableInt(
    ha_Button * const self
) {
    self->_disableInt(self->_child);
}
/*............................................................................*/
void ha_Button_clearIntFlag(
    ha_Button * const self
) {
    self->_clearIntFlag(self->_child);
}
/*............................................................................*/
bool ha_Button_isPressed(
    ha_Button * const self
) {
    return self->_isPressed(self->_child);
}
