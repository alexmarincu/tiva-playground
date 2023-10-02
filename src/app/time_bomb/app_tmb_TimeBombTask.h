#ifndef APP_TMB_TIMEBOMBTASK_H
#define APP_TMB_TIMEBOMBTASK_H
typedef struct app_tmb_TimeBombTask app_tmb_TimeBombTask;
/*............................................................................*/
#include "../../very_simple_kernel/vsk_EventSubscriber.h"
#include "../../very_simple_kernel/vsk_StateMachine.h"
#include "../../very_simple_kernel/vsk_Task.h"
/*............................................................................*/
struct app_tmb_TimeBombTask {
    vsk_Task _task;
    vsk_StateMachine _stateMachine;
    struct {
        vsk_EventSubscriber onStart;
    } _eventSubscribers;
    uint32_t _blinkCounter;
};
/*............................................................................*/
app_tmb_TimeBombTask * app_tmb_TimeBombTask_(void);
app_tmb_TimeBombTask * app_tmb_TimeBombTask_init(
    app_tmb_TimeBombTask * const self,
    ut_Queue * const messageQueue
);
void app_tmb_TimeBombTask_setBlinkCounter(
    app_tmb_TimeBombTask * const self,
    uint32_t const blinkCounter
);
uint32_t app_tmb_TimeBombTask_getBlinkCounter(
    app_tmb_TimeBombTask * const self
);
void app_tmb_TimeBombTask_decrementBlinkCounter(
    app_tmb_TimeBombTask * const self
);
/*............................................................................*/
#endif // APP_TMB_TIMEBOMBTASK_H
