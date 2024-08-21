#include "bubble_sort.hpp"
#include "sorting_stopwatch.hpp"
#include <algorithm>

BubbleSort::BubbleSort(std::vector<float>& data, int& comparisons, int& array_accesses, SortingStopwatch& stopwatch)
    : data(data), current_step(0), comparisons(comparisons), array_accesses(array_accesses), stopwatch(stopwatch) {}

bool BubbleSort::step() {
    stopwatch.start();  // Start the stopwatch

    if (current_step < data.size() - 1) {
        for (size_t j = 0; j < data.size() - 1 - current_step; ++j) {
            comparisons++;  // Increment comparisons count
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                array_accesses += 4; // 2 reads + 2 writes for swap
            } else {
                array_accesses += 2; // 2 reads if no swap
            }
        }
        current_step++;
        stopwatch.stop();  // Stop the stopwatch
        return false;  // Sorting is not done yet
    } else {
        stopwatch.stop();  // Stop the stopwatch
        return true;  // Sorting is complete
    }
}
