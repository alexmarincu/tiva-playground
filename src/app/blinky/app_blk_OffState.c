/*............................................................................*/
#include "app_blk_OffState.h"
#include "../../app/events/app_ev_OffTimeoutEvent.h"
#include "../../hw_abstraction/ha_Led.h"
#include "app_blk_BlinkyActObj.h"
#include "app_blk_OnState.h"
/*............................................................................*/
static void app_blk_OffState_setupEventSubscriptions(
    app_blk_OffState * const self
);
static void app_blk_OnState_onOffTimeout(
    app_blk_OffState * const self
);
static void app_blk_OffState_onEntry(
    app_blk_OffState * const self
);
static void app_blk_OffState_onExit(
    app_blk_OffState * const self
);
/*............................................................................*/
app_blk_OffState * app_blk_OffState_(void) {
    static app_blk_OffState self;
    return &self;
}
/*............................................................................*/
static void app_blk_OffState_setupEventSubscriptions(
    app_blk_OffState * const self
) {
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_OffTimeoutEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.offTimeout,
            vsk_StateMachine_getTask(self->_super.state._stateMachine),
            self,
            (vsk_MessageHandler)app_blk_OnState_onOffTimeout
        )
    );
}
/*............................................................................*/
app_blk_OffState * app_blk_OffState_init(
    app_blk_OffState * const self,
    vsk_StateMachine * const stateMachine
) {
    vsk_State_init(
        &self->_super.state,
        stateMachine,
        (vsk_StateOnEntry)app_blk_OffState_onEntry,
        (vsk_StateOnExit)app_blk_OffState_onExit
    );
    app_blk_OffState_setupEventSubscriptions(self);
    vsk_EventTimer_init(
        &self->_offTimeoutEventTimer,
        (vsk_Event *)app_ev_OffTimeoutEvent_()
    );
    return self;
}
/*............................................................................*/
static void app_blk_OnState_onOffTimeout(
    app_blk_OffState * const self
) {
    if (vsk_State_isActive((vsk_State *)self)) {
        vsk_StateMachine_transition(
            self->_super.state._stateMachine,
            (vsk_State *)app_blk_OnState_()
        );
    }
}
/*............................................................................*/
static void app_blk_OffState_onEntry(
    app_blk_OffState * const self
) {
    vsk_EventTimer_arm(
        &self->_offTimeoutEventTimer,
        200,
        0
    );
}
/*............................................................................*/
static void app_blk_OffState_onExit(
    app_blk_OffState * const self
) {
}
