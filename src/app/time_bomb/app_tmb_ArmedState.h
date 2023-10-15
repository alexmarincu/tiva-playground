#ifndef APP_TMB_ARMEDSTATE_H
#define APP_TMB_ARMEDSTATE_H
/*............................................................................*/
typedef struct app_tmb_ArmedState app_tmb_ArmedState;
#include "app_tmb_BaseState.h"
/*............................................................................*/
struct app_tmb_ArmedState {
    struct {
        app_tmb_BaseState baseState;
    } _super;
};
/*............................................................................*/
app_tmb_ArmedState * app_tmb_ArmedState_init(
    app_tmb_ArmedState * const self,
    vsk_StateMachine * const stateMachine
);
#endif // APP_TMB_ARMEDSTATE_H
