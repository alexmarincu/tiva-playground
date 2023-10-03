/*............................................................................*/
#include "app_tmb_BlinkState.h"
#include "../../app/events/app_ev_BlinkTimeoutEvent.h"
#include "../../hw_abstraction/ha_Led.h"
#include "app_tmb_PauseState.h"
/*............................................................................*/
static void app_tmb_BlinkState_setupEventSubscribers(
    app_tmb_BlinkState * const self
);
static void app_tmb_BlinkState_onBlinkTimeout(
    app_tmb_BlinkState * const self
);
static void app_tmb_BlinkState_onEntry(
    app_tmb_BlinkState * const self
);
static void app_tmb_BlinkState_onExit(
    app_tmb_BlinkState * const self
);
app_tmb_BlinkState * app_tmb_BlinkState_(void) {
    static app_tmb_BlinkState self;
    return &self;
}
/*............................................................................*/
static void app_tmb_BlinkState_setupEventSubscribers(
    app_tmb_BlinkState * const self
) {
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_BlinkTimeoutEvent_(),
        vsk_EventSubscriber_init(
            &self->_eventSubscribers.blinkTimeout,
            vsk_StateMachine_getTask(self->_state._stateMachine),
            self,
            (vsk_MessageHandler)app_tmb_BlinkState_onBlinkTimeout
        )
    );
}
/*............................................................................*/
app_tmb_BlinkState * app_tmb_BlinkState_init(
    app_tmb_BlinkState * const self,
    vsk_StateMachine * const stateMachine
) {
    vsk_State_init(
        &self->_state,
        stateMachine,
        (vsk_StateOnEntry)app_tmb_BlinkState_onEntry,
        (vsk_StateOnExit)app_tmb_BlinkState_onExit
    );
    app_tmb_BlinkState_setupEventSubscribers(self);
    vsk_EventTimer_init(
        &self->_blinkTimeoutEventTimer,
        (vsk_Event *)app_ev_BlinkTimeoutEvent_()
    );
    return self;
}
/*............................................................................*/
static void app_tmb_BlinkState_onBlinkTimeout(
    app_tmb_BlinkState * const self
) {
    vsk_StateMachine_transition(
        self->_state._stateMachine,
        (vsk_State *)app_tmb_PauseState_()
    );
}
/*............................................................................*/
static void app_tmb_BlinkState_onEntry(
    app_tmb_BlinkState * const self
) {
    ha_Led_setRedOn();
    vsk_EventTimer_arm(
        &self->_blinkTimeoutEventTimer,
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
