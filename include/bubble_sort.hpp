#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <vector>
#include <cstddef>
#include "sorting_stopwatch.hpp"

class BubbleSort {
public:
    BubbleSort(std::vector<float>& data, int& comparisons, int& array_accesses, SortingStopwatch& stopwatch);
    bool step();  // Performs one step of bubble sort, returns true if sorting is done

private:
    std::vector<float>& data;  // Reference to the data being sorted
    size_t current_step;  // Current step in the bubble sort
    int& comparisons;  // Reference to comparison count
    int& array_accesses;  // Reference to array accesses count
    SortingStopwatch& stopwatch;  // Reference to the stopwatch
};

#endif // BUBBLE_SORT_HPP
