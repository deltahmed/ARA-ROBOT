
#include "ARA_def.h"
#include "map.h"
#include "ARA_window.h"
#include "game.h"



//88 33

//22 58
int main(){

    Game game;
    Game_init(&game);
    generatemap(&game.map);
    while(TRUE) {

        game.window.clear_all(&game.window);

        game.window.create(&game.window);

        cprintf(game.window.top, 1, 1, COLOR_MUR, "Ceci est la fenetre du haut %d %d %d", COLS, LINES, 2000);

        cprint(game.window.bottom, 1, 1, COLOR_MUR2, "Ceci est la fenetre du bas");

        
        printmap(&game);
        game.window.get_key(&game.window);
        __movement(&game);

        
            
        game.window.update(&game.window);
    }

    
    game.window.destroy();

    return 0;
}

