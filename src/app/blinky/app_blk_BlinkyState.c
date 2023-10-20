/*............................................................................*/
#include "app_blk_BlinkyState.h"
/*............................................................................*/
static void app_blk_BlinkyState_onOnTimeout_default(
    app_blk_BlinkyState * const self
);
static void app_blk_BlinkyState_onOffTimeout_default(
    app_blk_BlinkyState * const self
);
/*............................................................................*/
app_blk_BlinkyState * app_blk_BlinkyState_init(
    app_blk_BlinkyState * const self,
    vsk_StateContext * const stateContext
) {
    vsk_State_init((vsk_State *)self, stateContext);
    self->_onOffTimeout = app_blk_BlinkyState_onOffTimeout_default;
    self->_onOnTimeout = app_blk_BlinkyState_onOnTimeout_default;
    return self;
}
/*............................................................................*/
static void app_blk_BlinkyState_onOnTimeout_default(
    app_blk_BlinkyState * const self
) {
}
/*............................................................................*/
void app_blk_BlinkyState_onOnTimeout(
    app_blk_BlinkyState * const self
) {
    self->_onOnTimeout(self);
}
/*............................................................................*/
static void app_blk_BlinkyState_onOffTimeout_default(
    app_blk_BlinkyState * const self
) {
}
/*............................................................................*/
void app_blk_BlinkyState_onOffTimeout(
    app_blk_BlinkyState * const self
) {
    self->_onOffTimeout(self);
}
