#ifndef ARA_TIME
#define ARATIME
#include <time.h>
#include "ARA_def.h"

typedef time_t Time;
typedef struct __timer_struct{
    Time __start_game_time;
    Time __actual_time;
    Time __timer;
    boolean __paused;

    void (*update)(struct __timer_struct* self);
    void (*set)(struct __timer_struct* self, Time value);
    void (*reset)(struct __timer_struct* self);
    Time (*get) (struct __timer_struct* self);


}Timer;

void Timer_init(Timer* self);


#endif