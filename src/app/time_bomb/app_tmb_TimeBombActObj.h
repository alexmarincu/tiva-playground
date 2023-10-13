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
        vsk_EventSubscription onStart;
        vsk_EventSubscription rightButtonPress;
        vsk_EventSubscription leftButtonPress;
        vsk_EventSubscription blinkTimeout;
        vsk_EventSubscription pauseTimeout;
    } _eventSubscriptions;
    struct {
        vsk_EventTimer blinkTimeout;
        vsk_EventTimer pauseTimeout;
    } _eventTimers;
    uint32_t _blinkCounter;
};
/*............................................................................*/
app_tmb_TimeBombActObj * app_tmb_TimeBombActObj_(void);
app_tmb_TimeBombActObj * app_tmb_TimeBombActObj_init(
    app_tmb_TimeBombActObj * const self
);
void app_tmb_TimeBombActObj_setBlinkCounter(
    app_tmb_TimeBombActObj * const self,
    uint32_t const blinkCounter
);
uint32_t app_tmb_TimeBombActObj_getBlinkCounter(
    app_tmb_TimeBombActObj * const self
);
void app_tmb_TimeBombActObj_decrementBlinkCounter(
    app_tmb_TimeBombActObj * const self
);
vsk_EventTimer * app_tmb_TimeBombActObj_getBlinkTimeoutEventTimer(
    app_tmb_TimeBombActObj * const self
);
vsk_EventTimer * app_tmb_TimeBombActObj_getPauseTimeoutEventTimer(
    app_tmb_TimeBombActObj * const self
);
#endif // APP_TMB_TIMEBOMBACTOBJ_H
