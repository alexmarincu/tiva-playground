/*............................................................................*/
#include "app_btn_ButtonsActObj.h"
/*............................................................................*/
#include "../../hw_abstraction/ha_LeftButton.h"
#include "../../hw_abstraction/ha_RightButton.h"
#include "../../system_infrastructure/events/si_ev_ButtonDebounceTimeoutEvent.h"
#include "../../system_infrastructure/events/si_ev_LeftButtonIntEvent.h"
#include "../../system_infrastructure/events/si_ev_LeftButtonPressEvent.h"
#include "../../system_infrastructure/events/si_ev_RightButtonIntEvent.h"
#include "../../system_infrastructure/events/si_ev_RightButtonPressEvent.h"
#include "app_btn_LeftButtonDebouncingState.h"
#include "app_btn_RightButtonDebouncingState.h"
#include "app_btn_WaitForButtonIntState.h"
/*............................................................................*/
static void app_btn_ButtonsActObj_onLeftButtonInt(
    app_btn_ButtonsActObj * const self
);
static void app_btn_ButtonsActObj_onRightButtonInt(
    app_btn_ButtonsActObj * const self
);
static void app_btn_ButtonsActObj_onDebounceTimeout(
    app_btn_ButtonsActObj * const self
);
/*............................................................................*/
app_btn_ButtonsActObj * app_btn_ButtonsActObj_(void) {
    static app_btn_ButtonsActObj self;
    return &self;
}
/*............................................................................*/
app_btn_ButtonsActObj * app_btn_ButtonsActObj_init(
    app_btn_ButtonsActObj * const self
) {
    vsk_ActiveObject_init(
        (vsk_ActiveObject *)self,
        (vsk_State *)app_btn_WaitForButtonIntState_()
    );
    app_btn_WaitForButtonIntState_init(
        app_btn_WaitForButtonIntState_(), (vsk_StateContext *)self
    );
    app_btn_LeftButtonDebouncingState_init(
        app_btn_LeftButtonDebouncingState_(), (vsk_StateContext *)self
    );
    app_btn_RightButtonDebouncingState_init(
        app_btn_RightButtonDebouncingState_(), (vsk_StateContext *)self
    );
    vsk_Event_subscribe(
        (vsk_Event *)si_ev_LeftButtonIntEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.leftButtonInt,
            &((vsk_ActiveObject *)self)->_inbox,
            (vsk_MessageHandler)app_btn_ButtonsActObj_onLeftButtonInt,
            self
        )
    );
    vsk_Event_subscribe(
        (vsk_Event *)si_ev_RightButtonIntEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.rightButtonInt,
            &((vsk_ActiveObject *)self)->_inbox,
            (vsk_MessageHandler)app_btn_ButtonsActObj_onRightButtonInt,
            self
        )
    );
    vsk_Event_subscribe(
        (vsk_Event *)si_ev_ButtonDebounceTimeoutEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.buttonDebounceTimeout,
            &((vsk_ActiveObject *)self)->_inbox,
            (vsk_MessageHandler)
                app_btn_ButtonsActObj_onDebounceTimeout,
            self
        )
    );
    vsk_EventTimer_init(
        &self->eventTimers.buttonDebounce, 30, 0,
        (vsk_Event *)si_ev_ButtonDebounceTimeoutEvent_()
    );
    return self;
}
/*............................................................................*/
static void app_btn_ButtonsActObj_onLeftButtonInt(
    app_btn_ButtonsActObj * const self
) {
    app_btn_ButtonsState_onLeftButtonInt(
        (app_btn_ButtonsState *)((vsk_StateContext *)self)->_state
    );
}
/*............................................................................*/
static void app_btn_ButtonsActObj_onRightButtonInt(
    app_btn_ButtonsActObj * const self
) {
    app_btn_ButtonsState_onRightButtonInt(
        (app_btn_ButtonsState *)((vsk_StateContext *)self)->_state
    );
}
/*............................................................................*/
static void app_btn_ButtonsActObj_onDebounceTimeout(
    app_btn_ButtonsActObj * const self
) {
    app_btn_ButtonsState_onDebounceTimeout(
        (app_btn_ButtonsState *)((vsk_StateContext *)self)->_state
    );
}
