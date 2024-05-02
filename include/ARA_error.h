#ifndef ARAERROR
#define ARAERROR

#include <stdio.h> 
#include <stdlib.h>

#define ARA_error(type) (ARA_error_function(type, __FILE__,  __FUNCTION__, __LINE__))


typedef enum __error_enum {
    UNDEFINED_ERROR = 1000,
    ALLOCATION_ERROR,
    ALREADY_DESTROYED_ERROR,
    EMPTY_OBJ_ERROR,
    TIME_TRAVEL_ERROR,
    WINDOWS_DO_NOT_EXIST_ERROR,
    NOCOLOR_ERROR,
    PLAYER_DIRECTION_ERROR,
}Error;

void show_error(char * message, Error type);
void show_error_line(char * message, Error type, const char * file, const char * function, int line);
void ARA_error_function(Error type, const char * file, const char * function, int line);



#endif