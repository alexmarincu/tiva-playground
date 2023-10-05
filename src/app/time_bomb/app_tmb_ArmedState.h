#ifndef APP_TMB_ARMEDSTATE_H
#define APP_TMB_ARMEDSTATE_H
/*............................................................................*/
typedef struct app_tmb_ArmedState app_tmb_ArmedState;
#include "../../very_simple_kernel/vsk_EventSubscriber.h"
#include "../../very_simple_kernel/vsk_State.h"
/*............................................................................*/
struct app_tmb_ArmedState {
    struct {
        vsk_State state;
    } _super;
    struct {
        vsk_EventSubscriber rightButtonPress;
    } _eventSubscribers;
};
/*............................................................................*/
app_tmb_ArmedState * app_tmb_ArmedState_(void);
app_tmb_ArmedState * app_tmb_ArmedState_init(
    app_tmb_ArmedState * const self,
    vsk_StateMachine * const stateMachine
);
#endif // APP_TMB_ARMEDSTATE_H
