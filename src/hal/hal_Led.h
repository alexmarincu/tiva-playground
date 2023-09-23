#ifndef HAL_LED_H
#define HAL_LED_H

void hal_Led_init(void);
void hal_Led_setGreen(void);
void hal_Led_setBlue(void);
void hal_Led_setRed(void);
void hal_Led_setOff(void);
void hal_Led_toggleRed(void);

#endif // HAL_LED_H
