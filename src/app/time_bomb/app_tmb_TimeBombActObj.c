/*............................................................................*/
#include "app_tmb_TimeBombActObj.h"
#include "../../app/events/app_ev_BlinkTimeoutEvent.h"
#include "../../app/events/app_ev_LeftButtonPressEvent.h"
#include "../../app/events/app_ev_PauseTimeoutEvent.h"
#include "../../app/events/app_ev_RightButtonPressEvent.h"
#include "app_tmb_BlinkState.h"
#include "app_tmb_BoomState.h"
#include "app_tmb_DefusedState.h"
#include "app_tmb_PauseState.h"
#include "app_tmb_WaitForButtonState.h"
/*............................................................................*/
static void app_tmb_TimeBombActObj_onRightButtonPress(
    app_tmb_TimeBombActObj * const self
);
static void app_tmb_TimeBombActObj_onLeftButtonPress(
    app_tmb_TimeBombActObj * const self
);
static void app_tmb_TimeBombActObj_onBlinkTimeout(
    app_tmb_TimeBombActObj * const self
);
static void app_tmb_TimeBombActObj_onPauseTimeout(
    app_tmb_TimeBombActObj * const self
);
/*............................................................................*/
app_tmb_TimeBombActObj * app_tmb_TimeBombActObj_(void) {
    static app_tmb_TimeBombActObj self;
    return &self;
}
/*............................................................................*/
app_tmb_TimeBombActObj * app_tmb_TimeBombActObj_init(
    app_tmb_TimeBombActObj * const self
) {
    vsk_ActiveObject_init(
        (vsk_ActiveObject *)self, (vsk_State *)app_tmb_WaitForButtonState_()
    );
    app_tmb_WaitForButtonState_init(
        app_tmb_WaitForButtonState_(), (vsk_StateContext *)self
    );
    app_tmb_BlinkState_init(app_tmb_BlinkState_(), (vsk_StateContext *)self);
    app_tmb_PauseState_init(app_tmb_PauseState_(), (vsk_StateContext *)self);
    app_tmb_BoomState_init(app_tmb_BoomState_(), (vsk_StateContext *)self);
    app_tmb_DefusedState_init(
        app_tmb_DefusedState_(), (vsk_StateContext *)self
    );
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_RightButtonPressEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.rightButtonPress,
            &((vsk_ActiveObject *)self)->_inbox,
            self,
            (vsk_MessageHandler)app_tmb_TimeBombActObj_onRightButtonPress
        )
    );
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_LeftButtonPressEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.leftButtonPress,
            &((vsk_ActiveObject *)self)->_inbox,
            self,
            (vsk_MessageHandler)app_tmb_TimeBombActObj_onLeftButtonPress
        )
    );
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_BlinkTimeoutEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.blinkTimeout,
            &((vsk_ActiveObject *)self)->_inbox,
            self,
            (vsk_MessageHandler)app_tmb_TimeBombActObj_onBlinkTimeout
        )
    );
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_PauseTimeoutEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.pauseTimeout,
            &((vsk_ActiveObject *)self)->_inbox,
            self,
            (vsk_MessageHandler)app_tmb_TimeBombActObj_onPauseTimeout
        )
    );
    vsk_EventTimer_init(
        &self->_eventTimers.blinkTimeout,
        (vsk_Event *)app_ev_BlinkTimeoutEvent_()
    );
    vsk_EventTimer_init(
        &self->_eventTimers.pauseTimeout,
        (vsk_Event *)app_ev_PauseTimeoutEvent_()
    );
    return self;
}
/*............................................................................*/
void app_tmb_TimeBombActObj_setBlinkCounter(
    app_tmb_TimeBombActObj * const self, uint32_t const blinkCounter
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
/*............................................................................*/
vsk_EventTimer * app_tmb_TimeBombActObj_getBlinkTimeoutEventTimer(
    app_tmb_TimeBombActObj * const self
) {
    return &self->_eventTimers.blinkTimeout;
}
/*............................................................................*/
vsk_EventTimer * app_tmb_TimeBombActObj_getPauseTimeoutEventTimer(
    app_tmb_TimeBombActObj * const self
) {
    return &self->_eventTimers.pauseTimeout;
}
/*............................................................................*/
static void app_tmb_TimeBombActObj_onRightButtonPress(
    app_tmb_TimeBombActObj * const self
) {
    app_tmb_TimeBombState_onRightButtonPress(
        (app_tmb_TimeBombState *)((vsk_StateContext *)self)->_state
    );
}
/*............................................................................*/
static void app_tmb_TimeBombActObj_onLeftButtonPress(
    app_tmb_TimeBombActObj * const self
) {
    app_tmb_TimeBombState_onLeftButtonPress(
        (app_tmb_TimeBombState *)((vsk_StateContext *)self)->_state
    );
}
/*............................................................................*/
static void app_tmb_TimeBombActObj_onBlinkTimeout(
    app_tmb_TimeBombActObj * const self
) {
    app_tmb_TimeBombState_onBlinkTimeout(
        (app_tmb_TimeBombState *)((vsk_StateContext *)self)->_state
    );
}
/*............................................................................*/
static void app_tmb_TimeBombActObj_onPauseTimeout(
    app_tmb_TimeBombActObj * const self
) {
    app_tmb_TimeBombState_onPauseTimeout(
        (app_tmb_TimeBombState *)((vsk_StateContext *)self)->_state
    );
}
