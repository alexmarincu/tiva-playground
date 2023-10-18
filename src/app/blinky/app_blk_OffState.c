/*............................................................................*/
#include "app_blk_OffState.h"
#include "app_blk_BlinkyActObj.h"
#include "app_blk_OnState.h"
/*............................................................................*/
static void app_blk_OffState_onEnter(
    app_blk_OffState * const self
);
static void app_blk_OnState_onOffTimeout(
    app_blk_OffState * const self
);
/*............................................................................*/
app_blk_OffState * app_blk_OffState_(void) {
    static app_blk_OffState self;
    return &self;
}
/*............................................................................*/
app_blk_OffState * app_blk_OffState_init(
    app_blk_OffState * const self,
    vsk_StateMachine * const stateMachine
) {
    app_blk_BaseState_init(
        &self->_super.baseState,
        stateMachine
    );
    self->_super.baseState._super.state._onEnter =
        (vsk_StateOnEnter)app_blk_OffState_onEnter;
    self->_super.baseState._onOffTimeout =
        (app_blk_BaseStateHandler)app_blk_OnState_onOffTimeout;
    return self;
}
/*............................................................................*/
static void app_blk_OffState_onEnter(
    app_blk_OffState * const self
) {
    vsk_Timer_arm(
        (vsk_Timer *)app_blk_BlinkyActObj_getOffTimeoutEventTimer(
            (app_blk_BlinkyActObj *)
                self->_super.baseState._super.state._stateMachine
        ),
        200,
        0
    );
}
/*............................................................................*/
static void app_blk_OnState_onOffTimeout(
    app_blk_OffState * const self
) {
    vsk_StateMachine_transition(
        self->_super.baseState._super.state._stateMachine,
        (vsk_State *)app_blk_OnState_()
    );
}
