#include "ARA_error.h"
#include "colors.h"

void show_error(char * message, Error type){
    endwin();
    fprintf(stderr,"\n%s%s%s ARA error no : %s%d%s \n\n", ARA_COLOR_BRIGHT_MAGENTA, message, ARA_COLOR_RESET, ARA_COLOR_BRIGHT_RED, type, ARA_COLOR_RESET); 
    exit(type);
}

void show_error_line(char * message, Error type, const char * file, const char * function, int line){
    endwin();
    fprintf(stderr,"\n%s%s%s ARA error no : %s%d%s\n", ARA_COLOR_BRIGHT_MAGENTA, message, ARA_COLOR_RESET, ARA_COLOR_BRIGHT_RED, type, ARA_COLOR_RESET);
    fprintf(stderr,"Occurred in file : `%s%s%s`, in function : `%s%s%s`, in line : %s%d%s \n\n", ARA_COLOR_BRIGHT_RED, file, ARA_COLOR_RESET, ARA_COLOR_BRIGHT_RED, function, ARA_COLOR_RESET, ARA_COLOR_BRIGHT_RED, line, ARA_COLOR_RESET ); 

    exit(type);
}

void ARA_error_function(Error type, const char * file, const char * function, int line){
    switch (type)
    {
    case ALLOCATION_ERROR:
        show_error("Allocation failed, check the ram usage.", ALLOCATION_ERROR);
        break;
    case ALREADY_DESTROYED_ERROR:
        show_error_line("You tried to destroy an empty object.", ALREADY_DESTROYED_ERROR, file, function, line);
        break;
    case EMPTY_OBJ_ERROR:
        show_error_line("You tried to call an empty object.", EMPTY_OBJ_ERROR, file, function, line);
        break;
    case TIME_TRAVEL_ERROR:
        show_error("Are you a time traveler ? The calculated time is a negative value, do not change the time settings when using the program.", TIME_TRAVEL_ERROR);
        break;
    case WINDOWS_DO_NOT_EXIST_ERROR:
        show_error_line("You tried to call a callable on an non existing window/subwindow.", WINDOWS_DO_NOT_EXIST_ERROR, file, function, line);
        break;
    case NOCOLOR_ERROR:
        show_error("Your terminal does not support color.", NOCOLOR_ERROR);
        break;
    case PLAYER_DIRECTION_ERROR:
        show_error_line("Invalid direction.", PLAYER_DIRECTION_ERROR, file, function, line);
        break;

    case VALUE_ERROR:
        show_error_line("An Value error occured.", VALUE_ERROR, file, function, line);
        break;
    
    default:
        show_error_line("An UNDEFINED_ERROR error occured.", UNDEFINED_ERROR, file, function, line);
        break;
    }
}