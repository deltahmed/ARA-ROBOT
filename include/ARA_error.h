/**
 * @file ARA_error.h
 * @author Ahmed A., Rayane M., Abdelwaheb A.
 * @brief Error handling header
 * @version 1.0
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef ARAERROR
#define ARAERROR

#include <stdio.h> 
#include <stdlib.h>


/**
 * @brief This macro calls the ARA_error_function with the necessary arguments to show where the ARA error is.
 *
 * @param type The type of error to log, represented by the Error enum.
 */
#define ARA_error(type) (ARA_error_function(type, __FILE__,  __FUNCTION__, __LINE__))

/**
 * @brief Enumeration of all possible ARA error types.
 */
typedef enum __error_enum {
    UNDEFINED_ERROR = 1000,
    ALLOCATION_ERROR,
    ALREADY_DESTROYED_ERROR,
    EMPTY_OBJ_ERROR,
    TIME_TRAVEL_ERROR,
    WINDOWS_DO_NOT_EXIST_ERROR,
    NOCOLOR_ERROR,
    PLAYER_DIRECTION_ERROR,
    VALUE_ERROR,
    FILE_ERROR
    
}Error;

void show_error(char * message, Error type);
void show_error_line(char * message, Error type, const char * file, const char * function, int line);
void ARA_error_function(Error type, const char * file, const char * function, int line);



#endif


