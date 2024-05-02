
#include "ARA_def.h"
#include "map.h"
#include "ARA_window.h"


//88 33
int main(){



    ARA_Window window;
    ARA_Window_init(&window, W_MODE_MULTIPLE);

    while(TRUE) {
        window.clear_all(&window);
        window.create(&window);

        cprint(window.top, 1, 1, COLOR_MUR, "Ceci est la fenetre du haut %d %d", COLS, LINES);

        wattron(window.bottom, COLOR_PAIR(COLOR_MUR2));
        mvwprintw(window.bottom, 1, 1, "Ceci est la fenetre du bas");
        wattroff(window.bottom, COLOR_PAIR(COLOR_MUR2));


        mvwprintw(window.bottom, 2, 1, "Ceci est la fenetre du bas");
            
        window.update(&window);
    }

    
    window.destroy();

    return 0;
}

