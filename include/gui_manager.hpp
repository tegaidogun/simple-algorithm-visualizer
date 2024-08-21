#ifndef GUI_MANAGER_HPP
#define GUI_MANAGER_HPP

#include "imgui.h"
#include "bubble_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"
#include "insertion_sort.hpp"
#include "selection_sort.hpp"
#include "heap_sort.hpp"
#include "shell_sort.hpp"
#include "radix_sort.hpp"
#include <vector>
#include <memory>

class GuiManager {
public:
    GuiManager();
    ~GuiManager();
    void render();
    void generate_random_bars(int count);
    void set_sorting_finished();

private:
    std::vector<float> bar_heights;
    ImVec4 bar_color;
    ImVec4 background_color;
    bool sorting_in_progress;

    float delay;           // Delay in milliseconds
    int comparisons;       // Number of comparisons
    int array_accesses;    // Number of array accesses
    float total_time;      // Total time taken in seconds


    // Sorting-related member variables
    std::unique_ptr<BubbleSort> bubble_sort;

    // Stopwatch for time measurement
    std::unique_ptr<SortingStopwatch> stopwatch;


    void start_bubble_sort();
    /*void start_merge_sort();
    void start_quick_sort();
    void start_insertion_sort();
    void start_selection_sort();
    void start_heap_sort();
    void start_shell_sort();
    void start_radix_sort();*/

    void render_menu();
    void render_sort_menu();
    void render_randomize_menu();
    void render_change_colors_menu();
    void render_about();
    void render_visualizer();
    void render_statistics();

    // Helper functions to update statistics
    void update_statistics();
};

#endif // GUI_MANAGER_HPP
