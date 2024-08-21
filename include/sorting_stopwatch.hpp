#ifndef SORTING_STOPWATCH_HPP
#define SORTING_STOPWATCH_HPP

#include <chrono>

class SortingStopwatch {
public:
    SortingStopwatch();

    void start();  // Starts the stopwatch
    void stop();   // Stops the stopwatch
    float get_elapsed_time() const;  // Returns the elapsed time in seconds

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    std::chrono::time_point<std::chrono::high_resolution_clock> end_time;
    bool running;
};

#endif // SORTING_STOPWATCH_HPP
