#ifndef ARAERROR
#define ARAERROR

#include <stdio.h> 
#include <stdlib.h>

typedef enum __error_enum {
    UNDEFINED = 1000,
    ALLOCATION_ERROR,
    ALREADY_DESTROYED,
    DESTROYED,
    TIME_TRAVEL,
    WINDOWS_DO_NOT_EXIST,
}Error;

void show_error(char * message, Error type);
void ARA_error(Error type);

#endif