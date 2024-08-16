#ifndef TIMER_H
#define TIMER_H

#include <sys/time.h>

void startTimer(struct timeval *start);
double stopTimer(struct timeval *start);

#endif // TIMER_H
