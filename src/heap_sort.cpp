#include "heap_sort.hpp"
#include <algorithm>
#include <chrono>  // For std::chrono::duration

HeapSort::HeapSort(std::vector<float>& data, int& comparisons, int& array_accesses, float delay)
    : data(data), heap_size(data.size()), current_step(heap_size), comparisons(comparisons), array_accesses(array_accesses), delay(delay) {
    // Build the heap
    for (size_t i = heap_size / 2 - 1; i < heap_size; --i) {
        heapify(heap_size, i);
    }
}

void HeapSort::heapify(size_t n, size_t i) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    comparisons++;  // Comparison for left child
    if (left < n && data[left] > data[largest]) {
        largest = left;
    }

    comparisons++;  // Comparison for right child
    if (right < n && data[right] > data[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(data[i], data[largest]);
        array_accesses += 4;  // 2 reads and 2 writes for the swap

        // Busy-wait loop for the delay
        auto start_time = std::chrono::high_resolution_clock::now();
        while (std::chrono::duration<float, std::milli>(std::chrono::high_resolution_clock::now() - start_time).count() < delay) {
            // Busy-wait loop
        }

        heapify(n, largest);
    }
}

bool HeapSort::step() {
    if (current_step > 1) {
        std::swap(data[0], data[current_step - 1]);
        array_accesses += 4;  // 2 reads and 2 writes for the swap
        current_step--;
        heapify(current_step, 0);

        // Busy-wait loop for the delay
        auto start_time = std::chrono::high_resolution_clock::now();
        while (std::chrono::duration<float, std::milli>(std::chrono::high_resolution_clock::now() - start_time).count() < delay) {
            // Busy-wait loop
        }

        return false;  // Sorting is not done yet
    } else {
        return true;  // Sorting is complete
    }
}
