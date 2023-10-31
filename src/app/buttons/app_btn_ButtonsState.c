/*............................................................................*/
#include "app_btn_ButtonsState.h"
/*............................................................................*/
static void app_btn_ButtonsState_onRightButtonInt_default(
    app_btn_ButtonsState * const self
);
static void app_btn_ButtonsState_onLeftButtonInt_default(
    app_btn_ButtonsState * const self
);
static void app_btn_ButtonsState_onDebounceTimeout_default(
    app_btn_ButtonsState * const self
);
/*............................................................................*/
app_btn_ButtonsState * app_btn_ButtonsState_init(
    app_btn_ButtonsState * const self, vsk_StateContext * const stateContext
) {
    vsk_State_init((vsk_State *)self, stateContext);
    self->_onLeftButtonInt = app_btn_ButtonsState_onLeftButtonInt_default;
    self->_onRightButtonInt = app_btn_ButtonsState_onRightButtonInt_default;
    self->_onDebounceTimeout = app_btn_ButtonsState_onDebounceTimeout_default;
    return self;
}
/*............................................................................*/
static void app_btn_ButtonsState_onLeftButtonInt_default(
    app_btn_ButtonsState * const self
) {
}
/*............................................................................*/
void app_btn_ButtonsState_onLeftButtonInt(app_btn_ButtonsState * const self) {
    self->_onLeftButtonInt(self);
}
/*............................................................................*/
static void app_btn_ButtonsState_onRightButtonInt_default(
    app_btn_ButtonsState * const self
) {
}
/*............................................................................*/
void app_btn_ButtonsState_onRightButtonInt(app_btn_ButtonsState * const self) {
    self->_onRightButtonInt(self);
}
/*............................................................................*/
static void app_btn_ButtonsState_onDebounceTimeout_default(
    app_btn_ButtonsState * const self
) {
}
/*............................................................................*/
void app_btn_ButtonsState_onDebounceTimeout(app_btn_ButtonsState * const self) {
    self->_onDebounceTimeout(self);
}
