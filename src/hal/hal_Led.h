#ifndef HAL_LED_H
#define HAL_LED_H

void hal_Led_init(void);
void hal_Led_setGreenOn(void);
void hal_Led_setGreenOff(void);
void hal_Led_setBlueOn(void);
void hal_Led_setBlueOff(void);
void hal_Led_setRedOn(void);
void hal_Led_setRedOff(void);
void hal_Led_setAllOn(void);
void hal_Led_setAllOff(void);
void hal_Led_toggleRed(void);

#endif // HAL_LED_H
