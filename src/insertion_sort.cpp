#include "insertion_sort.hpp"

InsertionSort::InsertionSort(std::vector<float>& data) : data(data), current_step(1), sorted_index(1) {}

bool InsertionSort::step() {
    if (current_step < data.size()) {
        float key = data[current_step];
        size_t j = current_step;

        while (j > 0 && data[j - 1] > key) {
            data[j] = data[j - 1];
            j--;
        }
        data[j] = key;

        current_step++;
        return false;  // Sorting is not done yet
    } else {
        return true;  // Sorting is complete
    }
}
