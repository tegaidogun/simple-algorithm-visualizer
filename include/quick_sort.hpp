#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <vector>
#include <stack>

class QuickSort {
public:
    QuickSort(std::vector<float>& data, int& comparisons, int& array_accesses, float delay);
    bool step();  // Perform one step of the sort
    bool is_finished() const { return stack.empty(); }

private:
    int partition(int low, int high);
    void run_to_completion(); // Automatically run steps until sorting is complete

    std::vector<float>& data;
    std::stack<std::pair<int, int>> stack;
    int& comparisons;       // Reference to comparison count
    int& array_accesses;    // Reference to array accesses count
    float delay;            // Delay between steps
};

#endif // QUICK_SORT_HPP
