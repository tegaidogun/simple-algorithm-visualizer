#include "radix_sort.hpp"
#include <cmath>
#include <algorithm>

RadixSort::RadixSort(std::vector<float>& data) : data(data), current_digit(1) {}

void RadixSort::counting_sort(int exp) {
    output.resize(data.size());
    count.assign(10, 0);

    for (size_t i = 0; i < data.size(); i++) {
        int index = static_cast<int>(data[i] / exp) % 10;
        count[index]++;
    }

    for (size_t i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = data.size() - 1; i >= 0; i--) {
        int index = static_cast<int>(data[i] / exp) % 10;
        output[count[index] - 1] = data[i];
        count[index]--;
    }

    for (size_t i = 0; i < data.size(); i++) {
        data[i] = output[i];
    }
}

bool RadixSort::step() {
    int max_value = *std::max_element(data.begin(), data.end());
    if (current_digit <= max_value) {
        counting_sort(current_digit);
        current_digit *= 10;
        return false;  // Sorting is not done yet
    } else {
        return true;  // Sorting is complete
    }
}
