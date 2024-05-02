
#include "ARA_def.h"
#include "map.h"
#include "ARA_window.h"



//88 33

//22 58
int main(){


    ARA_Window window;
    ARA_Window_init(&window, W_MODE_MULTIPLE);

    while(TRUE) {
        window.clear_all(&window);
        window.create(&window);

        cprintf(window.top, 1, 1, COLOR_MUR, "Ceci est la fenetre du haut %d %d %d", COLS, LINES, 2000);

        cprint(window.bottom, 1, 1, COLOR_MUR2, "Ceci est la fenetre du bas");

        
            
        window.update(&window);
    }

    
    window.destroy();

    return 0;
}

