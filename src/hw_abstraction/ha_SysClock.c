/*............................................................................*/
#include "ha_SysClock.h"
/*............................................................................*/
#include <stdbool.h>
/*............................................................................*/
#include "../../lib/TivaWare/driverlib/sysctl.h"
/*............................................................................*/
void ha_SysClock_setMaxFrequency(void) {
    SysCtlClockSet(
        SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ
    );
}
/*............................................................................*/
uint32_t ha_SysClock_getFrequency(void) {
    return SysCtlClockGet();
}
