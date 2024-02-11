/*----------------------------------------------------------------------------*/
#ifndef APP_BTN_RIGHTBUTTONDEBOUNCINGSTATE_H
#define APP_BTN_RIGHTBUTTONDEBOUNCINGSTATE_H
/*----------------------------------------------------------------------------*/
typedef struct app_btn_RightButtonDebouncingState
    app_btn_RightButtonDebouncingState;
/*----------------------------------------------------------------------------*/
#include "app_btn_DebouncingState.h"
/*----------------------------------------------------------------------------*/
struct app_btn_RightButtonDebouncingState {
    struct {
        app_btn_DebouncingState debouncingState;
    } _super;
};
/*----------------------------------------------------------------------------*/
app_btn_RightButtonDebouncingState * app_btn_RightButtonDebouncingState_(void);
app_btn_RightButtonDebouncingState * app_btn_RightButtonDebouncingState_init(
    app_btn_RightButtonDebouncingState * const self,
    vsk_StateContext * const stateContext
);
#endif // APP_BTN_RIGHTBUTTONDEBOUNCINGSTATE_H
