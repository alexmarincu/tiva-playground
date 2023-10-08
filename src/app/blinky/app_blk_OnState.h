#ifndef APP_BLK_ONSTATE_H
#define APP_BLK_ONSTATE_H
/*............................................................................*/
typedef struct app_blk_OnState app_blk_OnState;
#include "../../very_simple_kernel/vsk_EventSubscription.h"
#include "../../very_simple_kernel/vsk_EventTimer.h"
#include "../../very_simple_kernel/vsk_State.h"
/*............................................................................*/
struct app_blk_OnState {
    struct {
        vsk_State state;
    } _super;
    struct {
        vsk_EventSubscription onTimeout;
    } _eventSubscriptions;
    vsk_EventTimer _onTimeoutEventTimer;
};
/*............................................................................*/
app_blk_OnState * app_blk_OnState_(void);
app_blk_OnState * app_blk_OnState_init(
    app_blk_OnState * const self,
    vsk_StateMachine * const stateMachine
);
#endif // APP_BLK_ONSTATE_H
