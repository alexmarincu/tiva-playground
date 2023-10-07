/*............................................................................*/
#include "app_tmb_TimeBombActObj.h"
#include "../../app/events/app_ev_OnStartEvent.h"
#include "app_tmb_BlinkState.h"
#include "app_tmb_BoomState.h"
#include "app_tmb_DefusedState.h"
#include "app_tmb_PauseState.h"
#include "app_tmb_WaitForButtonState.h"
/*............................................................................*/
static void app_tmb_TimeBombActObj_setupEventSubscribers(
    app_tmb_TimeBombActObj * const self
);
static void app_tmb_TimeBombActObj_onStart(
    app_tmb_TimeBombActObj * const self
);
/*............................................................................*/
app_tmb_TimeBombActObj * app_tmb_TimeBombActObj_(void) {
    static app_tmb_TimeBombActObj self;
    return &self;
}
/*............................................................................*/
static void app_tmb_TimeBombActObj_setupEventSubscribers(
    app_tmb_TimeBombActObj * const self
) {
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_OnStartEvent_(),
        vsk_EventSubscriber_init(
            &self->_eventSubscribers.onStart,
            (vsk_Task *)self,
            self,
            (vsk_MessageHandler)app_tmb_TimeBombActObj_onStart
        )
    );
}
/*............................................................................*/
app_tmb_TimeBombActObj * app_tmb_TimeBombActObj_init(
    app_tmb_TimeBombActObj * const self
) {
    vsk_ActiveObject_init(&self->_super.actObj);
    vsk_StateMachine_init(&self->_stateMachine, vsk_ActiveObject_getTask(&self->_super.actObj));
    app_tmb_WaitForButtonState_init(
        app_tmb_WaitForButtonState_(),
        &self->_stateMachine
    );
    app_tmb_BlinkState_init(app_tmb_BlinkState_(), &self->_stateMachine);
    app_tmb_PauseState_init(app_tmb_PauseState_(), &self->_stateMachine);
    app_tmb_BoomState_init(app_tmb_BoomState_(), &self->_stateMachine);
    app_tmb_DefusedState_init(app_tmb_DefusedState_(), &self->_stateMachine);
    app_tmb_TimeBombActObj_setupEventSubscribers(self);
    return self;
}
/*............................................................................*/
static void app_tmb_TimeBombActObj_onStart(
    app_tmb_TimeBombActObj * const self
) {
    vsk_StateMachine_transition(
        &self->_stateMachine,
        (vsk_State *)app_tmb_WaitForButtonState_()
    );
}
/*............................................................................*/
void app_tmb_TimeBombActObj_setBlinkCounter(
    app_tmb_TimeBombActObj * const self,
    uint32_t const blinkCounter
) {
    self->_blinkCounter = blinkCounter;
}
/*............................................................................*/
uint32_t app_tmb_TimeBombActObj_getBlinkCounter(
    app_tmb_TimeBombActObj * const self
) {
    return self->_blinkCounter;
}
/*............................................................................*/
void app_tmb_TimeBombActObj_decrementBlinkCounter(
    app_tmb_TimeBombActObj * const self
) {
    self->_blinkCounter--;
}
