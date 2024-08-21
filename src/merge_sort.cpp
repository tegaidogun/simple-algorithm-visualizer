#include "merge_sort.hpp"

MergeSort::MergeSort(std::vector<float>& data)
    : data(data), aux(data.size()), left(0), right(1), mid(0), merging(false) {}

bool MergeSort::step() {
    // Check if we've completed the sorting process
    if (right >= data.size()) {
        right = 1;
        left = 0;
        merging = false;
        mid = 0;
    }

    // If left is beyond the end of the array, sorting is complete
    if (left >= data.size() - 1) return true;

    if (!merging) {
        mid = left + right - 1;
        if (mid >= data.size() - 1) {
            // No need to merge if we've reached the end
            right *= 2;
            left = 0;
            return false;
        }
        merging = true;
    }

    // Perform the merge step
    if (merging) {
        merge(left, mid, std::min(left + right * 2 - 1, data.size() - 1));
        merging = false;
        left += right * 2;
    }

    // Move to the next segment if necessary
    if (left >= data.size() - 1) {
        right *= 2; // Double the segment size for the next level of merging
        left = 0;   // Reset left to start merging from the beginning
    }

    return right >= data.size(); // Sorting is complete when all segments are merged
}

void MergeSort::merge(size_t low, size_t mid, size_t high) {
    size_t i = low, j = mid + 1;
    for (size_t k = low; k <= high; ++k) {
        if (i > mid) aux[k] = data[j++];
        else if (j > high) aux[k] = data[i++];
        else if (data[j] < data[i]) aux[k] = data[j++];
        else aux[k] = data[i++];
    }

    for (size_t k = low; k <= high; ++k) {
        data[k] = aux[k];
    }
}
