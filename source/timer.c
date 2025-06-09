#include <time.h>

#include "timer.h"

int timer_init(timer_t* timer, double tick_rate) {
    if (tick_rate <= 0) {
        return 0;
    }

    timer->tick_interval = 1.0 / tick_rate;
    timer->start_time = clock();
    timer->accumulated_time = 0.0;

    return 1;
}

unsigned int timer_tick(timer_t* timer) {		
    clock_t current_time = clock();

    double delta_time = (double)(current_time - timer->start_time) / CLOCKS_PER_SEC;    

    timer->accumulated_time += delta_time;

    timer->start_time = current_time;

    unsigned int ticks = (unsigned int)(timer->accumulated_time / timer->tick_interval);

    timer->accumulated_time -= ticks * timer->tick_interval;

    return ticks;
}