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
    struct {
        vsk_EventSubscription onLeftButtonInt;
        vsk_EventSubscription onRightButtonInt;
        vsk_EventSubscription onLeftButtonDebounce;
        vsk_EventSubscription onRightButtonDebounce;
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
