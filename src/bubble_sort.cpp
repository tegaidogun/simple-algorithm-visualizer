#include "bubble_sort.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <ostream>
#include <thread>

BubbleSort::BubbleSort(std::vector<float>& data, int& comparisons, int& array_accesses, float delay)
    : data(data), current_step(0), comparisons(comparisons), array_accesses(array_accesses), delay(delay) {}

// Define the destructor
BubbleSort::~BubbleSort() = default;

bool BubbleSort::step() {
    if (current_step < data.size() - 1) {
        for (size_t j = 0; j < data.size() - 1 - current_step; ++j) {
            comparisons++;  // Increment comparisons count
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                array_accesses += 4; // 2 reads + 2 writes for swap
            } else {
                array_accesses += 2; // 2 reads if no swap
            }
            std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(delay));  // Apply delay
        }
        current_step++;
        return false;  // Sorting is not done yet
    } else {
        return true;  // Sorting is complete
    }
}
