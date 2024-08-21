#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <vector>
#include <cstddef>

class SelectionSort {
public:
    SelectionSort(std::vector<float>& data);
    bool step();  // Performs one step of selection sort, returns true if sorting is done

private:
    std::vector<float>& data;  // Reference to the data being sorted
    size_t current_step;  // Current step in the selection sort
    size_t min_index;  // Index of the minimum element found
};

#endif // SELECTION_SORT_HPP
