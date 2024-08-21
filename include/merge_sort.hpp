#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>
#include <cstddef>

class MergeSort {
public:
    MergeSort(std::vector<float>& data, int& comparisons, int& array_accesses, float delay);
    bool step();  // Perform one step of merge sort, returns true if sorting is done

private:
    std::vector<float>& data;
    std::vector<float> aux;
    size_t left, right, mid;
    bool merging;

    int& comparisons;       // Reference to comparison count
    int& array_accesses;    // Reference to array accesses count
    float delay;            // Delay between steps

    void merge(size_t low, size_t mid, size_t high);
};

#endif // MERGE_SORT_HPP
