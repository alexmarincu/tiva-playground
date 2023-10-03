/*............................................................................*/
#include "app_tmb_WaitForButtonState.h"
#include "../../app/events/app_ev_LeftButtonPressEvent.h"
#include "../../hw_abstraction/ha_Led.h"
#include "app_tmb_BlinkState.h"
#include "app_tmb_TimeBombTask.h"
/*............................................................................*/
static void app_tmb_WaitForButtonState_setupEventSubscribers(
    app_tmb_WaitForButtonState * const self
);
static void app_tmb_WaitForButtonState_onLeftButtonPress(
    app_tmb_WaitForButtonState * const self
);
static void app_tmb_WaitForButtonState_onEntry(
    app_tmb_WaitForButtonState * const self
);
static void app_tmb_WaitForButtonState_onExit(
    app_tmb_WaitForButtonState * const self
);
/*............................................................................*/
app_tmb_WaitForButtonState * app_tmb_WaitForButtonState_(void) {
    static app_tmb_WaitForButtonState self;
    return &self;
}
/*............................................................................*/
static void app_tmb_WaitForButtonState_setupEventSubscribers(
    app_tmb_WaitForButtonState * const self
) {
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_LeftButtonPressEvent_(),
        vsk_EventSubscriber_init(
            &self->_eventSubscribers.leftButtonPress,
            vsk_StateMachine_getTask(self->_state._stateMachine),
            self,
            (vsk_MessageHandler)app_tmb_WaitForButtonState_onLeftButtonPress
        )
    );
}
/*............................................................................*/
app_tmb_WaitForButtonState * app_tmb_WaitForButtonState_init(
    app_tmb_WaitForButtonState * const self,
    vsk_StateMachine * const stateMachine
) {
    vsk_State_init(
        &self->_state,
        stateMachine,
        (vsk_StateOnEntry)app_tmb_WaitForButtonState_onEntry,
        (vsk_StateOnExit)app_tmb_WaitForButtonState_onExit
    );
    app_tmb_WaitForButtonState_setupEventSubscribers(self);
    return self;
}
/*............................................................................*/
static void app_tmb_WaitForButtonState_onLeftButtonPress(
    app_tmb_WaitForButtonState * const self
) {
    app_tmb_TimeBombTask_setBlinkCounter(
        (app_tmb_TimeBombTask *)self->_state._stateMachine->_task,
        5
    );
    vsk_StateMachine_transition(
        self->_state._stateMachine,
        (vsk_State *)app_tmb_BlinkState_()
    );
}
/*............................................................................*/
static void app_tmb_WaitForButtonState_onEntry(
    app_tmb_WaitForButtonState * const self
) {
    ha_Led_setGreenOn();
}
/*............................................................................*/
static void app_tmb_WaitForButtonState_onExit(
    app_tmb_WaitForButtonState * const self
) {
    ha_Led_setGreenOff();
}
