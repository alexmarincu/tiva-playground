#ifndef APP_BTN_BUTTONSTASK_H
#define APP_BTN_BUTTONSTASK_H
/*............................................................................*/
typedef struct app_btn_ButtonsTask app_btn_ButtonsTask;
#include "../../very_simple_kernel/vsk_EventSubscription.h"
#include "../../very_simple_kernel/vsk_EventTimer.h"
#include "../../very_simple_kernel/vsk_Task.h"
/*............................................................................*/
struct app_btn_ButtonsTask {
    struct {
        vsk_Task task;
    } _super;
    vsk_Inbox _inbox;
    struct {
        vsk_EventSubscription leftButtonInt;
        vsk_EventSubscription rightButtonInt;
        vsk_EventSubscription leftButtonDebounceTimeout;
        vsk_EventSubscription rightButtonDebounceTimeout;
    } _eventSubscriptions;
    struct {
        vsk_EventTimer leftButtonDebounceTimeout;
        vsk_EventTimer rightButtonDebounceTimeout;
    } _eventTimers;
};
/*............................................................................*/
app_btn_ButtonsTask * app_btn_ButtonsTask_(void);
app_btn_ButtonsTask * app_btn_ButtonsTask_init(
    app_btn_ButtonsTask * const self
);
#endif // APP_BTN_BUTTONSTASK_H
