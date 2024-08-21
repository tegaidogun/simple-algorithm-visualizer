#ifndef GUI_MANAGER_HPP
#define GUI_MANAGER_HPP

#include "imgui.h"
#include "bubble_sort.hpp"
#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include <atomic>

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
    std::atomic<bool> sorting_in_progress;  // Use atomic for thread safety

    float delay;           // Delay in milliseconds
    int comparisons;       // Number of comparisons
    int array_accesses;    // Number of array accesses
    float total_time;      // Total time taken

    std::chrono::time_point<std::chrono::high_resolution_clock> start_time; // Start time of sorting
    bool running;          // Is the stopwatch running

    std::unique_ptr<BubbleSort> bubble_sort;
    std::thread sorting_thread;  // Sorting thread
    std::atomic<bool> sorting_thread_active;  // To track if the sorting thread is active

    void start_bubble_sort();
    void render_menu();
    void render_sort_menu();
    void render_randomize_menu();
    void render_change_colors_menu();
    void render_about();
    void render_visualizer();
    void render_statistics();

    void stop_sorting_thread();
};

#endif // GUI_MANAGER_HPP
