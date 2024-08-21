#ifndef GUI_MANAGER_HPP
#define GUI_MANAGER_HPP

#include "imgui.h"
#include "bubble_sort.hpp"
#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include <atomic>
#include <condition_variable>
#include <mutex>

class GuiManager {
public:
    GuiManager();
    ~GuiManager();
    void render();
    void generate_random_bars(int count);
    void set_sorting_finished();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    std::chrono::time_point<std::chrono::high_resolution_clock> pause_start_time;  // When the pause started
    std::chrono::high_resolution_clock::duration paused_time;
    float total_time;  // Accumulated time

    std::vector<float> bar_heights;
    std::vector<float> original_bar_heights;
    ImVec4 bar_color;
    ImVec4 background_color;
    std::atomic<bool> sorting_in_progress;
    std::atomic<bool> sorting_paused;

    float delay;
    int comparisons;
    int array_accesses;
    bool running;

    std::unique_ptr<BubbleSort> bubble_sort;
    std::thread sorting_thread;
    std::condition_variable pause_cv;
    std::mutex pause_mutex;

    void start_bubble_sort();
    void stop_sorting_thread();
    void pause_sorting();
    void resume_sorting();
    void reset_sorting();

    void render_menu();
    void render_sort_menu();
    void render_controls_menu();
    void render_randomize_menu();
    void render_change_colors_menu();
    void render_about();
    void render_visualizer();
    void render_statistics();
};

#endif // GUI_MANAGER_HPP
