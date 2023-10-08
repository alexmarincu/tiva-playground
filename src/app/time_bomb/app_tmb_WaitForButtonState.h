#ifndef APP_TMB_WAITFORBUTTONSTATE_H
#define APP_TMB_WAITFORBUTTONSTATE_H
/*............................................................................*/
typedef struct app_tmb_WaitForButtonState app_tmb_WaitForButtonState;
#include "../../very_simple_kernel/vsk_EventSubscription.h"
#include "../../very_simple_kernel/vsk_State.h"
/*............................................................................*/
struct app_tmb_WaitForButtonState {
    struct {
        vsk_State state;
    } _super;
    struct {
        vsk_EventSubscription leftButtonPress;
    } _eventSubscriptions;
};
/*............................................................................*/
app_tmb_WaitForButtonState * app_tmb_WaitForButtonState_(void);
app_tmb_WaitForButtonState * app_tmb_WaitForButtonState_init(
    app_tmb_WaitForButtonState * const self,
    vsk_StateMachine * const stateMachine
);
#endif // APP_TMB_WAITFORBUTTONSTATE_H
