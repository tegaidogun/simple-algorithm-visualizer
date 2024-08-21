#include "shell_sort.hpp"
#include <algorithm>

ShellSort::ShellSort(std::vector<float>& data) : data(data), current_gap(data.size() / 2), current_step(0) {}

bool ShellSort::step() {
    if (current_gap > 0) {
        for (size_t i = current_gap; i < data.size(); ++i) {
            float temp = data[i];
            size_t j;
            for (j = i; j >= current_gap && data[j - current_gap] > temp; j -= current_gap) {
                data[j] = data[j - current_gap];
            }
            data[j] = temp;
        }
        current_gap /= 2;
        return false;  // Sorting is not done yet
    } else {
        return true;  // Sorting is complete
    }
}
