#include "heap_sort.hpp"
#include <algorithm>

HeapSort::HeapSort(std::vector<float>& data) : data(data), heap_size(data.size()), current_step(heap_size) {
    // Build the heap
    for (size_t i = heap_size / 2 - 1; i < heap_size; --i) {
        heapify(heap_size, i);
    }
}

void HeapSort::heapify(size_t n, size_t i) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n && data[left] > data[largest]) {
        largest = left;
    }

    if (right < n && data[right] > data[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(data[i], data[largest]);
        heapify(n, largest);
    }
}

bool HeapSort::step() {
    if (current_step > 1) {
        std::swap(data[0], data[current_step - 1]);
        current_step--;
        heapify(current_step, 0);
        return false;  // Sorting is not done yet
    } else {
        return true;  // Sorting is complete
    }
}
