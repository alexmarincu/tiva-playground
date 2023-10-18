/*............................................................................*/
#include "app_blk_OnState.h"
#include "../../hw_abstraction/ha_Led.h"
#include "app_blk_BlinkyActObj.h"
#include "app_blk_OffState.h"
/*............................................................................*/
static void app_blk_OnState_onEnter(
    app_blk_OnState * const self
);
static void app_blk_OnState_onExit(
    app_blk_OnState * const self
);
static void app_blk_OnState_onOnTimeout(
    app_blk_OnState * const self
);
/*............................................................................*/
app_blk_OnState * app_blk_OnState_(void) {
    static app_blk_OnState self;
    return &self;
}
/*............................................................................*/
app_blk_OnState * app_blk_OnState_init(
    app_blk_OnState * const self,
    vsk_StateMachine * const stateMachine
) {
    app_blk_BaseState_init(
        &self->_super.baseState,
        stateMachine
    );
    self->_super.baseState._super.state._onEnter =
        (vsk_StateOnEnter)app_blk_OnState_onEnter;
    self->_super.baseState._super.state._onExit =
        (vsk_StateOnExit)app_blk_OnState_onExit;
    self->_super.baseState._onOnTimeout =
        (app_blk_BaseStateHandler)app_blk_OnState_onOnTimeout;
    return self;
}
/*............................................................................*/
static void app_blk_OnState_onEnter(
    app_blk_OnState * const self
) {
    ha_Led_setBlueOn();
    vsk_EventTimer_arm(
        app_blk_BlinkyActObj_getOnTimeoutEventTimer(
            (app_blk_BlinkyActObj *)
                self->_super.baseState._super.state._stateMachine
        ),
        200,
        0
    );
}
/*............................................................................*/
static void app_blk_OnState_onExit(
    app_blk_OnState * const self
) {
    ha_Led_setBlueOff();
}
/*............................................................................*/
static void app_blk_OnState_onOnTimeout(
    app_blk_OnState * const self
) {
    vsk_StateMachine_transition(
        self->_super.baseState._super.state._stateMachine,
        (vsk_State *)app_blk_OffState_()
    );
}
