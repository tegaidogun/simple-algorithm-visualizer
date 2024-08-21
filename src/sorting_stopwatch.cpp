#include "sorting_stopwatch.hpp"

SortingStopwatch::SortingStopwatch() : running(false) {}

void SortingStopwatch::start() {
    start_time = std::chrono::high_resolution_clock::now();
    running = true;
}

void SortingStopwatch::stop() {
    if (running) {
        end_time = std::chrono::high_resolution_clock::now();
        running = false;
    }
}

float SortingStopwatch::get_elapsed_time() const {
    if (running) {
        auto current_time = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<float>(current_time - start_time).count();
    } else {
        return std::chrono::duration<float>(end_time - start_time).count();
    }
}
