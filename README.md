timer
=====

A simple C timer library that lets you repeat tasks at any rate.

Usage
-----

You simply need to put the `source/timer.h` file in your `include` folder and `source/timer.c` file in your `source` folder.

Here is an example of how you could then use it:

    #include <stdio.h>

    #include "timer.h"

    int main() {
        timer_t timer;
        unsigned int ticks;
        unsigned int i;

        if (!timer_init(&timer, 30)) {
            fprintf(stderr, "failed initializing timer\n");
            return 1;
        }

        for (;;) {
            ticks = timer_tick(&timer);
            for (i = 0; i < ticks; i++) {
                printf("tick (%u)\n", ticks - i);
            }
        }

        return 0;
    }