#include "merge_sort.hpp"
#include <algorithm> // For std::min
#include <chrono>    // For std::chrono::duration

MergeSort::MergeSort(std::vector<float>& data, int& comparisons, int& array_accesses, float delay)
    : data(data), aux(data.size()), left(0), right(1), mid(0), merging(false),
      comparisons(comparisons), array_accesses(array_accesses), delay(delay) {}

bool MergeSort::step() {
    if (right >= data.size()) {
        right = 1;
        left = 0;
        merging = false;
        mid = 0;
    }

    if (left >= data.size() - 1) return true;

    if (!merging) {
        mid = left + right - 1;
        if (mid >= data.size() - 1) {
            right *= 2;
            left = 0;
            return false;
        }
        merging = true;
    }

    if (merging) {
        merge(left, mid, std::min(left + right * 2 - 1, data.size() - 1));
        merging = false;
        left += right * 2;
    }

    if (left >= data.size() - 1) {
        right *= 2;
        left = 0;
    }

    // Busy-wait loop for the delay
    auto start_time = std::chrono::high_resolution_clock::now();
    while (std::chrono::duration<float, std::milli>(std::chrono::high_resolution_clock::now() - start_time).count() < delay) {
        // Busy-wait loop
    }

    return right >= data.size();
}

void MergeSort::merge(size_t low, size_t mid, size_t high) {
    size_t i = low, j = mid + 1;
    for (size_t k = low; k <= high; ++k) {
        if (i > mid) {
            aux[k] = data[j++];
            array_accesses += 2;  // 1 read from data[j] and 1 write to aux[k]
        } else if (j > high) {
            aux[k] = data[i++];
            array_accesses += 2;  // 1 read from data[i] and 1 write to aux[k]
        } else {
            comparisons++;  // Comparison between data[j] and data[i]
            if (data[j] < data[i]) {
                aux[k] = data[j++];
                array_accesses += 2;  // 1 read from data[j] and 1 write to aux[k]
            } else {
                aux[k] = data[i++];
                array_accesses += 2;  // 1 read from data[i] and 1 write to aux[k]
            }
        }

        // Busy-wait loop for the delay
        auto start_time = std::chrono::high_resolution_clock::now();
        while (std::chrono::duration<float, std::milli>(std::chrono::high_resolution_clock::now() - start_time).count() < delay) {
            // Busy-wait loop
        }
    }

    for (size_t k = low; k <= high; ++k) {
        data[k] = aux[k];
        array_accesses += 2;  // 1 read from aux[k] and 1 write to data[k]

        // Busy-wait loop for the delay
        auto start_time = std::chrono::high_resolution_clock::now();
        while (std::chrono::duration<float, std::milli>(std::chrono::high_resolution_clock::now() - start_time).count() < delay) {
            // Busy-wait loop
        }
    }
}
