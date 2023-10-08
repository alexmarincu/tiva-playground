/*............................................................................*/
#include "app_blk_BlinkyActObj.h"
#include "../../app/events/app_ev_OnStartEvent.h"
#include "app_blk_OffState.h"
#include "app_blk_OnState.h"
/*............................................................................*/
static void app_blk_BlinkyActObj_setupEventSubscriptions(
    app_blk_BlinkyActObj * const self
);
static void app_blk_BlinkyActObj_onStart(
    app_blk_BlinkyActObj * const self
);
/*............................................................................*/
app_blk_BlinkyActObj * app_blk_BlinkyActObj_(void) {
    static app_blk_BlinkyActObj self;
    return &self;
}
/*............................................................................*/
static void app_blk_BlinkyActObj_setupEventSubscriptions(
    app_blk_BlinkyActObj * const self
) {
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_OnStartEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.onStart,
            (vsk_Task *)self,
            self,
            (vsk_MessageHandler)app_blk_BlinkyActObj_onStart
        )
    );
}
/*............................................................................*/
app_blk_BlinkyActObj * app_blk_BlinkyActObj_init(
    app_blk_BlinkyActObj * const self
) {
    vsk_ActiveObject_init(&self->_super.actObj);
    app_blk_OnState_init(
        app_blk_OnState_(),
        &self->_super.actObj._stateMachine
    );
    app_blk_OffState_init(
        app_blk_OffState_(),
        &self->_super.actObj._stateMachine
    );
    app_blk_BlinkyActObj_setupEventSubscriptions(self);
    return self;
}
/*............................................................................*/
static void app_blk_BlinkyActObj_onStart(
    app_blk_BlinkyActObj * const self
) {
    vsk_StateMachine_transition(
        &self->_super.actObj._stateMachine,
        (vsk_State *)app_blk_OnState_()
    );
}
