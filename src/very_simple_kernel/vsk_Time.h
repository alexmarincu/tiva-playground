#ifndef VSK_TIME_H
#define VSK_TIME_H
typedef struct vsk_Time vsk_Time;
#include <stdint.h>
/*............................................................................*/
struct vsk_Time {
    uint32_t volatile _opTimeSeconds;
    uint32_t volatile _millisCount;
    uint16_t _tickPeriodMillis;
};
/*............................................................................*/
vsk_Time * vsk_Time_(void);
vsk_Time * vsk_Time_init(
    vsk_Time * const self
);
uint32_t vsk_Time_getMillisCount(
    vsk_Time * const self
);
uint32_t vsk_Time_getOpTimeSeconds(
    vsk_Time * const self
);
uint16_t vsk_Time_getTickPeriodMillis(
    vsk_Time * const self
);
void vsk_Time_informTickPeriodMillis(
    vsk_Time * const self,
    uint16_t const tickPeriodMillis
);
void vsk_Time_onSysTick(
    vsk_Time * const self
);
#endif // VSK_TIME_H
