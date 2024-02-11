/*----------------------------------------------------------------------------*/
#include "ha.h"
/*----------------------------------------------------------------------------*/
#include "ha_LeftButton.h"
#include "ha_RgbLed.h"
#include "ha_RightButton.h"
#include "ha_SysTick.h"
#include "ha_SysTickSignal.h"
#include "ha_TaskProcessingSignal.h"
#include "ha_Uart.h"
#include "peripherals/ha_per_PortB.h"
#include "peripherals/ha_per_PortF.h"
/*----------------------------------------------------------------------------*/
void ha_init(void) {
    ha_per_PortF_init(ha_per_PortF_());
    ha_per_PortB_init();
    ha_SysTick_init(ha_SysTick_());
    ha_LeftButton_init(ha_LeftButton_());
    ha_RightButton_init(ha_RightButton_());
    ha_RgbLed_init();
    ha_SysTickSignal_init();
    ha_TaskProcessingSignal_init();
    ha_Uart_init();
}
