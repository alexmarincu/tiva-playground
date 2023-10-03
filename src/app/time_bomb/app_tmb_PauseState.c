/*............................................................................*/
#include "app_tmb_PauseState.h"
#include "../../app/events/app_ev_PauseTimeoutEvent.h"
#include "../../hw_abstraction/ha_Led.h"
#include "app_tmb_BlinkState.h"
#include "app_tmb_BoomState.h"
#include "app_tmb_TimeBombTask.h"
/*............................................................................*/
static void app_tmb_PauseState_setupEventSubscribers(
    app_tmb_PauseState * const self
);
static void app_tmb_PauseState_onPauseTimeout(
    app_tmb_PauseState * const self
);
static void app_tmb_PauseState_onEntry(
    app_tmb_PauseState * const self
);
static void app_tmb_PauseState_onExit(
    app_tmb_PauseState * const self
);
/*............................................................................*/
app_tmb_PauseState * app_tmb_PauseState_(void) {
    static app_tmb_PauseState self;
    return &self;
}
/*............................................................................*/
static void app_tmb_PauseState_setupEventSubscribers(
    app_tmb_PauseState * const self
) {
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_PauseTimeoutEvent_(),
        vsk_EventSubscriber_init(
            &self->_eventSubscribers.pauseTimeout,
            vsk_StateMachine_getTask(self->_state._stateMachine),
            self,
            (vsk_MessageHandler)app_tmb_PauseState_onPauseTimeout
        )
    );
}
/*............................................................................*/
app_tmb_PauseState * app_tmb_PauseState_init(
    app_tmb_PauseState * const self,
    vsk_StateMachine * const stateMachine
) {
    vsk_State_init(
        &self->_state,
        stateMachine,
        (vsk_StateOnEntry)app_tmb_PauseState_onEntry,
        (vsk_StateOnExit)app_tmb_PauseState_onExit
    );
    app_tmb_PauseState_setupEventSubscribers(self);
    vsk_EventTimer_init(
        &self->_pauseTimeoutEventTimer,
        (vsk_Event *)app_ev_PauseTimeoutEvent_()
    );
    return self;
}
/*............................................................................*/
static void app_tmb_PauseState_onPauseTimeout(
    app_tmb_PauseState * const self
) {
    app_tmb_TimeBombTask_decrementBlinkCounter(
        (app_tmb_TimeBombTask *)self->_state._stateMachine->_task
    );
    if (
        app_tmb_TimeBombTask_getBlinkCounter(
            (app_tmb_TimeBombTask *)self->_state._stateMachine->_task
        ) > 0
    ) {
        vsk_StateMachine_transition(
            self->_state._stateMachine,
            (vsk_State *)app_tmb_BlinkState_()
        );
    } else {
        vsk_StateMachine_transition(
            self->_state._stateMachine,
            (vsk_State *)app_tmb_BoomState_()
        );
    }
}
/*............................................................................*/
static void app_tmb_PauseState_onEntry(
    app_tmb_PauseState * const self
) {
    vsk_EventTimer_arm(
        &self->_pauseTimeoutEventTimer,
        500,
        0
    );
}
/*............................................................................*/
static void app_tmb_PauseState_onExit(
    app_tmb_PauseState * const self
) {
}
