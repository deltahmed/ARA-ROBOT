/**
 * @file ARA_time.c
 * @author Ahmed A., Rayane M., Abdelwaheb A.
 * @brief Time related functions/methods
 * @version 1.0
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ARA_time.h"
#include "ARA_def.h"

/**
 * @brief Updates the timer by adding the elapsed time since the last update.
 *
 * This function updates the internal timer by calculating the difference in seconds 
 * between the current time and the last recorded time. It also checks for time 
 * inconsistencies.
 *
 * @param self Pointer to self.
 * @throw TIME_TRAVEL_ERROR if their is time inconsistencies.
 */
static void __update_timer(Timer* self){
    Time time_var = time(NULL);
    if(time_var < self->__actual_time){
        ARA_error(TIME_TRAVEL_ERROR);
    }
    self->__timer += (Time)difftime(time_var, self->__actual_time);
    self->__actual_time = time_var;
}


/**
 * @brief Sets the timer to a specified value.
 * @param self Pointer to self.
 * @param value The value to set the timer to.
 */
static void __set_timer(Timer* self, Time value){
    self->__actual_time = time(NULL);
    self->__timer = value;
}

/**
 * @brief Resets the timer to zero.
 * @param self Pointer to self.
 */
static void __reset_timer(Timer* self){
    __set_timer(self, 0);
}


/**
 * @brief Gets the current value of the timer.
 *
 * @param self Pointer to self.
 * @return The current value of the timer.
 */
static Time __get_timer(Timer* self){
    return self->__timer;
}


/**
 * @brief Initializes the Timer structure.
 *
 * @param self Pointer to self.
 */
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
