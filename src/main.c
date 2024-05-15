
#include "ARA_def.h"
#include "map.h"
#include "ARA_window.h"
#include "game.h"
#include "menu.h"
#include "file.h"

//88 33

//22 58
int main(){
    Game game;
    int r=0;
    Game_init(&game);
    
    if(menuChoice(&game)==0){
        game.window.destroy();
        game.map.destroy(&game.map);
        return 0;
    }
    game.window.destroy();
    while(TRUE) {
        game.window.clear_all(&game.window);

        game.window.create(&game.window);

        wtimeout(game.window.main_window,500);

        cprintf(game.window.top, 1, 1, COLOR_MUR, "Ceci est la fenetre du haut %d %d %d", COLS, LINES, game.window.get_key(&game.window));

        cprint(game.window.bottom, 1, 1, COLOR_MUR2, "Ceci est la fenetre du bas");
        
        game.timer.update(&game.timer);
        cprintf(game.window.bottom, 2, 2, COLOR_MUR2, "%ld",game.timer.get(&game.timer));

        
        printmap(&game);
        game.window.update_key(&game.window);
        __movement(&game);
        r++;
        if(r>100){break;}
        game.window.update(&game.window);
    }
    saveGame(&game);
    game.window.destroy();
    game.map.destroy(&game.map);
    
    
    return 0;
}

