#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include <vector>
#include <cstddef>

class HeapSort {
public:
    HeapSort(std::vector<float>& data, int& comparisons, int& array_accesses, float delay);
    bool step();  // Performs one step of heap sort, returns true if sorting is done

private:
    std::vector<float>& data;  // Reference to the data being sorted
    size_t heap_size;  // Size of the heap
    size_t current_step;  // Current step in the heap sort
    int& comparisons;       // Reference to comparison count
    int& array_accesses;    // Reference to array accesses count
    float delay;            // Delay between steps

    void heapify(size_t n, size_t i);
};

#endif // HEAP_SORT_HPP
