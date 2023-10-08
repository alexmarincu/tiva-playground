#ifndef APP_BLK_OFFSTATE_H
#define APP_BLK_OFFSTATE_H
/*............................................................................*/
typedef struct app_blk_OffState app_blk_OffState;
#include "../../very_simple_kernel/vsk_EventSubscription.h"
#include "../../very_simple_kernel/vsk_EventTimer.h"
#include "../../very_simple_kernel/vsk_State.h"
/*............................................................................*/
struct app_blk_OffState {
    struct {
        vsk_State state;
    } _super;
    struct {
        vsk_EventSubscription offTimeout;
    } _eventSubscriptions;
    vsk_EventTimer _offTimeoutEventTimer;
};
/*............................................................................*/
app_blk_OffState * app_blk_OffState_(void);
app_blk_OffState * app_blk_OffState_init(
    app_blk_OffState * const self,
    vsk_StateMachine * const stateMachine
);
#endif // APP_BLK_OFFSTATE_H
