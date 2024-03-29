/*----------------------------------------------------------------------------*/
#ifndef APP_BTN_BUTTONSACTOBJ_H
#define APP_BTN_BUTTONSACTOBJ_H
/*----------------------------------------------------------------------------*/
typedef struct app_btn_ButtonsActObj app_btn_ButtonsActObj;
/*----------------------------------------------------------------------------*/
#include "../../../very-simple-kernel/very_simple_kernel/src/vsk_ActiveObject.h"
#include "../../../very-simple-kernel/very_simple_kernel/src/vsk_EventSubscription.h"
#include "../../../very-simple-kernel/very_simple_kernel/src/vsk_EventTimer.h"
/*----------------------------------------------------------------------------*/
struct app_btn_ButtonsActObj {
    struct {
        vsk_ActiveObject activeObject;
    } _super;
    struct {
        vsk_EventSubscription leftButtonInt;
        vsk_EventSubscription rightButtonInt;
        vsk_EventSubscription buttonDebounceTimeout;
    } _eventSubscriptions;
    struct {
        vsk_EventTimer buttonDebounce;
    } eventTimers;
};
/*----------------------------------------------------------------------------*/
app_btn_ButtonsActObj * app_btn_ButtonsActObj_(void);
app_btn_ButtonsActObj * app_btn_ButtonsActObj_init(
    app_btn_ButtonsActObj * const self
);
#endif // APP_BTN_BUTTONSACTOBJ_H
