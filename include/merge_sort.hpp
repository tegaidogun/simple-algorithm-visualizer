#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>
#include <cstddef>

class MergeSort {
public:
    MergeSort(std::vector<float>& data);
    bool step();  // Perform one step of merge sort, returns true if sorting is done

private:
    std::vector<float>& data;
    std::vector<float> aux;
    size_t left, right, mid;
    bool merging;

    void merge(size_t low, size_t mid, size_t high);
};

#endif // MERGE_SORT_HPP
