
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
    struct timespec current;
    long actual=0,final=0;
    int compteur=0;
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
        re_print_all(&game,400);
        //cprintf(game.window.top, 1, 1, BASE_CRS_COLOR_BRIGHT_RED, "Ceci est la fenetre du haut %d %d %d", COLS, LINES, game.window.get_key(&game.window));
        if(game.map.get(&game.map,game.player.get_x(&game.player),game.player.get_y(&game.player))==MAP_TASK){
            task_choose(&game);
            game.map.set(&game.map,game.player.get_x(&game.player),game.player.get_y(&game.player),MAP_ROOM);
        }
        if(game.map.get(&game.map,game.player.get_x(&game.player),game.player.get_y(&game.player))==MAP_HEATH_CHARGE){
            object_effect(&game, game.player.get_x(&game.player), game.player.get_y(&game.player));
        }

        compteur+=final-actual;
        if(compteur<0){
            compteur=0;
        }
        if(compteur>400){
            compteur=compteur%400;
            monster(&game);
        }
        clock_gettime(CLOCK_REALTIME,&current);
        actual=current.tv_sec*1000+current.tv_nsec/1000000;
        game.window.update_key(&game.window);

        if(player_movement(&game)==0){
            break;
        }

        clock_gettime(CLOCK_REALTIME,&current);
        final=current.tv_sec*1000+current.tv_nsec/1000000;

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

