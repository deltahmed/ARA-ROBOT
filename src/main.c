
#include "ARA_def.h"
#include "map.h"
#include "ARA_screen.h"
//88 33
int main(){
    setlocale(LC_ALL, "");

    WINDOW *top_win, *bottom_win, *right_win, *main_win;
    
    initscr();
    
    int key;
    while(1) {
        clear();    // Efface la fenêtre (donc l'ancien message)
        if (LINES<NB_LINES || COLS<NB_COLS ){
            main_win = newwin(NB_LINES,NB_COLS,0,0);
            mvwprintw(main_win, 1, 1, "The Windows is too small");
            mvwprintw(main_win, 2, 1, "Minimum : %d lines %d columns",NB_LINES,NB_COLS);
            mvwprintw(main_win, 3, 1, "Actual : %d lines %d columns",LINES, COLS);
        } else {
            main_win = newwin(NB_LINES,NB_COLS,0,0);
            top_win = subwin(main_win, (NB_LINES / 3)*2, (NB_COLS/3)*2, 0, 0);        // Créé une fenêtre de 'LINES / 2' lignes et de COLS colonnes en 0, 0
            bottom_win = subwin(main_win, NB_LINES / 3, (NB_COLS/3)*2, (NB_LINES / 3)*2, 0); // Créé la même fenêtre que ci-dessus sauf que les coordonnées changent
            right_win = subwin(main_win, 0, NB_COLS/3, 0, (NB_COLS/3)*2);
            mvwprintw(main_win, 1, 1, "%d %d %d %d",LINES, COLS, (LINES-NB_LINES)/2,(COLS-NB_COLS)/2);
            box(top_win, ACS_VLINE, ACS_HLINE);
            box(bottom_win, ACS_VLINE, ACS_HLINE);
            box(right_win, ACS_VLINE, ACS_HLINE);
        

            mvwprintw(top_win, 1, 1, "Ceci est la fenetre du haut %d %d", COLS, LINES);
            mvwprintw(bottom_win, 1, 1, "Ceci est la fenetre du bas");
            
            wrefresh(top_win);
            wrefresh(bottom_win);
            wrefresh(right_win);  
        }
        wrefresh(main_win);
        key = wgetch(main_win);
        refresh();
        if(key != 410)
            break;
    }

    
    endwin();

    return 0;
}
