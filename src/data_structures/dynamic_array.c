#include "dynamic_array.h"

// Initialize array with initial size
void initArray(DynamicArray *a, size_t initialSize) {
    a->array = malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
}

// Insert element into array
void insertArray(DynamicArray *a, int element) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}

// Free array
void freeArray(DynamicArray *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}
