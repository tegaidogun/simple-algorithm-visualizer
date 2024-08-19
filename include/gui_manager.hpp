#ifndef GUI_MANAGER_HPP
#define GUI_MANAGER_HPP

#include "imgui.h"
#include "bubble_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"
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
    std::unique_ptr<BubbleSort> bubble_sort;
    std::unique_ptr<MergeSort> merge_sort;
    std::unique_ptr<QuickSort> quick_sort;

    void start_bubble_sort();
    void start_merge_sort();
    void start_quick_sort();
    void render_menu();
    void render_sort_menu();
    void render_randomize_menu();
    void render_change_colors_menu();
    void render_about();
    void render_visualizer();
};

#endif // GUI_MANAGER_HPP
