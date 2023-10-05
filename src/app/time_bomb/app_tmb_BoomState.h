#ifndef APP_TMB_BOOMSTATE_H
#define APP_TMB_BOOMSTATE_H
/*............................................................................*/
typedef struct app_tmb_BoomState app_tmb_BoomState;
#include "../../very_simple_kernel/vsk_State.h"
/*............................................................................*/
struct app_tmb_BoomState {
    struct {
        vsk_State state;
    } _super;
};
/*............................................................................*/
app_tmb_BoomState * app_tmb_BoomState_(void);
app_tmb_BoomState * app_tmb_BoomState_init(
    app_tmb_BoomState * const self,
    vsk_StateMachine * const stateMachine
);
#endif // APP_TMB_BOOMSTATE_H
