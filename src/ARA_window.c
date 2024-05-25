
#include "ARA_window.h"

/**
 * @brief flip the cursor show state.
 * 
 * @param self Pointer to self.
 */
static void __show_cursor(ARA_Window* self){
    self->__cursor = !self->__cursor;
    curs_set(self->__cursor);
}

/**
 * @brief Draws boxes around all windows.
 * 
 * @param self Pointer to the ARA_Window structure.
 * @throw WINDOWS_DO_NOT_EXIST_ERROR if its in ONE_WINDOW_MODE.
 */
static void __ARA_box(ARA_Window* self){
    if (self->__one_win_mode){
        ARA_error(WINDOWS_DO_NOT_EXIST_ERROR);
    }
    box(self->top, ACS_VLINE, ACS_HLINE);
    box(self->bottom , ACS_VLINE, ACS_HLINE);
    box(self->right, ACS_VLINE, ACS_HLINE);
}

/**
 * @brief Creates a single window.
 * 
 * @param self Pointer to self.
 */
static void __one_window_mode(ARA_Window* self){
    self->__one_win_mode = 1;
    self->main_window = newwin(NB_LINES,NB_COLS,0,0);
    box(self->main_window, ACS_VLINE, ACS_HLINE);
    self->top = NULL;  
    self->bottom = NULL;  
    self->right = NULL;  
    keypad(self->main_window, true);
}

/**
 * @brief Creates all windows.
 * 
 * @param self Pointer to self.
 */
static void __create_windows(ARA_Window* self){
    if (LINES<NB_LINES || COLS<NB_COLS ){
        __one_window_mode(self);
        mvwprintw(self->main_window, 1, 1, "The Windows is too small");
        mvwprintw(self->main_window, 2, 1, "Minimum : %d lines %d columns",NB_LINES,NB_COLS);
        mvwprintw(self->main_window, 3, 1, "Actual : %d lines %d columns",LINES, COLS);
    } else {
        self->__one_win_mode = 0;
        self->main_window = newwin(NB_LINES,NB_COLS,0,0);
        self->top = subwin(self->main_window, (NB_LINES / 3)*2, (NB_COLS/3)*2, 0, 0);  
        self->bottom = subwin(self->main_window, NB_LINES / 3, (NB_COLS/3)*2, (NB_LINES / 3)*2, 0);
        self->right = subwin(self->main_window, 0, NB_COLS/3, 0, (NB_COLS/3)*2);
        keypad(self->top, true);
        keypad(self->bottom, true);
        keypad(self->right, true);
        __ARA_box(self);
    }
    keypad(self->main_window, true);

}
/**
 * @brief Refreshes all windows.
 * 
 * @param self Pointer to self.
 */
static void __refresh_all(ARA_Window* self){
    if (!self->__one_win_mode){
        wrefresh(self->top);  
        wrefresh(self->bottom);
        wrefresh(self->right);
    }
    wrefresh(self->main_window);
}

/**
 * @brief Refreshes a specific window.
 * 
 * @param self Pointer to self.
 * @param choice_window The window to refresh.
 * @throw WINDOWS_DO_NOT_EXIST_ERROR if the window choosed do not exit.
 */
static void __refresh(ARA_Window* self, ARA_Window_choice choice_window){
    switch (choice_window)
    {
    case W_TOP:
        if (self->__one_win_mode){
            ARA_error(WINDOWS_DO_NOT_EXIST_ERROR);
        }
        wrefresh(self->top);  
        break;
    case W_BOTTOM:
        if (self->__one_win_mode){
            ARA_error(WINDOWS_DO_NOT_EXIST_ERROR);
        }
        wrefresh(self->bottom);  
        break;
    case W_RIGHT:
        if (self->__one_win_mode){
            ARA_error(WINDOWS_DO_NOT_EXIST_ERROR);
        }
        wrefresh(self->right);  
        break; 
    case W_MAIN:
    default:
        break;
    }
    wrefresh(self->main_window);
}

/**
 * @brief Updates the current key.
 * 
 * @param self Pointer to self.
 */
static void __update_key(ARA_Window* self){
    self->__key = (Key)wgetch(self->main_window);
}

/**
 * @brief Gets the current key.
 * 
 * @param self Pointer to self.
 * @return The current key.
 */
static Key __get_key(ARA_Window* self){
    return self->__key;
}

/**
 * @brief Updates the window state.
 * 
 * @param self Pointer to self.
 */
static void __update_all(ARA_Window* self){
    __refresh_all(self);

}

/**
 * @brief Clears all windows.
 * 
 * @param self Pointer to self.
 */
static void __clear_all(ARA_Window* self){
    if (!self->__one_win_mode){
        wclear(self->top);  
        wclear(self->bottom);
        wclear(self->right);
    }
    wclear(self->main_window);
}

/**
 * @brief Clears a specific window.
 * 
 * @param self Pointer to self.
 * @param choice_window The window to clear.
 * @throw WINDOWS_DO_NOT_EXIST_ERROR if the window choosed do not exit.
*/
static void __clear(ARA_Window* self, ARA_Window_choice choice_window){
    switch (choice_window)
    {
    case W_TOP:
        if (self->__one_win_mode){
            ARA_error(WINDOWS_DO_NOT_EXIST_ERROR);
        }
        wclear(self->top);  
        break;
    case W_BOTTOM:
        if (self->__one_win_mode){
            ARA_error(WINDOWS_DO_NOT_EXIST_ERROR);
        }
        wclear(self->bottom);  
        break;
    case W_RIGHT:
        if (self->__one_win_mode){
            ARA_error(WINDOWS_DO_NOT_EXIST_ERROR);
        }
        wclear(self->right);  
        break; 
    case W_MAIN:
    default:
        break;
    }
    wclear(self->main_window);
}

/**
 * @brief end curses.
 */
static void __end_curses(){
    endwin();
}

/**
 * @brief Initializes color pairs for ncurses.
 *
 * This function initializes color pairs for use in the ncurses interface.
 * @throw raises an NOCOLOR_ERROR if the terminal does not support color.
 */
static void __color_init(){
    if (!has_colors()) {
        ARA_error(NOCOLOR_ERROR);
    }
    start_color();
    init_color(CRS_COLOR_BRIGHT_RED, 900, 257, 257);
    init_pair(BASE_CRS_COLOR_BRIGHT_RED, CRS_COLOR_RED, CRS_COLOR_BLACK);


    init_pair(BASE_CRS_COLOR_BLACK, CRS_COLOR_BLACK, CRS_COLOR_BLACK);
    init_pair(BASE_CRS_COLOR_RED, CRS_COLOR_RED, CRS_COLOR_BLACK);
    init_pair(BASE_CRS_COLOR_GREEN, CRS_COLOR_GREEN, CRS_COLOR_BLACK);
    init_pair(BASE_CRS_COLOR_YELLOW, CRS_COLOR_YELLOW, CRS_COLOR_BLACK);
    init_pair(BASE_CRS_COLOR_BLUE, CRS_COLOR_BLUE, CRS_COLOR_BLACK);
    init_pair(BASE_CRS_COLOR_MAGENTA, CRS_COLOR_MAGENTA, CRS_COLOR_BLACK);
    init_pair(BASE_CRS_COLOR_CYAN, CRS_COLOR_CYAN, CRS_COLOR_BLACK);
    init_pair(BASE_CRS_COLOR_WHITE, CRS_COLOR_WHITE, CRS_COLOR_BLACK);

    // Initialisation de la couleur CRS_COLOR_BRIGHT_BLACK
    init_color(CRS_COLOR_BRIGHT_BLACK, 500, 500, 500);
    init_pair(BASE_CRS_COLOR_BRIGHT_BLACK, CRS_COLOR_BRIGHT_BLACK, CRS_COLOR_BLACK);

    // Initialisation de la couleur CRS_COLOR_BRIGHT_RED
    init_color(CRS_COLOR_BRIGHT_RED, 900, 257, 257);
    init_pair(BASE_CRS_COLOR_BRIGHT_RED, CRS_COLOR_BRIGHT_RED, CRS_COLOR_BLACK);

    // Initialisation de la couleur CRS_COLOR_BRIGHT_GREEN
    init_color(CRS_COLOR_BRIGHT_GREEN, 411, 1000, 431);
    init_pair(BASE_CRS_COLOR_BRIGHT_GREEN, CRS_COLOR_BRIGHT_GREEN, CRS_COLOR_BLACK);

    // Initialisation de la couleur CRS_COLOR_BRIGHT_YELLOW
    init_color(CRS_COLOR_BRIGHT_YELLOW, 960, 1000, 411);
    init_pair(BASE_CRS_COLOR_BRIGHT_YELLOW, CRS_COLOR_BRIGHT_YELLOW, CRS_COLOR_BLACK);

    // Initialisation de la couleur CRS_COLOR_BRIGHT_BLUE
    init_color(CRS_COLOR_BRIGHT_BLUE, 235, 321, 980);
    init_pair(BASE_CRS_COLOR_BRIGHT_BLUE, CRS_COLOR_BRIGHT_BLUE, CRS_COLOR_BLACK);

    // Initialisation de la couleur CRS_COLOR_BRIGHT_MAGENTA
    init_color(CRS_COLOR_BRIGHT_MAGENTA, 721, 321, 968);
    init_pair(BASE_CRS_COLOR_BRIGHT_MAGENTA, CRS_COLOR_BRIGHT_MAGENTA, CRS_COLOR_BLACK);

    // Initialisation de la couleur CRS_COLOR_BRIGHT_CYAN
    init_color(CRS_COLOR_BRIGHT_CYAN, 466, 827, 968);
    init_pair(BASE_CRS_COLOR_BRIGHT_CYAN, CRS_COLOR_BRIGHT_CYAN, CRS_COLOR_BLACK);

    init_pair(FONT_CRS_COLOR_BRIGHT_RED, CRS_COLOR_WHITE, CRS_COLOR_BRIGHT_RED);
    init_pair(FONT_CRS_COLOR_BRIGHT_GREEN, CRS_COLOR_WHITE, CRS_COLOR_BRIGHT_GREEN);
    init_pair(FONT_CRS_COLOR_BRIGHT_YELLOW, CRS_COLOR_WHITE, CRS_COLOR_BRIGHT_YELLOW);
    init_pair(FONT_CRS_COLOR_GREEN, CRS_COLOR_WHITE, CRS_COLOR_GREEN);

    init_pair(SPECIAL_CRS_COLOR_RED_YELLOW, CRS_COLOR_BRIGHT_RED, CRS_COLOR_BRIGHT_YELLOW);

}
/**
 * @brief Initializes the Window structure.
 *
 * @param self Pointer to self.
 */
void ARA_Window_init(ARA_Window* self, ARA_Window_mode mode){
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();
    self->__key = 0;
    self->__cursor = 0;
    curs_set(self->__cursor);
    if (mode){
        __one_window_mode(self);
        
    } else {
        __create_windows(self);
    }


    __color_init(self);
    __refresh_all(self);
    self->box_all = __ARA_box;
    self->create = __create_windows;
    self->get_key = __get_key;
    self->refresh_all = __refresh_all;
    self->refresh_win = __refresh;
    self->update = __update_all;
    self->update_key = __update_key;
    self->show_cursor = __show_cursor;
    self->create_one_win_mode = __one_window_mode;
    self->clear_all = __clear_all;
    self->clear_win = __clear;
    self->destroy = __end_curses;
}
