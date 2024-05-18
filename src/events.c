#include "events.h"

//Celui la c est pour l'affichage de task avec comme bord un caractere ASCII qui prend une seule case
/*void task(Game *game){
    int y=0,x=0,y1=(NB_LINES / 3)-6,y2=(NB_LINES / 3)+6,x1=(NB_COLS / 3)-24,x2=(NB_COLS / 3)+24;
    char mission[]="Reparer le dispositif d'oxygene";
    char message[100];
    for(y=y1;y<y2;y++){
        for(x=x1;x<x2;x++){
            if(y==y1 || y==y2-1 || x==x1 || x==x2-1){
                snprintf(message, sizeof(message), "#");
                mvwaddstr(game->window.top,y,x,message);
            }
            else{
                mvwaddch(game->window.top,y,x,' ');
            }
        }
    }
    snprintf(message, sizeof(message), "Task :");
    //Comme mvwaddstr ne prend que 4 parametres je ne peux pas faire (....,"%s",mission) c est pour ca que snprintf formate ma chaine pour etre utilisee sans "%s"
    mvwaddstr(game->window.top,y1+2,x1+2,message);
    snprintf(message, sizeof(message), "%s",mission);
    mvwaddstr(game->window.top,y1+4,x1+3,message);
}*/

//Celui la c est pour l'affichage de task avec comme bord un emoji qui prend deux cases
void task(Game *game){
    int y=0,x=0,y1=(NB_LINES / 3)-5,y2=(NB_LINES / 3)+5,x1=(NB_COLS / 3)-22,x2=(NB_COLS / 3)+23;
    //Il faut que x1 soit egale a (NB_COLS / 3)-k avec k pair comme ca ca ne bug pas avec l'affichage d une emote sur une autre
    char mission[]="Reparer le dispositif d'oxygene";
    char message[100];
    for(y=y1;y<y2;y++){
        for(x=x1;x<x2;x+=2){
            if(y==y1 || y==y2-1 || x==x1 || x==x2-1){
                snprintf(message, sizeof(message), "🔆");
                //D'autres emojis : 💠 🏮
                mvwaddstr(game->window.top,y,x,message);
            }
            else{
                snprintf(message, sizeof(message), "  ");
                mvwaddstr(game->window.top,y,x,message);
            }
        }
    }
    snprintf(message, sizeof(message), "Task :");
    //Comme mvwaddstr ne prend que 4 parametres je ne peux pas faire (....,"%s",mission) c est pour ca que snprintf formate ma chaine pour etre utilisee sans "%s"
    mvwaddstr(game->window.top,y1+2,x1+3,message);
    snprintf(message, sizeof(message), "%s",mission);
    mvwaddstr(game->window.top,y1+4,x1+4,message);
}

void touches(Game game){
    mvwprintw(game.window.bottom,1,3,"    +---+");
    mvwprintw(game.window.bottom,2,3,"    | z |                    m : Menu");
    mvwprintw(game.window.bottom,3,3,"+---+---+---+");
    mvwprintw(game.window.bottom,4,3,"| q | s | d |");
    mvwprintw(game.window.bottom,5,3,"+---+---+---+");
    mvwprintw(game.window.bottom,7,2,"⚔   Battle :");
}

int QTE(Game *game){
    char carvalue=0,car=0;
    int i=0;
    for(i=0;i<6;i++){
        carvalue='a'+rand()%('z'-'a');
        game->window.clear_all(&game->window);
        game->window.create(&game->window);
        wtimeout(game->window.main_window,1000);
        mvwprintw(game->window.bottom,8,3,"Tapez %c",carvalue);
        touches(*game);
        game->timer.update(&game->timer);
        cprintf(game->window.bottom, 2, 6, BASE_CRS_COLOR_BRIGHT_RED, "Temps : %ld",game->timer.get(&game->timer));
        printmap(game);
        game->window.update_key(&game->window);
        car=game->window.get_key(&game->window);            
        game->window.update(&game->window);
        if((car!=carvalue)||(car==ERR)){
            game->window.destroy();
            game->map.destroy(&game->map);
            return 0;
        }
    }
    game->map.set(&game->map,game->player.get_x(&game->player),game->player.get_y(&game->player),MAP_ROOM);
    game->window.clear_all(&game->window);
    game->window.create(&game->window);
    printmap(game);
    game->window.update(&game->window);
    return 1;
}