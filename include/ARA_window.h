#define _XOPEN_SOURCE_EXTENDED 1

#include <ncursesw/ncurses.h>

#ifndef ARA_WINDOW_H
#define ARA_WINDOW_H

#include "ARA_def.h"

#define cprint(win,x,y,attribute,format_str,...) (wattron(win, COLOR_PAIR(attribute)), mvwprintw(win, x, y, format_str, __VA_ARGS__), wattroff(win, COLOR_PAIR(attribute)))

#define NB_LINES 33
#define NB_COLS 88

typedef int Key;
typedef char boolean;

typedef enum  __ARA_Window_Mode_enum {
    W_MODE_MULTIPLE,
    W_MODE_ONE,
}ARA_Window_mode;

typedef enum  __ARA_Window_choice_enum {
    W_MAIN,
    W_TOP,
    W_BOTTOM,
    W_RIGHT,
}ARA_Window_choice;

typedef struct __ARA_Window_struct
{
    WINDOW* main_window;

    WINDOW* top;
    WINDOW* bottom;
    WINDOW* right;

    boolean __one_win_mode;
    Key __key;
    boolean __cursor;

    void (*box_all)(struct __ARA_Window_struct* self);
    void (*create)(struct __ARA_Window_struct* self);
    void (*create_one_win_mode)(struct __ARA_Window_struct* self);
    void (*refresh_all)(struct __ARA_Window_struct* self);
    void (*refresh_win)(struct __ARA_Window_struct* self, ARA_Window_choice choice_window);
    void (*clear_all)(struct __ARA_Window_struct* self);
    void (*clear_win)(struct __ARA_Window_struct* self, ARA_Window_choice choice_window);
    void (*update_key)(struct __ARA_Window_struct* self);
    Key (*get_key)(struct __ARA_Window_struct* self);
    void (*update)(struct __ARA_Window_struct* self);
    void (*show_cursor)(struct __ARA_Window_struct* self);
    void (*destroy)();


    
}ARA_Window;

void ARA_Window_init(ARA_Window* self, ARA_Window_mode mode);

#endif