#include "ARA_time.h"
#include "ARA_def.h"


static void __update_timer(Timer* self){
    Time time_var = time(NULL);
    if(time_var < self->__actual_time){
        ARA_error(TIME_TRAVEL_ERROR);
    }
    self->__timer += (Time)difftime(time_var, self->__actual_time);
    self->__actual_time = time_var;
}
static void __set_timer(Timer* self, Time value){
    self->__actual_time = time(NULL);
    self->__timer = value;
}
static void __reset_timer(Timer* self){
    __set_timer(self, 0);
}

static Time __get_timer(Timer* self){
    return self->__timer;
}

void Timer_init(Timer* self){
    Time time_var = time(NULL);
    self->__start_game_time = time_var;
    self->__actual_time = time_var;
    self->__timer = 0;

    self->get = __get_timer;
    self->reset = __reset_timer;
    self->set = __set_timer;
    self->update = __update_timer;
}
