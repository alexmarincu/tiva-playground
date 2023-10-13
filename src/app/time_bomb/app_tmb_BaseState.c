/*............................................................................*/
#include "app_tmb_BaseState.h"
/*............................................................................*/
static void app_tmb_BaseState_onPauseTimeout_default(
    app_tmb_BaseState * const self
);
static void app_tmb_BaseState_onBlinkTimeout_default(
    app_tmb_BaseState * const self
);
static void app_tmb_BaseState_onRightButtonPress_default(
    app_tmb_BaseState * const self
);
static void app_tmb_BaseState_onLeftButtonPress_default(
    app_tmb_BaseState * const self
);
/*............................................................................*/
app_tmb_BaseState * app_tmb_BaseState_init(
    app_tmb_BaseState * const self,
    vsk_StateMachine * const stateMachine
) {
    vsk_State_init(
        &self->_super.state,
        stateMachine
    );
    self->_onBlinkTimeout = app_tmb_BaseState_onBlinkTimeout_default;
    self->_onPauseTimeout = app_tmb_BaseState_onPauseTimeout_default;
    self->_onRightButtonPress = app_tmb_BaseState_onRightButtonPress_default;
    self->_onLeftButtonPress = app_tmb_BaseState_onLeftButtonPress_default;
    return self;
}
/*............................................................................*/
static void app_tmb_BaseState_onPauseTimeout_default(
    app_tmb_BaseState * const self
) {
}
/*............................................................................*/
void app_tmb_BaseState_onPauseTimeout(
    app_tmb_BaseState * const self
) {
    self->_onPauseTimeout(self);
}
/*............................................................................*/
static void app_tmb_BaseState_onBlinkTimeout_default(
    app_tmb_BaseState * const self
) {
}
/*............................................................................*/
void app_tmb_BaseState_onBlinkTimeout(
    app_tmb_BaseState * const self
) {
    self->_onBlinkTimeout(self);
}
/*............................................................................*/
static void app_tmb_BaseState_onRightButtonPress_default(
    app_tmb_BaseState * const self
) {
}
/*............................................................................*/
void app_tmb_BaseState_onRightButtonPress(
    app_tmb_BaseState * const self
) {
    self->_onRightButtonPress(self);
}
/*............................................................................*/
static void app_tmb_BaseState_onLeftButtonPress_default(
    app_tmb_BaseState * const self
) {
}
/*............................................................................*/
void app_tmb_BaseState_onLeftButtonPress(
    app_tmb_BaseState * const self
) {
    self->_onLeftButtonPress(self);
}
