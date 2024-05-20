#include "ARA_error.h"
#include "colors.h"

/**
 * @brief Displays an error message and exits the program.
 *
 * This function terminates the ncurses mode, displays an error message on the 
 * standard error output with colored formatting, and exits the program with the 
 * specified error type.
 *
 * @param message The error message to display.
 * @param type The error type (enum Error) which is used as the exit code.
 */
void show_error(char * message, Error type){
    endwin();
    fprintf(stderr,"\n%s%s%s ARA error no : %s%d%s \n\n", ARA_COLOR_BRIGHT_MAGENTA, message, ARA_COLOR_RESET, ARA_COLOR_BRIGHT_RED, type, ARA_COLOR_RESET); 
    exit(type);
}

/**
 * @brief Displays an error message with file, function, and line information, then exits the program.
 *
 * This function terminates the ncurses mode, displays an error message on the 
 * standard error output with colored formatting, including the file name, function name, 
 * and line number where the error occurred, and exits the program with the specified error type .
 *
 * @param message The error message to display.
 * @param type The error type (enum Error) which is used as the exit code.
 * @param file The name of the file where the error occurred.
 * @param function The name of the function where the error occurred.
 * @param line The line number where the error occurred.
 */
void show_error_line(char * message, Error type, const char * file, const char * function, int line){
    endwin();
    fprintf(stderr,"\n%s%s%s ARA error no : %s%d%s\n", ARA_COLOR_BRIGHT_MAGENTA, message, ARA_COLOR_RESET, ARA_COLOR_BRIGHT_RED, type, ARA_COLOR_RESET);
    fprintf(stderr,"Occurred in file : `%s%s%s`, in function : `%s%s%s`, in line : %s%d%s \n\n", ARA_COLOR_BRIGHT_RED, file, ARA_COLOR_RESET, ARA_COLOR_BRIGHT_RED, function, ARA_COLOR_RESET, ARA_COLOR_BRIGHT_RED, line, ARA_COLOR_RESET ); 

    exit(type);
}


/**
 * @brief Handles the various error types and displays the appropriate error messages.
 *
 * This function checks the error type and calls the appropriate error display function 
 * with a specific message, including the file, function, and line number if necessary.
 *
 * @param type The error type (enum Error) which determines the error message.
 * @param file The name of the file where the error occurred.
 * @param function The name of the function where the error occurred.
 * @param line The line number where the error occurred.
 */
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