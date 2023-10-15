/*............................................................................*/
#include "vsk_ActiveObject.h"
#include "vsk_OnStartEvent.h"
/*............................................................................*/
static void vsk_ActiveObject_onStart(
    vsk_ActiveObject * const self
);
/*............................................................................*/
vsk_ActiveObject * vsk_ActiveObject_init(
    vsk_ActiveObject * const self,
    vsk_State * const initialState
) {
    vsk_Task_init(&self->_task);
    vsk_StateMachine_init(&self->_super.stateMachine, initialState);
    vsk_Event_subscribe(
        (vsk_Event *)vsk_OnStartEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.onStart,
            &self->_task.inbox,
            self,
            (vsk_MessageHandler)vsk_ActiveObject_onStart
        )
    );
    return self;
}
/*............................................................................*/
static void vsk_ActiveObject_onStart(
    vsk_ActiveObject * const self
) {
    vsk_StateMachine_transition(
        &self->_super.stateMachine,
        self->_super.stateMachine._initialState
    );
}
