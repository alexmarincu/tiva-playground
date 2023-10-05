#ifndef APP_TMB_PAUSESTATE_H
#define APP_TMB_PAUSESTATE_H
/*............................................................................*/
typedef struct app_tmb_PauseState app_tmb_PauseState;
#include "../../very_simple_kernel/vsk_EventSubscriber.h"
#include "../../very_simple_kernel/vsk_EventTimer.h"
#include "../../very_simple_kernel/vsk_State.h"
/*............................................................................*/
struct app_tmb_PauseState {
    struct {
        vsk_State state;
    } _super;
    struct {
        vsk_EventSubscriber pauseTimeout;
    } _eventSubscribers;
    vsk_EventTimer _pauseTimeoutEventTimer;
};
/*............................................................................*/
app_tmb_PauseState * app_tmb_PauseState_(void);
app_tmb_PauseState * app_tmb_PauseState_init(
    app_tmb_PauseState * const self,
    vsk_StateMachine * const stateMachine
);
#endif // APP_TMB_PAUSESTATE_H
