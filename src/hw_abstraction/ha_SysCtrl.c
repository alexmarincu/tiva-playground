/*............................................................................*/
#include "ha_SysCtrl.h"
#include <stdbool.h>
#include <stdint.h>
//
#include "../../lib/TivaWare/driverlib/sysctl.h"
/*............................................................................*/
void ha_SysCtrl_sleep(void) {
    SysCtlSleep();
}
