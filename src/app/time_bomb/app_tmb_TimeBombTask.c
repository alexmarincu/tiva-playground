#include "app_tmb_TimeBombTask.h"
#include "../../app/events/app_ev_OnStartEvent.h"
#include "app_tmb_BlinkState.h"
#include "app_tmb_BoomState.h"
#include "app_tmb_PauseState.h"
#include "app_tmb_WaitForButtonState.h"
/*............................................................................*/
static void app_tmb_TimeBombTask_setupEventSubscribers(
    app_tmb_TimeBombTask * const self
);
static void app_tmb_TimeBombTask_onStart(
    app_tmb_TimeBombTask * const self
);
/*............................................................................*/
app_tmb_TimeBombTask * app_tmb_TimeBombTask_(void) {
    static app_tmb_TimeBombTask self;
    return &self;
}
/*............................................................................*/
static void app_tmb_TimeBombTask_setupEventSubscribers(
    app_tmb_TimeBombTask * const self
) {
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_OnStartEvent_(),
        vsk_EventSubscriber_init(
            &self->_eventSubscribers.onStart,
            (vsk_Task *)self,
            self,
            (vsk_MessageHandler)app_tmb_TimeBombTask_onStart
        )
    );
}
/*............................................................................*/
app_tmb_TimeBombTask * app_tmb_TimeBombTask_init(
    app_tmb_TimeBombTask * const self,
    ut_Queue * const messageQueue
) {
    vsk_Task_init(&self->_task, messageQueue);
    vsk_StateMachine_init(&self->_stateMachine, &self->_task);
    app_tmb_WaitForButtonState_init(
        app_tmb_WaitForButtonState_(),
        &self->_stateMachine
    );
    app_tmb_BlinkState_init(app_tmb_BlinkState_(), &self->_stateMachine);
    app_tmb_PauseState_init(app_tmb_PauseState_(), &self->_stateMachine);
    app_tmb_BoomState_init(app_tmb_BoomState_(), &self->_stateMachine);
    app_tmb_TimeBombTask_setupEventSubscribers(self);
    return self;
}
/*............................................................................*/
static void app_tmb_TimeBombTask_onStart(
    app_tmb_TimeBombTask * const self
) {
    vsk_StateMachine_transition(
        &self->_stateMachine,
        (vsk_State *)app_tmb_WaitForButtonState_()
    );
}
/*............................................................................*/
void app_tmb_TimeBombTask_setBlinkCounter(
    app_tmb_TimeBombTask * const self,
    uint32_t const blinkCounter
) {
    self->_blinkCounter = blinkCounter;
}
/*............................................................................*/
uint32_t app_tmb_TimeBombTask_getBlinkCounter(
    app_tmb_TimeBombTask * const self
) {
    return self->_blinkCounter;
}
/*............................................................................*/
void app_tmb_TimeBombTask_decrementBlinkCounter(
    app_tmb_TimeBombTask * const self
) {
    self->_blinkCounter--;
}
