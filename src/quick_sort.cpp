#include "quick_sort.hpp"
#include <utility>   // For std::pair
#include <algorithm> // For std::swap

QuickSort::QuickSort(std::vector<float>& data) : data(data) {
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

    return false;  // Sorting is still in progress
}

int QuickSort::partition(int low, int high) {
    float pivot = data[high];  // Choose the last element as pivot
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (data[j] < pivot) {
            i++;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[high]);
    return i + 1;
}
