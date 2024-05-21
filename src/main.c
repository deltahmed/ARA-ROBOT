
#include "ARA_def.h"
#include "map.h"
#include "ARA_window.h"
#include "game.h"
#include "ARA_menu.h"
#include "ARA_file.h"
#include "ARA_events.h"

//88 33

//22 

/**
 * @brief The main fuction with the main game loop.
 * 
 * @return int 
 */
int main(){
    Game game;
    int r=0,choice=0;
    do{
    Game_init(&game);
    
    do{
        choice=choice_menu(&game);
        if(choice==EXIT){
            return 0;
        }
    }while(choice==CREDIT);//choice est egal a 4 si l utilisateur clique sur Credit puis sur la touche m pour revenir au menu

    game.window.destroy();
    //Pour supprimer le one_win_mode
    while(true) {
        game.window.clear_all(&game.window);

        game.window.create(&game.window);

        wtimeout(game.window.main_window,500);
        //wtimeout doit toujours etre apres game.window.create parceque avant elle sera pas deja creee

        cprintf(game.window.top, 1, 1, BASE_CRS_COLOR_BRIGHT_RED, "Ceci est la fenetre du haut %d %d %d", COLS, LINES, game.window.get_key(&game.window));

        //cprint(game.window.bottom, 1, 1, BASE_CRS_COLOR_BRIGHT_RED, "Ceci est la fenetre du bas");
        keys(game);
        
        game.timer.update(&game.timer);
        cprintf(game.window.bottom, 2, 6, BASE_CRS_COLOR_BRIGHT_RED, "Temps : %ld",game.timer.get(&game.timer));
        //On pourrait faire une fonction qui printf tout ce qui est dans la window bottom(keys,time.....)
        
        print_map(&game);
        print_right_window(&game);
        if(game.map.get(&game.map,game.player.get_x(&game.player),game.player.get_y(&game.player))==MAP_TASK){
            task(&game);
        }
        if(game.map.get(&game.map,game.player.get_x(&game.player),game.player.get_y(&game.player))==MAP_HEATH_CHARGE){
            object_effect(&game, game.player.get_x(&game.player), game.player.get_y(&game.player));
        }
        print_right_window(&game);
        //Je la mets avant mouvement comme ca elle reste tant que j ai pas bouge
        game.window.update_key(&game.window);
        player_movement(&game);
        if(game.map.get(&game.map,game.player.get_x(&game.player),game.player.get_y(&game.player))==MAP_MONSTER && QTE(&game)==0){
            break;
            //Parce que quand on sort de la boucle ca veut dire qu on a perdu car on a pas encore de condition de win
            //Et on supprime deja la window et la map dans la focntion QTE en cas de defaite 
        }
        //Je la mets apres mouvement pour eviter que le jeu s enregistre apres une defaite au QTE
        r++;
        if(r%50==0){
            saveGame(&game);
            //Chaque 50 mouvements ca enregistre
        }
        game.window.update(&game.window);
    }
    gameEnd(game);
    }while(true);
    saveGame(&game);
    game.window.destroy();
    game.map.destroy(&game.map);
    
    
    return 0;
}

