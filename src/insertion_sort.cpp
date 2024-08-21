#include "insertion_sort.hpp"
#include <chrono>  // For std::chrono::duration

InsertionSort::InsertionSort(std::vector<float>& data, int& comparisons, int& array_accesses, float delay)
    : data(data), current_step(1), sorted_index(1), comparisons(comparisons), array_accesses(array_accesses), delay(delay) {}

bool InsertionSort::step() {
    if (current_step < data.size()) {
        float key = data[current_step];
        array_accesses++;  // Reading key
        size_t j = current_step;

        while (j > 0 && data[j - 1] > key) {
            comparisons++;  // Comparison in while loop
            data[j] = data[j - 1];
            array_accesses += 2;  // One read and one write
            j--;

            // Busy-wait loop for the delay
            auto start_time = std::chrono::high_resolution_clock::now();
            while (std::chrono::duration<float, std::milli>(std::chrono::high_resolution_clock::now() - start_time).count() < delay) {
                // Busy-wait loop
            }
        }
        comparisons++;  // Final comparison in while loop
        data[j] = key;
        array_accesses++;  // Final write

        current_step++;

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
