#ifndef APP_TMB_TIMEBOMBACTOBJ_H
#define APP_TMB_TIMEBOMBACTOBJ_H
/*............................................................................*/
typedef struct app_tmb_TimeBombActObj app_tmb_TimeBombActObj;
#include "../../very_simple_kernel/vsk_ActiveObject.h"
#include "../../very_simple_kernel/vsk_EventSubscriber.h"
#include "../../very_simple_kernel/vsk_StateMachine.h"
/*............................................................................*/
struct app_tmb_TimeBombActObj {
    struct {
        vsk_ActiveObject actObj;
    } _super;
    struct {
        vsk_EventSubscriber onStart;
    } _eventSubscribers;
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
/*............................................................................*/
#endif // APP_TMB_TIMEBOMBACTOBJ_H
