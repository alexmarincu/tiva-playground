#ifndef APP_TMB_TIMEBOMBACTOBJ_H
#define APP_TMB_TIMEBOMBACTOBJ_H
/*............................................................................*/
typedef struct app_tmb_TimeBombActObj app_tmb_TimeBombActObj;
#include "../../very_simple_kernel/vsk_ActiveObject.h"
#include "../../very_simple_kernel/vsk_EventSubscription.h"
#include "../../very_simple_kernel/vsk_EventTimer.h"
/*............................................................................*/
struct app_tmb_TimeBombActObj {
    struct {
        vsk_ActiveObject actObj;
    } _super;
    struct {
        vsk_EventSubscription rightButtonPress;
        vsk_EventSubscription leftButtonPress;
        vsk_EventSubscription blinkTimeout;
        vsk_EventSubscription pauseTimeout;
    } _eventSubscriptions;
    struct {
        vsk_EventTimer blinkTimeout;
        vsk_EventTimer pauseTimeout;
    } eventTimers;
    uint32_t blinkCounter;
};
/*............................................................................*/
app_tmb_TimeBombActObj * app_tmb_TimeBombActObj_(void);
app_tmb_TimeBombActObj * app_tmb_TimeBombActObj_init(
    app_tmb_TimeBombActObj * const self
);
#endif // APP_TMB_TIMEBOMBACTOBJ_H
