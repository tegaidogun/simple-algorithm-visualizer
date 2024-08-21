#include "quick_sort.hpp"
#include <utility>   // For std::pair
#include <algorithm> // For std::swap
#include <chrono>    // For std::chrono::duration

QuickSort::QuickSort(std::vector<float>& data, int& comparisons, int& array_accesses, float delay)
    : data(data), comparisons(comparisons), array_accesses(array_accesses), delay(delay) {
    if (data.size() > 1) {
        stack.push(std::make_pair(0, data.size() - 1));
    }

    // Automatically run steps until sorting is complete
    run_to_completion();
}

void QuickSort::run_to_completion() {
    int max_steps = data.size() * data.size();  // Worst case O(n^2) steps
    int steps = 0;

    while (!is_finished() && steps < max_steps) {
        step();
        steps++;
    }
}

bool QuickSort::step() {
    if (stack.empty()) {
        return true;  // Sorting is finished
    }

    // Get the current range to partition
    std::pair<int, int> range = stack.top();
    stack.pop();

    int low = range.first;
    int high = range.second;

    // Perform the partition operation
    int p = partition(low, high);

    // Push new sub-ranges to stack for further sorting
    if (p - 1 > low) {
        stack.push(std::make_pair(low, p - 1));
    }
    if (p + 1 < high) {
        stack.push(std::make_pair(p + 1, high));
    }

    // Busy-wait loop for the delay
    auto start_time = std::chrono::high_resolution_clock::now();
    while (std::chrono::duration<float, std::milli>(std::chrono::high_resolution_clock::now() - start_time).count() < delay) {
        // Busy-wait loop
    }

    return false;  // Sorting is still in progress
}

int QuickSort::partition(int low, int high) {
    float pivot = data[high];  // Choose the last element as pivot
    array_accesses++;  // Access pivot element

    int i = low - 1;

    for (int j = low; j < high; ++j) {
        comparisons++;  // Compare data[j] with pivot
        array_accesses++;  // Access data[j]
        if (data[j] < pivot) {
            i++;
            std::swap(data[i], data[j]);
            array_accesses += 4;  // 2 reads + 2 writes for swap
        }
    }
    std::swap(data[i + 1], data[high]);
    array_accesses += 4;  // 2 reads + 2 writes for swap

    // Busy-wait loop for the delay
    auto start_time = std::chrono::high_resolution_clock::now();
    while (std::chrono::duration<float, std::milli>(std::chrono::high_resolution_clock::now() - start_time).count() < delay) {
        // Busy-wait loop
    }

    return i + 1;
}
