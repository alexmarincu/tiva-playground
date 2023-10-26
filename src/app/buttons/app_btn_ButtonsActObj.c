/*............................................................................*/
#include "app_btn_ButtonsActObj.h"
/*............................................................................*/
#include "../../hw_abstraction/ha_LeftButton.h"
#include "../../hw_abstraction/ha_RightButton.h"
#include "../../system_infrastructure/events/si_ev_LeftButtonDebounceTimeoutEvent.h"
#include "../../system_infrastructure/events/si_ev_LeftButtonIntEvent.h"
#include "../../system_infrastructure/events/si_ev_LeftButtonPressEvent.h"
#include "../../system_infrastructure/events/si_ev_RightButtonDebounceTimeoutEvent.h"
#include "../../system_infrastructure/events/si_ev_RightButtonIntEvent.h"
#include "../../system_infrastructure/events/si_ev_RightButtonPressEvent.h"
/*............................................................................*/
static void app_btn_ButtonsActObj_onLeftButtonInt(
    app_btn_ButtonsActObj * const self
);
static void app_btn_ButtonsActObj_onRightButtonInt(
    app_btn_ButtonsActObj * const self
);
static void app_btn_ButtonsActObj_onLeftButtonDebounceTimeout(
    app_btn_ButtonsActObj * const self
);
static void app_btn_ButtonsActObj_onRightButtonDebounceTimeout(
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
    vsk_ActiveObject_init((vsk_ActiveObject *)self, NULL);
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
        (vsk_Event *)si_ev_LeftButtonDebounceTimeoutEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.leftButtonDebounceTimeout,
            &((vsk_ActiveObject *)self)->_inbox,
            (vsk_MessageHandler)
                app_btn_ButtonsActObj_onLeftButtonDebounceTimeout,
            self
        )
    );
    vsk_Event_subscribe(
        (vsk_Event *)si_ev_RightButtonDebounceTimeoutEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.rightButtonDebounceTimeout,
            &((vsk_ActiveObject *)self)->_inbox,
            (vsk_MessageHandler)
                app_btn_ButtonsActObj_onRightButtonDebounceTimeout,
            self
        )
    );
    uint32_t const debounceDelayMillis = 30;
    vsk_EventTimer_init(
        &self->_eventTimers.leftButtonDebounceTimeout,
        debounceDelayMillis,
        0,
        (vsk_Event *)si_ev_LeftButtonDebounceTimeoutEvent_()
    );
    vsk_EventTimer_init(
        &self->_eventTimers.rightButtonDebounceTimeout,
        debounceDelayMillis,
        0,
        (vsk_Event *)si_ev_RightButtonDebounceTimeoutEvent_()
    );
    return self;
}
/*............................................................................*/
static void app_btn_ButtonsActObj_onLeftButtonInt(
    app_btn_ButtonsActObj * const self
) {
    vsk_Timer_start((vsk_Timer *)&self->_eventTimers.leftButtonDebounceTimeout);
}
/*............................................................................*/
static void app_btn_ButtonsActObj_onRightButtonInt(
    app_btn_ButtonsActObj * const self
) {
    vsk_Timer_start(
        (vsk_Timer *)&self->_eventTimers.rightButtonDebounceTimeout
    );
}
/*............................................................................*/
static void app_btn_ButtonsActObj_onLeftButtonDebounceTimeout(
    app_btn_ButtonsActObj * const self
) {
    if (ha_LeftButton_isPressed(ha_LeftButton_())) {
        vsk_Event_raise((vsk_Event *)si_ev_LeftButtonPressEvent_());
    }
}
/*............................................................................*/
static void app_btn_ButtonsActObj_onRightButtonDebounceTimeout(
    app_btn_ButtonsActObj * const self
) {
    if (ha_RightButton_isPressed(ha_RightButton_())) {
        vsk_Event_raise((vsk_Event *)si_ev_RightButtonPressEvent_());
    }
}
