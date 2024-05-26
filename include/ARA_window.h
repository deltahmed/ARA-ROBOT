/**
 * @file ARA_window.h
 * @author Ahmed A., Rayane M., Abdelwaheb A.
 * @brief ncursesw handling header
 * @version 1.0
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#define _XOPEN_SOURCE_EXTENDED 1
#define _XOPEN_SOURCE 700

#include <ncursesw/ncurses.h>

#ifndef ARA_WINDOW_H
#define ARA_WINDOW_H

#include "ARA_def.h"

/**
 * @brief Prints a string with a specified color attribute at a given position in a window (mvwprintw).
 *
 * This macro sets the specified color attribute, prints the string at the 
 * specified position in the given window, and then turns off the color attribute.
 *
 * @param win The window where the string is printed.
 * @param x The x coordinate of the string.
 * @param y The y coordinate of the string .
 * @param attribute The color attribute to use (COLOR_PAIR).
 * @param str The string to print.
 */
#define cprint(win,x,y,attribute,str) (wattron(win, COLOR_PAIR(attribute)), mvwprintw(win, y, x, str), wattroff(win, COLOR_PAIR(attribute)))

/**
 * @brief Prints a string with a specified color attribute at a given position in a window (mvwaddstr).
 *
 * This macro sets the specified color attribute, prints the string at the 
 * specified position in the given window, and then turns off the color attribute.
 *
 * @param win The window where the string is printed.
 * @param x The x coordinate of the string.
 * @param y The y coordinate of the string .
 * @param attribute The color attribute to use (COLOR_PAIR).
 * @param str The string to print.
 */
#define cprintadd(win,x,y,attribute,str) (wattron(win, COLOR_PAIR(attribute)), mvwaddstr(win, y, x, str), wattroff(win, COLOR_PAIR(attribute)))

/**
 * @brief Prints a formatted string with a specified color attribute at a given position in a window.
 *
 * This macro sets the specified color attribute, prints the formatted string 
 * at the specified position in the given window, and then turns off the color attribute.
 * 
 * CAUTION : DO NOT USE A NON FORMATTED STR WITH THIS MACRO USE cprint INSTEAD.
 *
 * @param win The window where the formatted string is printed.
 * @param x The x coordinate of the string.
 * @param y The y coordinate of the string.
 * @param attribute The color attribute to use (COLOR_PAIR).
 * @param format_str The formatted string to print.
 * @param ... Additional arguments for the formatted string.
 */
#define cprintf(win,x,y,attribute,format_str,...) (wattron(win, COLOR_PAIR(attribute)), mvwprintw(win, y, x, format_str, __VA_ARGS__), wattroff(win, COLOR_PAIR(attribute)))


#define NB_LINES 33
#define NB_COLS 88

#define GAME_SCREEN_X 56
#define GAME_SCREEN_Y 20

typedef int Key;
typedef int boolean;

/**
 * @brief Enumeration for the different window modes.
 */
typedef enum  __ARA_Window_Mode_enum {
    W_MODE_MULTIPLE,
    W_MODE_ONE,
}ARA_Window_mode;

/**
 * @brief This enumeration defines the possible window selections
 */
typedef enum  __ARA_Window_choice_enum {
    W_MAIN,
    W_TOP,
    W_BOTTOM,
    W_RIGHT,
}ARA_Window_choice;

/**
 * @brief Structure representing a window its properties and methods.
 */
typedef struct __ARA_Window_struct {
    WINDOW* main_window;   /**< The main window. */

    WINDOW* top;           /**< The top sub-window. */
    WINDOW* bottom;        /**< The bottom sub-window. */
    WINDOW* right;         /**< The right sub-window. */

    boolean __one_win_mode; 
    Key __key;              
    boolean __cursor;       

    /**
     * @brief Draws boxes around all windows.
     * 
     * @param self Pointer to the ARA_Window structure.
     * @throw WINDOWS_DO_NOT_EXIST_ERROR if its in ONE_WINDOW_MODE.
     */
    void (*box_all)(struct __ARA_Window_struct* self);

    /**
     * @brief Creates all windows.
     * 
     * @param self Pointer to self.
     */
    void (*create)(struct __ARA_Window_struct* self);

    /**
     * @brief Creates a single window.
     * 
     * @param self Pointer to self.
     */
    void (*create_one_win_mode)(struct __ARA_Window_struct* self);

    /**
     * @brief Refreshes all windows.
     * 
     * @param self Pointer to self.
     */
    void (*refresh_all)(struct __ARA_Window_struct* self);

    /**
     * @brief Refreshes a specific window.
     * 
     * @param self Pointer to self.
     * @param choice_window The window to refresh.
     * @throw WINDOWS_DO_NOT_EXIST_ERROR if the window choosed do not exit.
     */
    void (*refresh_win)(struct __ARA_Window_struct* self, ARA_Window_choice choice_window);

    /**
     * @brief Clears all windows.
     * 
     * @param self Pointer to self.
     */
    void (*clear_all)(struct __ARA_Window_struct* self);

    /**
     * @brief Clears a specific window.
     * 
     * @param self Pointer to self.
     * @param choice_window The window to clear.
     * @throw WINDOWS_DO_NOT_EXIST_ERROR if the window choosed do not exit.
     */
    void (*clear_win)(struct __ARA_Window_struct* self, ARA_Window_choice choice_window);

    /**
     * @brief Updates the current key.
     * 
     * @param self Pointer to self.
     */
    void (*update_key)(struct __ARA_Window_struct* self);

    /**
     * @brief Gets the current key.
     * 
     * @param self Pointer to self.
     * @return The current key.
     */
    Key (*get_key)(struct __ARA_Window_struct* self);

    /**
     * @brief Updates the window state.
     * 
     * @param self Pointer to self.
     */
    void (*update)(struct __ARA_Window_struct* self);

    /**
     * @brief flip the cursor show state.
     * 
     * @param self Pointer to self.
     */
    void (*show_cursor)(struct __ARA_Window_struct* self);

    /**
     * @brief end curses.
     */
    void (*destroy)();
} ARA_Window;
void ARA_Window_init(ARA_Window* self, ARA_Window_mode mode);

#endif