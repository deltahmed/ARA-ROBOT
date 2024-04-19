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
    case TIME_TRAVEL:
        show_error("Are you a time traveler ? The claculated time is a negative value, do not change the time settings when using the program.", TIME_TRAVEL);
        break;
    case WINDOWS_DO_NOT_EXIST:
        show_error("You tried to call a callable on an non existing window/subwindow.", WINDOWS_DO_NOT_EXIST);
        break;
    
    default:
        show_error("An undefined error occured.", UNDEFINED);
        break;
    }
}