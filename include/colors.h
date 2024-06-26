/**
 * @file colors.h
 * @author Ahmed A., Rayane M., Abdelwaheb A.
 * @brief Colors handling header
 * @version 1.0
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef ARA_COLOR_H
#define ARA_COLOR_H

#include "ARA_def.h"
#include "ARA_window.h"

// ========================== terminal color ===============================

/**
 * @brief terminal colors.
 * 
 */

#define ARA_COLOR_RESET "\033[0m"

#define ARA_STYLE_BOLD "\033[1m"
#define ARA_STYLE_DIM "\033[2m"
#define ARA_STYLE_UNDERLINED "\033[4m"
#define ARA_STYLE_BLINK "\033[5m"
#define ARA_STYLE_REVERSE "\033[7m"
#define ARA_STYLE_HIDDEN "\033[8m"

#define ARA_COLOR_BLACK "\033[30m"
#define ARA_COLOR_RED "\033[31m"
#define ARA_COLOR_GREEN "\033[32m"
#define ARA_COLOR_YELLOW "\033[33m"
#define ARA_COLOR_BLUE "\033[34m"
#define ARA_COLOR_MAGENTA "\033[35m"
#define ARA_COLOR_CYAN "\033[36m"
#define ARA_COLOR_WHITE "\033[37m"
#define ARA_COLOR_BRIGHT_BLACK "\033[90m"
#define ARA_COLOR_BRIGHT_RED "\033[91m"
#define ARA_COLOR_BRIGHT_GREEN "\033[92m"
#define ARA_COLOR_BRIGHT_YELLOW "\033[93m"
#define ARA_COLOR_BRIGHT_BLUE "\033[94m"
#define ARA_COLOR_BRIGHT_MAGENTA "\033[95m"
#define ARA_COLOR_BRIGHT_CYAN "\033[96m"
#define ARA_COLOR_BRIGHT_WHITE "\033[97m"

#define ARA_BG_BLACK "\033[40m"
#define ARA_BG_RED "\033[41m"
#define ARA_BG_GREEN "\033[42m"
#define ARA_BG_YELLOW "\033[43m"
#define ARA_BG_BLUE "\033[44m"
#define ARA_BG_MAGENTA "\033[45m"
#define ARA_BG_CYAN "\033[46m"
#define ARA_BG_WHITE "\033[47m"
#define ARA_BG_BRIGHT_BLACK "\033[100m"
#define ARA_BG_BRIGHT_RED "\033[101m"
#define ARA_BG_BRIGHT_GREEN "\033[102m"
#define ARA_BG_BRIGHT_YELLOW "\033[103m"
#define ARA_BG_BRIGHT_BLUE "\033[104m"
#define ARA_BG_BRIGHT_MAGENTA "\033[105m"
#define ARA_BG_BRIGHT_CYAN "\033[106m"
#define ARA_BG_BRIGHT_WHITE "\033[107m"

// ========================== Curses colors ===============================


/**
 * @brief curses colors.
 * 
 */

#define CRS_COLOR_BLACK 0
#define CRS_COLOR_RED 1
#define CRS_COLOR_GREEN 2
#define CRS_COLOR_YELLOW 3
#define CRS_COLOR_BLUE 4
#define CRS_COLOR_MAGENTA 5
#define CRS_COLOR_CYAN 6
#define CRS_COLOR_WHITE 7
#define CRS_COLOR_BRIGHT_BLACK 8
#define CRS_COLOR_BRIGHT_RED 9
#define CRS_COLOR_BRIGHT_GREEN 10
#define CRS_COLOR_BRIGHT_YELLOW 11
#define CRS_COLOR_BRIGHT_BLUE 12
#define CRS_COLOR_BRIGHT_MAGENTA 13
#define CRS_COLOR_BRIGHT_CYAN 14

// ========================== Curses color pairs ===============================

/**
 * @brief curses color pairs.
 * 
 */

#define BASE_CRS_COLOR_BLACK 0
#define BASE_CRS_COLOR_RED 1
#define BASE_CRS_COLOR_GREEN 2
#define BASE_CRS_COLOR_YELLOW 3
#define BASE_CRS_COLOR_BLUE 4
#define BASE_CRS_COLOR_MAGENTA 5
#define BASE_CRS_COLOR_CYAN 6
#define BASE_CRS_COLOR_WHITE 7
#define BASE_CRS_COLOR_BRIGHT_BLACK 8
#define BASE_CRS_COLOR_BRIGHT_RED 9
#define BASE_CRS_COLOR_BRIGHT_GREEN 10
#define BASE_CRS_COLOR_BRIGHT_YELLOW 11
#define BASE_CRS_COLOR_BRIGHT_BLUE 12
#define BASE_CRS_COLOR_BRIGHT_MAGENTA 13
#define BASE_CRS_COLOR_BRIGHT_CYAN 14

#define FONT_CRS_COLOR_BRIGHT_RED 15
#define FONT_CRS_COLOR_BRIGHT_GREEN 16
#define FONT_CRS_COLOR_BRIGHT_YELLOW 17
#define FONT_CRS_COLOR_GREEN 19

#define SPECIAL_CRS_COLOR_RED_YELLOW 18


#endif /* ARA_COLOR_H */
