#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <vector>
#include <stack>

class QuickSort {
public:
    QuickSort(std::vector<float>& data);
    bool step();  // Perform one step of the sort
    bool is_finished() const { return stack.empty(); }

private:
    int partition(int low, int high);
    void run_to_completion(); // Add this declaration

    std::vector<float>& data;
    std::stack<std::pair<int, int>> stack;
};

#endif // QUICK_SORT_HPP
