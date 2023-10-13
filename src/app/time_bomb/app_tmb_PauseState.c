/*............................................................................*/
#include "app_tmb_PauseState.h"
#include "app_tmb_BlinkState.h"
#include "app_tmb_BoomState.h"
#include "app_tmb_TimeBombActObj.h"
/*............................................................................*/
static void app_tmb_PauseState_onEnter(
    app_tmb_PauseState * const self
);
static void app_tmb_PauseState_onPauseTimeout(
    app_tmb_PauseState * const self
);
/*............................................................................*/
app_tmb_PauseState * app_tmb_PauseState_(void) {
    static app_tmb_PauseState self;
    return &self;
}
/*............................................................................*/
app_tmb_PauseState * app_tmb_PauseState_init(
    app_tmb_PauseState * const self,
    vsk_StateMachine * const stateMachine
) {
    app_tmb_ArmedState_init(
        &self->_super.armedState,
        stateMachine
    );
    self->_super.armedState._super.baseState._super.state._onEnter =
        (vsk_StateOnEnter)app_tmb_PauseState_onEnter;
    self->_super.armedState._super.baseState._onPauseTimeout =
        (app_tmb_BaseStateHandler)app_tmb_PauseState_onPauseTimeout;
    return self;
}
/*............................................................................*/
static void app_tmb_PauseState_onEnter(
    app_tmb_PauseState * const self
) {
    vsk_EventTimer_arm(
        app_tmb_TimeBombActObj_getPauseTimeoutEventTimer(
            (app_tmb_TimeBombActObj *)
                self->_super.armedState._super.baseState._super.state._stateMachine
        ),
        500,
        0
    );
}
/*............................................................................*/
static void app_tmb_PauseState_onPauseTimeout(
    app_tmb_PauseState * const self
) {
    app_tmb_TimeBombActObj_decrementBlinkCounter(
        (app_tmb_TimeBombActObj *)
            self->_super.armedState._super.baseState._super.state._stateMachine
    );
    if (
        app_tmb_TimeBombActObj_getBlinkCounter(
            (app_tmb_TimeBombActObj *)
                self->_super.armedState._super.baseState._super.state._stateMachine
        ) > 0
    ) {
        vsk_StateMachine_transition(
            self->_super.armedState._super.baseState._super.state._stateMachine,
            (vsk_State *)app_tmb_BlinkState_()
        );
    } else {
        vsk_StateMachine_transition(
            self->_super.armedState._super.baseState._super.state._stateMachine,
            (vsk_State *)app_tmb_BoomState_()
        );
    }
}
