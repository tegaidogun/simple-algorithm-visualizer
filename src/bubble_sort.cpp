#include "bubble_sort.hpp"
#include <algorithm>

BubbleSort::BubbleSort(std::vector<float>& data) : data(data), current_step(0) {}

bool BubbleSort::step() {
    if (current_step < data.size() - 1) {
        for (size_t j = 0; j < data.size() - 1 - current_step; ++j) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
            }
        }
        current_step++;
        return false;  // Sorting is not done yet
    } else {
        return true;  // Sorting is complete
    }
}
