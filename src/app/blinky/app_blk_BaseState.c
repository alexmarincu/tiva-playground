/*............................................................................*/
#include "app_blk_BaseState.h"
/*............................................................................*/
static void app_blk_BaseState_onOnTimeout_default(
    app_blk_BaseState * const self
);
static void app_blk_BaseState_onOffTimeout_default(
    app_blk_BaseState * const self
);
/*............................................................................*/
app_blk_BaseState * app_blk_BaseState_init(
    app_blk_BaseState * const self,
    vsk_StateMachine * const stateMachine
) {
    vsk_State_init(
        &self->_super.state,
        stateMachine
    );
    self->_onOffTimeout = app_blk_BaseState_onOffTimeout_default;
    self->_onOnTimeout = app_blk_BaseState_onOnTimeout_default;
    return self;
}
/*............................................................................*/
static void app_blk_BaseState_onOnTimeout_default(
    app_blk_BaseState * const self
) {
}
/*............................................................................*/
void app_blk_BaseState_onOnTimeout(
    app_blk_BaseState * const self
) {
    self->_onOnTimeout(self);
}
/*............................................................................*/
static void app_blk_BaseState_onOffTimeout_default(
    app_blk_BaseState * const self
) {
}
/*............................................................................*/
void app_blk_BaseState_onOffTimeout(
    app_blk_BaseState * const self
) {
    self->_onOffTimeout(self);
}
