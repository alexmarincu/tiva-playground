#ifndef APP_TMB_DEFUSEDSTATE_H
#define APP_TMB_DEFUSEDSTATE_H
/*............................................................................*/
typedef struct app_tmb_DefusedState app_tmb_DefusedState;
#include "app_tmb_BaseState.h"
/*............................................................................*/
struct app_tmb_DefusedState {
    struct {
        app_tmb_BaseState baseState;
    } _super;
};
/*............................................................................*/
app_tmb_DefusedState * app_tmb_DefusedState_(void);
app_tmb_DefusedState * app_tmb_DefusedState_init(
    app_tmb_DefusedState * const self,
    vsk_StateMachine * const stateMachine
);
#endif // APP_TMB_DEFUSEDSTATE_H
