#ifndef ARA_TIME
#define ARA_TIME
#include <time.h>
#include "ARA_def.h"


typedef time_t Time;

/**
 * @brief The Timer definition with all the methods.
 * 
 */
typedef struct __timer_struct{
    Time __start_game_time;
    Time __actual_time;
    Time __timer;
    char __paused;

    /**
     * @brief Updates the timer by adding the elapsed time since the last update.
     *
     * @param self Pointer to self.
     * @throw TIME_TRAVEL_ERROR if their is time inconsistencies.
     */
    void (*update)(struct __timer_struct* self);
    /**
     * @brief Sets the timer to a specified value.
     * @param self Pointer to self.
     * @param value The value to set the timer to.
     */
    void (*set)(struct __timer_struct* self, Time value);
    /**
     * @brief Resets the timer to zero.
     * @param self Pointer to self.
     */
    void (*reset)(struct __timer_struct* self);
    
    /**
     * @brief Gets the current value of the timer.
     *
     * @param self Pointer to self.
     * @return The current value of the timer.
     */
    Time (*get) (struct __timer_struct* self);


}Timer;

void Timer_init(Timer* self);


#endif