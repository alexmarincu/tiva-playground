/*............................................................................*/
#include "app_tmb_ArmedState.h"
#include "../../app/events/app_ev_RightButtonPressEvent.h"
#include "app_tmb_DefusedState.h"
/*............................................................................*/
static void app_tmb_ArmedState_setupEventSubscribers(
    app_tmb_ArmedState * const self
);
static void app_tmb_ArmedState_onRightButtonPress(
    app_tmb_ArmedState * const self
);
static void app_tmb_ArmedState_onEntry(
    app_tmb_ArmedState * const self
);
static void app_tmb_ArmedState_onExit(
    app_tmb_ArmedState * const self
);
/*............................................................................*/
app_tmb_ArmedState * app_tmb_ArmedState_(void) {
    static app_tmb_ArmedState self;
    return &self;
}
/*............................................................................*/
static void app_tmb_ArmedState_setupEventSubscribers(
    app_tmb_ArmedState * const self
) {
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_RightButtonPressEvent_(),
        vsk_EventSubscriber_init(
            &self->_eventSubscribers.rightButtonPress,
            vsk_StateMachine_getTask(self->_state._stateMachine),
            self,
            (vsk_MessageHandler)app_tmb_ArmedState_onRightButtonPress
        )
    );
}
/*............................................................................*/
app_tmb_ArmedState * app_tmb_ArmedState_init(
    app_tmb_ArmedState * const self,
    vsk_StateMachine * const stateMachine
) {
    vsk_State_init(
        &self->_state,
        stateMachine,
        (vsk_StateOnEntry)app_tmb_ArmedState_onEntry,
        (vsk_StateOnExit)app_tmb_ArmedState_onExit
    );
    app_tmb_ArmedState_setupEventSubscribers(self);
    return self;
}
/*............................................................................*/
static void app_tmb_ArmedState_onRightButtonPress(
    app_tmb_ArmedState * const self
) {
    if (vsk_State_isActive((vsk_State *)self)) {
        vsk_StateMachine_transition(
            self->_state._stateMachine,
            (vsk_State *)app_tmb_DefusedState_()
        );
    }
}
/*............................................................................*/
static void app_tmb_ArmedState_onEntry(
    app_tmb_ArmedState * const self
) {
}
/*............................................................................*/
static void app_tmb_ArmedState_onExit(
    app_tmb_ArmedState * const self
) {
}
