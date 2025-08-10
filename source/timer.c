#include <time.h>
#include <stdio.h>

#include "timer.h"

int
timer_init(timer_t* timer, double tick_rate)
{
    if (tick_rate <= 0) {
        fprintf(stderr, "passed tick rate below zero\n");
        return 0;
    }
    timer->tick_interval = 1.0 / tick_rate;
    timer->start_time = clock();
    timer->accumulated_time = 0.0;
    return 1;
}

unsigned int
timer_tick(timer_t* timer)
{		
    clock_t current_time;
    double delta_time;
    unsigned int ticks;
    current_time = clock();
    delta_time = (double)(current_time - timer->start_time) / CLOCKS_PER_SEC;    
    timer->accumulated_time += delta_time;
    timer->start_time = current_time;
    ticks = (unsigned int)(timer->accumulated_time / timer->tick_interval);
    timer->accumulated_time -= ticks * timer->tick_interval;
    return ticks;
}