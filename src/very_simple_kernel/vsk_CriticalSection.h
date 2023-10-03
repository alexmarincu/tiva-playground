#ifndef VSK_CRITICALSECTION_H
#define VSK_CRITICALSECTION_H
/*............................................................................*/
typedef struct vsk_CriticalSection vsk_CriticalSection;
typedef void (*vsk_CriticalSectionEnter)(void);
typedef void (*vsk_CriticalSectionExit)(void);
/*............................................................................*/
struct vsk_CriticalSection {
    vsk_CriticalSectionEnter _enter;
    vsk_CriticalSectionExit _exit;
};
/*............................................................................*/
vsk_CriticalSection * vsk_CriticalSection_(void);
vsk_CriticalSection * vsk_CriticalSection_init(
    vsk_CriticalSection * const self,
    vsk_CriticalSectionEnter const enter,
    vsk_CriticalSectionExit const exit
);
void vsk_CriticalSection_enter(
    vsk_CriticalSection * const self
);
void vsk_CriticalSection_exit(
    vsk_CriticalSection * const self
);
#endif // VSK_CRITICALSECTION_H
