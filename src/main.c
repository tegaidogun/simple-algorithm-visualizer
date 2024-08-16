#include <stdio.h>
#include <stdlib.h>
#include "utils/array_utils.h"
#include "utils/timer.h"
#include "algorithms/bubble_sort.h"
#include "algorithms/quick_sort.h"
#include "algorithms/merge_sort.h"

// Function prototypes
void run_sort(void (*sort_func)(int*, int), int *array, int size);

int main() {
    int choice, size;
    printf("Select sorting algorithm:\n");
    printf("1: Bubble Sort\n");
    printf("2: Quick Sort\n");
    printf("3: Merge Sort\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter size of array: ");
    scanf("%d", &size);

    int *array = malloc(size * sizeof(int));
    if (!array) {
        perror("Failed to allocate memory for array");
        return EXIT_FAILURE;
    }

    fillArray(array, size, 1000);  // Fill array with random numbers up to 1000
    printf("Original Array:\n");
    printArray(array, size);

    switch (choice) {
        case 1:
            run_sort(bubble_sort, array, size);
            break;
        case 2:
            run_sort(quick_sort, array, 0, size - 1);
            printArray(array, size); // Quick sort is in-place, print after sorting
            break;
        case 3:
            run_sort(merge_sort, array, 0, size - 1);
            printArray(array, size); // Merge sort is in-place, print after sorting
            break;
        default:
            printf("Invalid choice\n");
    }

    free(array);
    return 0;
}

void run_sort(void (*sort_func)(int*, int), int *array, int size) {
    struct timeval start;
    startTimer(&start);
    sort_func(array, size);
    double elapsed = stopTimer(&start);

    printf("Sorted Array:\n");
    printArray(array, size);
    printf("Time taken: %.2f seconds\n", elapsed);
}
