#include "ARA_error.h"
#include "colors.h"

void show_error(char * message, Error type){
    
    fprintf(stderr,"\n%s%s%s ARA error no : %s%d%s \n\n", COLOR_BRIGHT_MAGENTA, message, COLOR_RESET, COLOR_BRIGHT_RED, type, COLOR_RESET); 
    exit(type);
}

void ARA_error(Error type){
    switch (type)
    {
    case ALLOCATION_ERROR:
        show_error("Allocation failed, check the ram usage.", ALLOCATION_ERROR);
        break;
    case ALREADY_DESTROYED:
        show_error("You tried to destroy an empty object.", ALREADY_DESTROYED);
        break;
    case DESTROYED:
        show_error("You tried to call an empty object.", DESTROYED);
        break;
    
    default:
        show_error("An undefined error occured.", UNDEFINED);
        break;
    }
}