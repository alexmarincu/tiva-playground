#include "ut_Array.h"

ut_Array * ut_Array_init(
    ut_Array * const self,
    void ** const items,
    size_t const length
) {
    self->items = items;
    self->length = length;
    ut_Array_clear(self);
    return self;
}

void ut_Array_insert(ut_Array * const self, void * const item, size_t const index) {
    self->items[index] = item;
}

void * ut_Array_get(ut_Array * const self, uint8_t const index) {
    return self->items[index];
}

void * ut_Array_remove(ut_Array * const self, uint8_t const index) {
    void * item = self->items[index];
    self->items[index] = 0;
    return item;
}

void ut_Array_clear(ut_Array * const self) {
    for (size_t i = 0; i < self->length; i++) {
        self->items[i] = 0;
    }
}

size_t ut_Array_length(ut_Array * const self) {
    return self->length;
}
