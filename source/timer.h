#ifndef TIMER_H
#define TIMER_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <time.h>

typedef struct {
    double tick_interval;
    clock_t start_time;
    double accumulated_time;
} timer_t;

int timer_init(timer_t* timer, double tick_rate);
unsigned int timer_tick(timer_t* timer);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* TIMER_H */