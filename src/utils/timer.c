#include "timer.h"

// Start the timer
void startTimer(struct timeval *start) {
    gettimeofday(start, NULL);
}

// Stop the timer and return elapsed time in seconds
double stopTimer(struct timeval *start) {
    struct timeval end;
    gettimeofday(&end, NULL);
    double elapsed = (end.tv_sec - start->tv_sec) +
                     (end.tv_usec - start->tv_usec) / 1000000.0;
    return elapsed;
}
