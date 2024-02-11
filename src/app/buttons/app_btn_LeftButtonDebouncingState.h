/*----------------------------------------------------------------------------*/
#ifndef APP_BTN_LEFTBUTTONDEBOUNCINGSTATE_H
#define APP_BTN_LEFTBUTTONDEBOUNCINGSTATE_H
/*----------------------------------------------------------------------------*/
typedef struct app_btn_LeftButtonDebouncingState
    app_btn_LeftButtonDebouncingState;
/*----------------------------------------------------------------------------*/
#include "app_btn_DebouncingState.h"
/*----------------------------------------------------------------------------*/
struct app_btn_LeftButtonDebouncingState {
    struct {
        app_btn_DebouncingState debouncingState;
    } _super;
};
/*----------------------------------------------------------------------------*/
app_btn_LeftButtonDebouncingState * app_btn_LeftButtonDebouncingState_(void);
app_btn_LeftButtonDebouncingState * app_btn_LeftButtonDebouncingState_init(
    app_btn_LeftButtonDebouncingState * const self,
    vsk_StateContext * const stateContext
);
#endif // APP_BTN_LEFTBUTTONDEBOUNCINGSTATE_H
