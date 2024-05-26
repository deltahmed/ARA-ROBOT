
#include "ARA_def.h"
#include "map.h"
#include "ARA_window.h"
#include "game.h"
#include "ARA_menu.h"
#include "ARA_file.h"
#include "ARA_events.h"
#include "items.h"

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
    int compteur=0,menu=0;
    int get_value;
    do{
        menu=0;
        Game_init(&game);
        
        do{
            choice=choice_menu(&game);
            if(choice==EXIT){
                return 0;
            }
        }while(choice==CREDIT || choice==RESTORE_FAIL);//choice est egal a 4 si l utilisateur clique sur Credit puis sur la touche m pour revenir au menu
        
        game.window.destroy();
        //Pour supprimer le one_win_mode
        
        while(game.player.get_life(&game.player) >0) {
            re_print_all(&game,400,true);
            get_value = game.map.get(&game.map,game.player.get_x(&game.player),game.player.get_y(&game.player));
            if(is_task(get_value)){
                task(&game, get_value);
                game.map.set(&game.map,game.player.get_x(&game.player),game.player.get_y(&game.player),MAP_ROOM);
            }
            if (is_item(get_value))
            {
                game.player.add_object(&game.player, get_value);
                game.map.set(&game.map,game.player.get_x(&game.player),game.player.get_y(&game.player),MAP_ROOM);
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
                menu=1;
                break;
            } else if (player_movement(&game)==-1){
                menu=2;
                break;
            }

            clock_gettime(CLOCK_REALTIME,&current);
            final=current.tv_sec*1000+current.tv_nsec/1000000;
            get_value = game.map.get(&game.map,game.player.get_x(&game.player),game.player.get_y(&game.player));
            update_life(&game);
            if(is_monster(get_value) && QTE(&game,get_value)==0){
                game.player.set_life(&game.player,game.player.get_life(&game.player)-10);
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
        //Si menu==0 alos ca veut dire qu on a perdu 
        if(menu==0){
            gameEnd(game);
        } else if (menu == 2){
            gameWin(game);
        }
        else{
            saveGame(&game);
        }
    }while(true);
    saveGame(&game);
    game.window.destroy();
    game.map.destroy(&game.map);
    
    return 0;
}


