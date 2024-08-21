#include "gui_manager.hpp"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <thread>

GuiManager::GuiManager()
    : bar_color(ImVec4(1.0f, 0.0f, 0.0f, 1.0f)),
      background_color(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)),
      sorting_in_progress(false),
      delay(5.0f),       // Default delay set to 5ms
      comparisons(0),    // Initialize comparisons
      array_accesses(0)  // Initialize array accesses
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    generate_random_bars(25);
}

GuiManager::~GuiManager() {
    // Destructor ensures cleanup
}

void GuiManager::generate_random_bars(int count) {
    bar_heights.clear();
    for (int i = 0; i < count; ++i) {
        bar_heights.push_back(static_cast<float>(std::rand() % 100) / 100.0f * 200.0f);
    }
    sorting_in_progress = false;
    bubble_sort.reset();
    // Reset statistics
    delay = 5.0f;
    comparisons = 0;
    array_accesses = 0;
}

void GuiManager::set_sorting_finished() {
    sorting_in_progress = false;
}

void GuiManager::start_bubble_sort() {
    comparisons = 0;
    array_accesses = 0;
    stopwatch.reset(new SortingStopwatch());  // Initialize stopwatch
    bubble_sort.reset(new BubbleSort(bar_heights, comparisons, array_accesses, *stopwatch)); // Pass stopwatch
    sorting_in_progress = true;
}

void GuiManager::render_menu() {
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("Sort")) {
            render_sort_menu();
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Randomize")) {
            render_randomize_menu();
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Change Colors")) {
            render_change_colors_menu();
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Configurations")) {
            ImGui::SliderFloat("Set Delay (ms)", &delay, 0.0f, 1000.0f, "%.2f ms");
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("About")) {
            render_about();
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void GuiManager::render_sort_menu() {
    ImGui::BeginDisabled(sorting_in_progress);
    if (ImGui::MenuItem("Bubble Sort")) {
        start_bubble_sort();
    }
    ImGui::EndDisabled();
}

void GuiManager::render_randomize_menu() {
    if (ImGui::MenuItem("Generate 25 Random Values")) {
        generate_random_bars(25);
    }
    if (ImGui::MenuItem("Generate 50 Random Values")) {
        generate_random_bars(50);
    }
    if (ImGui::MenuItem("Generate 75 Random Values")) {
        generate_random_bars(75);
    }
    if (ImGui::MenuItem("Generate 100 Random Values")) {
        generate_random_bars(100);
    }
    if (ImGui::MenuItem("Generate 1000 Random Values")) {
        generate_random_bars(1000);
    }
    if (ImGui::MenuItem("Generate a Random Amount of Random Values")) {
        int random_count = 10 + (std::rand() % 991);  // Random value between 10 and 1000
        generate_random_bars(random_count);
    }
}

void GuiManager::render_change_colors_menu() {
    ImGui::ColorEdit4("Bar Color", (float*)&bar_color);
    ImGui::ColorEdit4("Background Color", (float*)&background_color);
}

void GuiManager::render_about() {
    ImGui::TextWrapped("Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                       "Vestibulum imperdiet felis at justo varius, et tristique eros suscipit.");
}

void GuiManager::render_visualizer() {
    ImVec2 window_size = ImGui::GetIO().DisplaySize;
    float padding = 20.0f;
    float menu_bar_height = ImGui::GetFrameHeight();
    float visualizer_width = window_size.x * 0.7f - 2 * padding;
    float visualizer_height = window_size.y - menu_bar_height - 2 * padding;

    ImGui::SetNextWindowPos(ImVec2(padding, menu_bar_height + padding), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(visualizer_width, visualizer_height), ImGuiCond_Always);

    ImGui::Begin("Bar Visualizer", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    ImVec2 p = ImGui::GetCursorScreenPos();

    float available_width = visualizer_width;
    float available_height = visualizer_height - 2 * padding;
    float bar_width = (available_width - 2 * padding - (bar_heights.size() - 1) * 5.0f) / bar_heights.size();
    float spacing = 5.0f;

    float horizontal_bar_y = p.y + available_height - 15.0f;
    draw_list->AddRectFilled(ImVec2(p.x - 10.0f, horizontal_bar_y), ImVec2(p.x + available_width, horizontal_bar_y + 15.0f),
                             IM_COL32(255, 255, 255, 255));

    ImU32 bar_color_u32 = ImGui::ColorConvertFloat4ToU32(bar_color);
    for (size_t i = 0; i < bar_heights.size(); ++i) {
        float x = p.x - 10.0f + padding + i * (bar_width + spacing);
        float y = horizontal_bar_y - bar_heights[i] * 2;
        draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + bar_width, horizontal_bar_y), bar_color_u32);
    }

    ImGui::End();
}

void GuiManager::render_statistics() {
    ImVec2 window_size = ImGui::GetIO().DisplaySize;
    float padding = 20.0f;
    float menu_bar_height = ImGui::GetFrameHeight();
    float dialog_width = window_size.x * 0.3f - 2 * padding;
    float dialog_height = window_size.y - menu_bar_height - 2 * padding;

    ImGui::SetNextWindowPos(ImVec2(window_size.x * 0.7f + padding, menu_bar_height + padding), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(dialog_width, dialog_height), ImGuiCond_Always);

    ImGui::Begin("Statistics", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);

    ImGui::Text("Delay: %.4f ms", delay);
    ImGui::Text("Comparisons: %d", comparisons);
    ImGui::Text("Array Accesses: %d", array_accesses);
    ImGui::Text("Total Time Taken: %.2f s", total_time);

    ImGui::End();
}

void GuiManager::render() {
    render_menu();

    if (sorting_in_progress) {
        if (bubble_sort) {
            sorting_in_progress = !bubble_sort->step();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(delay)));

        if (!sorting_in_progress) {
            bubble_sort.reset();
        }
    }

    render_visualizer();
    render_statistics();
}
