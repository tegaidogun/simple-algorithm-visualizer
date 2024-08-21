#include "selection_sort.hpp"
#include <algorithm>

SelectionSort::SelectionSort(std::vector<float>& data) : data(data), current_step(0), min_index(0) {}

bool SelectionSort::step() {
    if (current_step < data.size() - 1) {
        min_index = current_step;

        for (size_t j = current_step + 1; j < data.size(); ++j) {
            if (data[j] < data[min_index]) {
                min_index = j;
            }
        }

        std::swap(data[current_step], data[min_index]);
        current_step++;
        return false;  // Sorting is not done yet
    } else {
        return true;  // Sorting is complete
    }
}
