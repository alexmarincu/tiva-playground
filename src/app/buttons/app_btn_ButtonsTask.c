/*............................................................................*/
#include "app_btn_ButtonsTask.h"
#include "../../app/events/app_ev_LeftButtonDebounceTimeoutEvent.h"
#include "../../app/events/app_ev_LeftButtonIntEvent.h"
#include "../../app/events/app_ev_LeftButtonPressEvent.h"
#include "../../app/events/app_ev_RightButtonDebounceTimeoutEvent.h"
#include "../../app/events/app_ev_RightButtonIntEvent.h"
#include "../../app/events/app_ev_RightButtonPressEvent.h"
#include "../../hw_abstraction/ha_LeftButton.h"
#include "../../hw_abstraction/ha_RightButton.h"
/*............................................................................*/
static void app_btn_ButtonsTask_onLeftButtonInt(
    app_btn_ButtonsTask * const self
);
static void app_btn_ButtonsTask_onRightButtonInt(
    app_btn_ButtonsTask * const self
);
static void app_btn_ButtonsTask_onLeftButtonDebounceTimeout(
    app_btn_ButtonsTask * const self
);
static void app_btn_ButtonsTask_onRightButtonDebounceTimeout(
    app_btn_ButtonsTask * const self
);
/*............................................................................*/
app_btn_ButtonsTask * app_btn_ButtonsTask_(void) {
    static app_btn_ButtonsTask self;
    return &self;
}
/*............................................................................*/
static void task(app_btn_ButtonsTask * const self) {
    vsk_Message_dispatch(vsk_Inbox_readMessage(&self->_inbox));
}
/*............................................................................*/
app_btn_ButtonsTask * app_btn_ButtonsTask_init(
    app_btn_ButtonsTask * const self
) {
    vsk_Task_init((vsk_Task *)self, (vsk_TaskOperation)task, self);
    vsk_Inbox_init(&self->_inbox, (vsk_Task *)self);
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_LeftButtonIntEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.leftButtonInt,
            &self->_inbox,
            self,
            (vsk_MessageHandler)app_btn_ButtonsTask_onLeftButtonInt
        )
    );
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_RightButtonIntEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.rightButtonInt,
            &self->_inbox,
            self,
            (vsk_MessageHandler)app_btn_ButtonsTask_onRightButtonInt
        )
    );
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_LeftButtonDebounceTimeoutEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.leftButtonDebounceTimeout,
            &self->_inbox,
            self,
            (vsk_MessageHandler)
                app_btn_ButtonsTask_onLeftButtonDebounceTimeout
        )
    );
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_RightButtonDebounceTimeoutEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.rightButtonDebounceTimeout,
            &self->_inbox,
            self,
            (vsk_MessageHandler)
                app_btn_ButtonsTask_onRightButtonDebounceTimeout
        )
    );
    uint32_t const debounceDelayMillis = 20;
    vsk_EventTimer_init(
        &self->_eventTimers.leftButtonDebounceTimeout,
        debounceDelayMillis,
        0,
        (vsk_Event *)app_ev_LeftButtonDebounceTimeoutEvent_()
    );
    vsk_EventTimer_init(
        &self->_eventTimers.rightButtonDebounceTimeout,
        debounceDelayMillis,
        0,
        (vsk_Event *)app_ev_RightButtonDebounceTimeoutEvent_()
    );
    return self;
}
/*............................................................................*/
static void app_btn_ButtonsTask_onLeftButtonInt(
    app_btn_ButtonsTask * const self
) {
    vsk_Timer_start((vsk_Timer *)&self->_eventTimers.leftButtonDebounceTimeout);
}
/*............................................................................*/
static void app_btn_ButtonsTask_onRightButtonInt(
    app_btn_ButtonsTask * const self
) {
    vsk_Timer_start(
        (vsk_Timer *)&self->_eventTimers.rightButtonDebounceTimeout
    );
}
/*............................................................................*/
static void app_btn_ButtonsTask_onLeftButtonDebounceTimeout(
    app_btn_ButtonsTask * const self
) {
    if (ha_LeftButton_isPressed(ha_LeftButton_())) {
        vsk_Event_raise((vsk_Event *)app_ev_LeftButtonPressEvent_());
    }
}
/*............................................................................*/
static void app_btn_ButtonsTask_onRightButtonDebounceTimeout(
    app_btn_ButtonsTask * const self
) {
    if (ha_RightButton_isPressed(ha_RightButton_())) {
        vsk_Event_raise((vsk_Event *)app_ev_RightButtonPressEvent_());
    }
}
