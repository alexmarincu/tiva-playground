#ifndef APP_TMB_BLINKSTATE_H
#define APP_TMB_BLINKSTATE_H
/*............................................................................*/
typedef struct app_tmb_BlinkState app_tmb_BlinkState;
#include "../../very_simple_kernel/vsk_EventSubscriber.h"
#include "../../very_simple_kernel/vsk_EventTimer.h"
#include "../../very_simple_kernel/vsk_State.h"
/*............................................................................*/
struct app_tmb_BlinkState {
    struct {
        vsk_State state;
    } _super;
    struct {
        vsk_EventSubscriber blinkTimeout;
    } _eventSubscribers;
    vsk_EventTimer _blinkTimeoutEventTimer;
};
/*............................................................................*/
app_tmb_BlinkState * app_tmb_BlinkState_(void);
app_tmb_BlinkState * app_tmb_BlinkState_init(
    app_tmb_BlinkState * const self,
    vsk_StateMachine * const stateMachine
);
#endif // APP_TMB_BLINKSTATE_H
