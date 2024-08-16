#include "quick_sort.h"

// Function to perform the partition operation for Quick Sort
static int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    int temp;

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}

// Recursive function to perform Quick Sort
void quick_sort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}
