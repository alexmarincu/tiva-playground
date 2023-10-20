/*............................................................................*/
#include "app_tmb_TimeBombState.h"
/*............................................................................*/
static void app_tmb_TimeBombState_onPauseTimeout_default(
    app_tmb_TimeBombState * const self
);
static void app_tmb_TimeBombState_onBlinkTimeout_default(
    app_tmb_TimeBombState * const self
);
static void app_tmb_TimeBombState_onRightButtonPress_default(
    app_tmb_TimeBombState * const self
);
static void app_tmb_TimeBombState_onLeftButtonPress_default(
    app_tmb_TimeBombState * const self
);
/*............................................................................*/
app_tmb_TimeBombState * app_tmb_TimeBombState_init(
    app_tmb_TimeBombState * const self, vsk_StateContext * const stateContext
) {
    vsk_State_init((vsk_State *)self, stateContext);
    self->_onBlinkTimeout = app_tmb_TimeBombState_onBlinkTimeout_default;
    self->_onPauseTimeout = app_tmb_TimeBombState_onPauseTimeout_default;
    self->_onRightButtonPress =
        app_tmb_TimeBombState_onRightButtonPress_default;
    self->_onLeftButtonPress = app_tmb_TimeBombState_onLeftButtonPress_default;
    return self;
}
/*............................................................................*/
static void app_tmb_TimeBombState_onPauseTimeout_default(
    app_tmb_TimeBombState * const self
) {
}
/*............................................................................*/
void app_tmb_TimeBombState_onPauseTimeout(app_tmb_TimeBombState * const self) {
    self->_onPauseTimeout(self);
}
/*............................................................................*/
static void app_tmb_TimeBombState_onBlinkTimeout_default(
    app_tmb_TimeBombState * const self
) {
}
/*............................................................................*/
void app_tmb_TimeBombState_onBlinkTimeout(app_tmb_TimeBombState * const self) {
    self->_onBlinkTimeout(self);
}
/*............................................................................*/
static void app_tmb_TimeBombState_onRightButtonPress_default(
    app_tmb_TimeBombState * const self
) {
}
/*............................................................................*/
void app_tmb_TimeBombState_onRightButtonPress(
    app_tmb_TimeBombState * const self
) {
    self->_onRightButtonPress(self);
}
/*............................................................................*/
static void app_tmb_TimeBombState_onLeftButtonPress_default(
    app_tmb_TimeBombState * const self
) {
}
/*............................................................................*/
void app_tmb_TimeBombState_onLeftButtonPress(
    app_tmb_TimeBombState * const self
) {
    self->_onLeftButtonPress(self);
}
