#include "gui_manager.hpp"
#include <cstdio>
#include <cstdlib>
#include <ctime>

GuiManager::GuiManager() : bar_color(ImVec4(1.0f, 0.0f, 0.0f, 1.0f)), background_color(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), sorting_in_progress(false) {
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
    merge_sort.reset();
    quick_sort.reset();
}

void GuiManager::set_sorting_finished() {
    sorting_in_progress = false;
}

void GuiManager::start_bubble_sort() {
    bubble_sort = std::unique_ptr<BubbleSort>(new BubbleSort(bar_heights));
    sorting_in_progress = true;
}

void GuiManager::start_merge_sort() {
    merge_sort = std::unique_ptr<MergeSort>(new MergeSort(bar_heights));
    sorting_in_progress = true;
}

void GuiManager::start_quick_sort() {
    quick_sort = std::unique_ptr<QuickSort>(new QuickSort(bar_heights));
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
            // Add configuration options here in the future
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
    if (ImGui::MenuItem("Merge Sort")) {
        start_merge_sort();
    }
    if (ImGui::MenuItem("Quick Sort")) {
        start_quick_sort();
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
    if (ImGui::MenuItem("Generate a Random Amount of Random Values")) {
        int random_count = 10 + (std::rand() % 91);  // Random value between 10 and 100
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
    // Get the current window size
    ImVec2 window_size = ImGui::GetIO().DisplaySize;

    // Calculate the size and position of the bar visualizer window with padding
    float padding = 20.0f;  // Padding from the edges of the viewport
    float visualizer_width = window_size.x * 0.9f;
    float visualizer_height = window_size.y * 0.9f;
    float visualizer_x = (window_size.x - visualizer_width) / 2.0f;
    float visualizer_y = (window_size.y - visualizer_height) / 2.0f;

    // Set the next window position and size
    ImGui::SetNextWindowPos(ImVec2(visualizer_x, visualizer_y), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(visualizer_width, visualizer_height), ImGuiCond_Always);

    // Render the bar visualizer window
    ImGui::Begin("Bar Visualizer", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    ImVec2 p = ImGui::GetCursorScreenPos();

    // Set background color
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImGui::ColorConvertFloat4ToU32(background_color));

    // Calculate the available drawing area considering padding
    float available_width = visualizer_width - 2 * padding;
    float available_height = visualizer_height - 2 * padding;

    // Calculate the width of each bar and spacing between them
    float bar_width = (available_width - (bar_heights.size() - 1) * 5.0f) / bar_heights.size();
    float spacing = 5.0f;

    // Draw the horizontal bar at the bottom
    float horizontal_bar_y = p.y + padding + available_height - 15.0f;  // 10px height for the bar
    draw_list->AddRectFilled(ImVec2(p.x + padding, horizontal_bar_y), ImVec2(p.x + padding + available_width, horizontal_bar_y + 10.0f), IM_COL32(255, 255, 255, 255));

    // Convert ImVec4 color to ImU32 for drawing
    ImU32 bar_color_u32 = ImGui::ColorConvertFloat4ToU32(bar_color);

    // Draw each vertical bar, doubled in height
    for (size_t i = 0; i < bar_heights.size(); ++i) {
        float x = p.x + padding + i * (bar_width + spacing);
        float y = horizontal_bar_y - bar_heights[i] * 2;  // Double the height
        draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + bar_width, horizontal_bar_y), bar_color_u32);
    }

    ImGui::PopStyleColor();
    ImGui::End();
}

void GuiManager::render() {
    render_menu();

    // Perform a step of the active sort if sorting is in progress
    if (sorting_in_progress) {
        if (bubble_sort) {
            sorting_in_progress = !bubble_sort->step();
        } else if (merge_sort) {
            sorting_in_progress = !merge_sort->step();
        } else if (quick_sort) {
            sorting_in_progress = !quick_sort->step();
        }

        // If sorting is finished, clean up the sort object
        if (!sorting_in_progress) {
            bubble_sort.reset();
            merge_sort.reset();
            quick_sort.reset();
        }
    }

    render_visualizer();
}
