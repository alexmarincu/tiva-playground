#ifndef HAL_LBUTTON_H
#define HAL_LBUTTON_H
#include "hal_Button.h"

typedef struct hal_LButton hal_LButton;

hal_LButton * hal_LButton_(void);
hal_LButton * hal_LButton_init(hal_LButton * const self);
void hal_LButton_setIntTypeBothEdges(hal_LButton * const self);
void hal_LButton_registerInt(hal_LButton * const self, void (*const fun)(void));
void hal_LButton_unregisterInt(hal_LButton * const self);
void hal_LButton_enableInt(hal_LButton * const self);
void hal_LButton_disableInt(hal_LButton * const self);
void hal_LButton_clearIntFlag(hal_LButton * const self);
bool hal_LButton_isPressed(hal_LButton * const self);

#endif // HAL_LBUTTON_H
