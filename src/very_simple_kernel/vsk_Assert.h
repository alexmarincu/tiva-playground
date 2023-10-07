#ifndef VSK_ASSERT_H
#define VSK_ASSERT_H
typedef struct vsk_Assert vsk_Assert;
typedef void (*vsk_AssertOnAssert)(void);
#include <stdbool.h>
/*............................................................................*/
struct vsk_Assert {
    vsk_AssertOnAssert _onAssert;
};
/*............................................................................*/
vsk_Assert * vsk_Assert_(void);
vsk_Assert * vsk_Assert_init(
    vsk_Assert * const self,
    vsk_AssertOnAssert const onAssert
);
void vsk_Assert_check(
    vsk_Assert * const self,
    bool const condition
);
#endif // VSK_ASSERT_H
