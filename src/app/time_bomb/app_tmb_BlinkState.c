/*............................................................................*/
#include "app_tmb_BlinkState.h"
#include "../../hw_abstraction/ha_Led.h"
#include "app_tmb_PauseState.h"
#include "app_tmb_TimeBombActObj.h"
/*............................................................................*/
static void app_tmb_BlinkState_onEnter(
    app_tmb_BlinkState * const self
);
static void app_tmb_BlinkState_onExit(
    app_tmb_BlinkState * const self
);
static void app_tmb_BlinkState_onBlinkTimeout(
    app_tmb_BlinkState * const self
);
/*............................................................................*/
app_tmb_BlinkState * app_tmb_BlinkState_(void) {
    static app_tmb_BlinkState self;
    return &self;
}
/*............................................................................*/
app_tmb_BlinkState * app_tmb_BlinkState_init(
    app_tmb_BlinkState * const self,
    vsk_StateMachine * const stateMachine
) {
    app_tmb_ArmedState_init(
        &self->_super.armedState,
        stateMachine
    );
    self->_super.armedState._super.baseState._super.state._onEnter =
        (vsk_StateOnEnter)app_tmb_BlinkState_onEnter;
    self->_super.armedState._super.baseState._super.state._onExit =
        (vsk_StateExit)app_tmb_BlinkState_onExit;
    self->_super.armedState._super.baseState._onBlinkTimeout =
        (app_tmb_BaseStateHandler)app_tmb_BlinkState_onBlinkTimeout;
    return self;
}
/*............................................................................*/
static void app_tmb_BlinkState_onEnter(
    app_tmb_BlinkState * const self
) {
    ha_Led_setRedOn();
    vsk_EventTimer_arm(
        app_tmb_TimeBombActObj_getBlinkTimeoutEventTimer(
            (app_tmb_TimeBombActObj *)
                self->_super.armedState._super.baseState._super.state._stateMachine
        ),
        500,
        0
    );
}
/*............................................................................*/
static void app_tmb_BlinkState_onExit(
    app_tmb_BlinkState * const self
) {
    ha_Led_setRedOff();
}
/*............................................................................*/
static void app_tmb_BlinkState_onBlinkTimeout(
    app_tmb_BlinkState * const self
) {
    vsk_StateMachine_transition(
        self->_super.armedState._super.baseState._super.state._stateMachine,
        (vsk_State *)app_tmb_PauseState_()
    );
}
