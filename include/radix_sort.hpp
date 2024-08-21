#ifndef RADIX_SORT_HPP
#define RADIX_SORT_HPP

#include <vector>
#include <cstddef>

class RadixSort {
public:
    RadixSort(std::vector<float>& data);
    bool step();  // Performs one step of radix sort, returns true if sorting is done

private:
    std::vector<float>& data;  // Reference to the data being sorted
    int current_digit;  // Current digit being sorted
    std::vector<float> output;  // Output array used for sorting
    std::vector<int> count;  // Count array for counting sort

    void counting_sort(int exp);
};

#endif // RADIX_SORT_HPP
