#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <vector>
#include <cstddef>

class InsertionSort {
public:
    InsertionSort(std::vector<float>& data, int& comparisons, int& array_accesses, float delay);
    bool step();  // Performs one step of insertion sort, returns true if sorting is done

private:
    std::vector<float>& data;  // Reference to the data being sorted
    size_t current_step;  // Current step in the insertion sort
    size_t sorted_index;  // Index of the sorted portion
    int& comparisons;       // Reference to comparison count
    int& array_accesses;    // Reference to array accesses count
    float delay;            // Delay between steps
};

#endif // INSERTION_SORT_HPP
