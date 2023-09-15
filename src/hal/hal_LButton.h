#ifndef HAL_LBUTTON_H
#define HAL_LBUTTON_H
#include "hal_Button.h"

typedef struct hal_LButton hal_LButton;

hal_LButton * hal_LButton_(void);
hal_LButton * hal_LButton_init(hal_LButton * const self);
void hal_LButton_intRegister(hal_LButton * const self, void (*const fun)(void));
void hal_LButton_intUnregister(hal_LButton * const self);
void hal_LButton_intEnable(hal_LButton * const self);
void hal_LButton_intDisable(hal_LButton * const self);

#endif // HAL_LBUTTON_H
