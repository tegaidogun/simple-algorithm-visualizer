#include "array_utils.h"
#include <stdio.h>
#include <stdlib.h>

// Fill the array with random numbers up to 'range'
void fillArray(int *array, int size, int range) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % range;
    }
}

// Print the array elements
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
