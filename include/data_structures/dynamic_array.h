#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>

typedef struct {
    int *array;
    size_t used;
    size_t size;
} DynamicArray;

void initArray(DynamicArray *a, size_t initialSize);
void insertArray(DynamicArray *a, int element);
void freeArray(DynamicArray *a);

#endif // DYNAMIC_ARRAY_H
