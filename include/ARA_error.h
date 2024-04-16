#ifndef ARAERROR
#define ARAERROR

#include <stdio.h> 
#include <stdlib.h>

typedef enum {
    UNDEFINED = 1000,
    ALLOCATION_ERROR,
    ALREADY_DESTROYED,
    DESTROYED,
}Error;

void show_error(char * message, Error type);
void ARA_error(Error type);

#endif