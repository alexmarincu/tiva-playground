#ifndef UTL_PRIMITIVEARRAY_H
#define UTL_PRIMITIVEARRAY_H

#define utl_PrimitiveArray_length(self) \
    (sizeof(self) / sizeof(self[0]))

#endif // UTL_PRIMITIVEARRAY_H
