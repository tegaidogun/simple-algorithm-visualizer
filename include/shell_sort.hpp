#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include <vector>
#include <cstddef>

class ShellSort {
public:
    ShellSort(std::vector<float>& data);
    bool step();  // Performs one step of shell sort, returns true if sorting is done

private:
    std::vector<float>& data;  // Reference to the data being sorted
    size_t current_gap;  // Current gap value in shell sort
    size_t current_step;  // Current step in the shell sort
};

#endif // SHELL_SORT_HPP
