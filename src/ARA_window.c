
#include "ARA_window.h"

static void __show_cursor(ARA_Window* self){
    self->__cursor = !self->__cursor;
    curs_set(self->__cursor);
}


static void __ARA_box(ARA_Window* self){
    if (self->__one_win_mode){
        ARA_error(WINDOWS_DO_NOT_EXIST);
    }
    box(self->top, ACS_VLINE, ACS_HLINE);
    box(self->bottom , ACS_VLINE, ACS_HLINE);
    box(self->right, ACS_VLINE, ACS_HLINE);
}

static void __one_window_mode(ARA_Window* self){
    self->__one_win_mode = 1;
    self->main_window = newwin(NB_LINES,NB_COLS,0,0);
    self->top = NULL;  
    self->bottom = NULL;  
    self->right = NULL;  
}

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
        __ARA_box(self);
    }
    

}

static void __refresh_all(ARA_Window* self){
    if (!self->__one_win_mode){
        wrefresh(self->top);  
        wrefresh(self->bottom);
        wrefresh(self->right);
    }
    wrefresh(self->main_window);
}
static void __refresh(ARA_Window* self, ARA_Window_choice choice_window){
    switch (choice_window)
    {
    case W_TOP:
        if (self->__one_win_mode){
            ARA_error(WINDOWS_DO_NOT_EXIST);
        }
        wrefresh(self->top);  
        break;
    case W_BOTTOM:
        if (self->__one_win_mode){
            ARA_error(WINDOWS_DO_NOT_EXIST);
        }
        wrefresh(self->bottom);  
        break;
    case W_RIGHT:
        if (self->__one_win_mode){
            ARA_error(WINDOWS_DO_NOT_EXIST);
        }
        wrefresh(self->right);  
        break; 
    case W_MAIN:
    default:
        break;
    }
    wrefresh(self->main_window);
}

static void __update_key(ARA_Window* self){
    self->__key = (Key)wgetch(self->main_window);
}

static Key __get_key(ARA_Window* self){
    return self->__key;
}

static void __update_all(ARA_Window* self){
    __refresh_all(self);
    __update_key(self);

}

static void __clear_all(ARA_Window* self){
    if (!self->__one_win_mode){
        wclear(self->top);  
        wclear(self->bottom);
        wclear(self->right);
    }
    wclear(self->main_window);
}
static void __clear(ARA_Window* self, ARA_Window_choice choice_window){
    switch (choice_window)
    {
    case W_TOP:
        if (self->__one_win_mode){
            ARA_error(WINDOWS_DO_NOT_EXIST);
        }
        wclear(self->top);  
        break;
    case W_BOTTOM:
        if (self->__one_win_mode){
            ARA_error(WINDOWS_DO_NOT_EXIST);
        }
        wclear(self->bottom);  
        break;
    case W_RIGHT:
        if (self->__one_win_mode){
            ARA_error(WINDOWS_DO_NOT_EXIST);
        }
        wclear(self->right);  
        break; 
    case W_MAIN:
    default:
        break;
    }
    wclear(self->main_window);
}

static void __end_curses(){
    curs_set(1);
    endwin();
}

void ARA_Window_init(ARA_Window* self, ARA_Window_mode mode){
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    if (mode){
        __one_window_mode(self);
    } else {
        __create_windows(self);
    }
    __refresh_all(self);
    self->__key = 0;
    self->__cursor = 1;
    __show_cursor(self);

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
