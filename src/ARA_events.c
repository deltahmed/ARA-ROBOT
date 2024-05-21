#include "ARA_events.h"

/**
 * @brief Print a stylish alphabet
 * 
 * @param game The current game
 * @param car The user's caracter input
 * @param y The line where to print the alphabet
 * @param x The column where to print the alphabet
 */
void print_alphabet(Game *game, char car, int y, int x){
    char message[100];
    switch(car){
        case 'a' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█  █▀▀█  █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█  █▄▄█  █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█  █  █  █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'b' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█  █▀▀█  █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█  █▀▀▄  █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█  █▄▄█  █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'c' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█  █▀▀█  █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█  █     █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█  █▄▄█  █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'd' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█  █▀▀▄  █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█  █  █  █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█  █▄▄▀  █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'e' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█  █▀▀▀  █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█  █▀▀▀  █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█  █▄▄▄  █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'f' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█  █▀▀▀  █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█  █▀▀▀  █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█  █     █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'g' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█  █▀▀█  █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█  █ ▄▄  █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█  █▄▄█  █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'h' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█  █  █  █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█  █▀▀█  █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█  █  █  █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'i' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█  ▀█▀  █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█   █   █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█  ▄█▄  █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'j' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█     █  █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█  ▄  █  █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█  █▄▄█  █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'k' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█  █ ▄▀  █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█  █▀▄   █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█  █  █  █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'l' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█  █     █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█  █     █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█  █▄▄█  █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'm' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█ █▀▄▀█ █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█ █ █ █ █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█ █   █ █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'n' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█ █▄  █ █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█ █ █ █ █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█ █  ▀█ █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'o' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█ █▀▀▀█ █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█ █   █ █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█ █▄▄▄█ █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'p' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█  █▀▀█  █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█  █▄▄█  █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█  █     █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'q' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█  █▀▀█  █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█  █  █  █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█  ▀▀█▄  █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'r' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█  █▀▀█  █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█  █▄▄▀  █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█  █  █  █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 's' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█ █▀▀▀█ █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█ ▀▀▀▄▄ █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█ █▄▄▄█ █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 't' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█ ▀▀█▀▀ █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█   █   █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█   █   █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'u' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█  █  █  █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█  █  █  █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█  █▄▄█  █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'v' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█ █   █ █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█  █ █  █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█  ▀▄▀  █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'w' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█ █   █ █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█ █ █ █ █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█ █▄▀▄█ █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'x' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█ ▀▄ ▄▀ █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█   █   █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█ ▄▀ ▀▄ █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'y' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█ █   █ █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█ █▄▄▄█ █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█   █   █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case 'z' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-2,x-4,message);
            snprintf(message, sizeof(message), "█ ▀▀▀▀█ █");
            mvwaddstr(game->window.top,y-1,x-4,message);
            snprintf(message, sizeof(message), "█ ▄▄▄▀▀ █");
            mvwaddstr(game->window.top, y ,x-4,message);
            snprintf(message, sizeof(message), "█ █▄▄▄▄ █");
            mvwaddstr(game->window.top,y+1,x-4,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+2,x-4,message);
            break;
        case ' ' :
            snprintf(message, sizeof(message), "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█");
            mvwaddstr(game->window.top,y-1,x-8,message);
            snprintf(message, sizeof(message), "█ █▄▄▄▄▄▄▄▄▄▄▄▄█ █");
            mvwaddstr(game->window.top,y,x-8,message);
            snprintf(message, sizeof(message), "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█");
            mvwaddstr(game->window.top,y+1,x-8,message);
    }
}

/**
 * @brief Displays a task with a border made of emoji characters.
 *
 * This function draws a rectangular border using emoji characters.
 * 
 * @param game Pointer to the current game.
 */
void task_pop_up(Game *game, char * mission, char * emoji, int* x1, int* y1, int* x2, int* y2){
    int y=0;
    int x=0;
    *x1=(NB_COLS / 3)-22;
    *y1=(NB_LINES / 3)-7;
    *x2=(NB_COLS / 3)+23;
    *y2=(NB_LINES / 3)+7;
    //Il faut que x1 soit egale a (NB_COLS / 3)-k avec k pair comme ca ca ne bug pas avec l'affichage d une emote sur une autre
    char message[100];
    for(y=*y1; y<*y2; y++){
        for(x=*x1; x<*x2; x+=2){
            if(y==*y1 || y==*y2-1 || x==*x1 || x==*x2-1){
                snprintf(message, sizeof(message), emoji);
            }
            else{
                snprintf(message, sizeof(message), "  ");
            }
            mvwaddstr(game->window.top,y,x,message);
        }
    }
    //Comme mvwaddstr ne prend que 4 parametres je ne peux pas faire (....,"%s",mission) c est pour ca que snprintf formate ma chaine pour etre utilisee sans "%s"
    snprintf(message, sizeof(message), "%s",mission);
    mvwaddstr(game->window.top,*y1+1,*x1+(*x2-*x1)/2 - strlen(message)/2 +1,message);
}

//🕹
void task_recalibrate(Game *game){
    int x1, x2, y1, y2;
    task_pop_up(game, "Recalibrer le vaisssaux", "⚙ ", &x1, &y1, &x2, &y2);
    char buffer[100];
    for (int y = y1+4; y < y2-4; y++)
    {
        for (int x = x1+2; x < x2-1; x++)
        {   
            if ( is_in(x, x1 + (x2-x1)/2 - 3, x1 + (x2-x1)/2 + 3))
            {
                cprintadd(game->window.top, x ,y ,FONT_CRS_COLOR_BRIGHT_RED," ");
            } else if ( is_in(x, x1 + (x2-x1)/2 - 6, x1 + (x2-x1)/2 + 6 )){
                cprintadd(game->window.top, x ,y ,FONT_CRS_COLOR_BRIGHT_YELLOW," ");
            } else {
                cprintadd(game->window.top, x ,y ,FONT_CRS_COLOR_BRIGHT_GREEN," ");
            }
            
            
        }
    }

}

/**
 * @brief Displays the control instructions in the bottom window of the game.
 * @param game Pointer to the current game.
 */
void keys(Game game){
    mvwprintw(game.window.bottom,1,3,"    +---+");
    mvwprintw(game.window.bottom,2,3,"    | z |");
    mvwprintw(game.window.bottom,3,3,"+---+---+---+");
    mvwprintw(game.window.bottom,4,3,"| q | s | d |");
    mvwprintw(game.window.bottom,5,3,"+---+---+---+");
    mvwprintw(game.window.bottom,7,2,"m : Menu");
}

/**
 * @brief Print the arena of the QTE game between the player and the monster
 * 
 * @param game Pointer to the Game structure containing game state and window information.
 * @param car The player input caracter
 */
void print_arena(Game *game, char car){
    int y=0,x=0,y1=(NB_LINES / 3)-5,y2=(NB_LINES / 3)+5,x1=(NB_COLS / 3)-22,x2=(NB_COLS / 3)+23;
    //Il faut que x1 soit egale a (NB_COLS / 3)-k avec k pair comme ca ca ne bug pas avec l'affichage d une emote sur une autre
    char fight[]="C'est l'heure du du-du-du-du-duel";
    char message[100];
    for(y=y1;y<y2;y++){
        for(x=x1;x<x2;x+=2){
            if(y==y1 || y==y2-1 || x==x1 || x==x2-1){
                snprintf(message, sizeof(message), "⚔ ");
            }
            else{
                snprintf(message, sizeof(message), "  ");
            }
            mvwaddstr(game->window.top,y,x,message);
        }
    }
    snprintf(message, sizeof(message), "%s",fight);
    //Comme mvwaddstr ne prend que 4 parametres je ne peux pas faire (....,"%s",mission) c est pour ca que snprintf formate ma chaine pour etre utilisee sans "%s"
    mvwaddstr(game->window.top,y1+1,x1+6,message);
    snprintf(message, sizeof(message), "🤖");
    mvwaddstr(game->window.top,y2-3,x1+3,message);
    snprintf(message, sizeof(message), "👾");
    mvwaddstr(game->window.top,y1+3,x2-4,message);
    if(car>=0){
        print_alphabet(game,car,(y1+y2)/2,(x1+x2)/2);
    }
    else{
        //Si car<0 c est un signal qui montre que je suis dans l'etape ou j attends que l'utilisateur tape espace
        print_alphabet(game,' ',(y1+y2)/2,(x1+x2)/2);
    }
    //A regarder le premier printArena dans le premier do while dans QTE pour comprendre pq je fais if car>0 
}

/**
 * @brief Executes a Quick Time Event (QTE) in the game.
 *
 * This function runs a QTE where the player must type random characters displayed on the screen 
 * within a certain time limit. If the player types the correct characters in the time limit, 
 * they pass the QTE; otherwise, they fail.
 *
 * @param game Pointer to the Game structure containing game state and window information.
 * @return true if the QTE is successfully completed.
 * @return false if not.
 */
int QTE(Game *game){
    char carvalue=0,car=0;
    int i=0;
    //Le premier do while c est en attendant que le joueur tape espace
    do{
        game->window.clear_all(&game->window);
        game->window.create(&game->window);
        wtimeout(game->window.main_window,500);
        keys(*game);
        game->timer.update(&game->timer);
        cprintf(game->window.bottom, 2, 6, BASE_CRS_COLOR_BRIGHT_RED, "Temps : %ld",game->timer.get(&game->timer));
        print_map(game);
        print_arena(game,-1);
        game->window.update(&game->window);
        game->window.update_key(&game->window);
    }while(game->window.get_key(&game->window)!=' ');
    //Là le joueur a tape espace et il commence a vraiment jouer le QTE
    for(i=0;i<6;i++){
        carvalue=randint('a','z'+1);
        game->window.clear_all(&game->window);
        game->window.create(&game->window);
        wtimeout(game->window.main_window,1000);
        keys(*game);
        game->timer.update(&game->timer);
        cprintf(game->window.bottom, 2, 6, BASE_CRS_COLOR_BRIGHT_RED, "Temps : %ld",game->timer.get(&game->timer));
        print_map(game);
        print_arena(game,carvalue);          
        game->window.update(&game->window);
        game->window.update_key(&game->window);
        car=game->window.get_key(&game->window);
        if((car!=carvalue)||(car==ERR)){
            //Si le joueur perd on detruit tout
            game->window.destroy();
            game->map.destroy(&game->map);
            return 0;
        }
    }
    //Si le programme arrive ici ca veut dire que le joueur a reussi de gagner au QTE
    game->map.set(&game->map,game->player.get_x(&game->player),game->player.get_y(&game->player),MAP_ROOM);
    //Je mets du vide a la place du monstre
    return 1;
}

/**
 * @brief Gives the direction of the monster to get next to the player
 * 
 * @param game The current game
 * @param xmonster The x of the monster to move
 * @param ymonster the y of the monster to move
 */
void movementMonster(Game *game, int xmonster, int ymonster){
    int x = game->player.get_x(&game->player), y = game->player.get_y(&game->player);
    //A ne pas enlever la repetition du game->map.set(....,MAP_ROOM) sinon ca enleve le monstre meme si il ne peut pas bouger 
    if(x==xmonster){
        if(y<ymonster && game->map.get(&game->map,xmonster,ymonster-1)==MAP_ROOM){
            game->map.set(&game->map,xmonster,ymonster-1,MAP_MONSTER);
            game->map.set(&game->map,xmonster,ymonster,MAP_ROOM);
        }
        else if(y>ymonster && game->map.get(&game->map,xmonster,ymonster+1)==MAP_ROOM){
            game->map.set(&game->map,xmonster,ymonster+1,MAP_MONSTER);
            game->map.set(&game->map,xmonster,ymonster,MAP_ROOM);
        }
    }
    else{
        if(x<xmonster && game->map.get(&game->map,xmonster-1,ymonster)==MAP_ROOM){
            game->map.set(&game->map,xmonster-1,ymonster,MAP_MONSTER);
            game->map.set(&game->map,xmonster,ymonster,MAP_ROOM);
        }
        else if(x>xmonster && game->map.get(&game->map,xmonster+1,ymonster)==MAP_ROOM){
            game->map.set(&game->map,xmonster+1,ymonster,MAP_MONSTER);
            game->map.set(&game->map,xmonster,ymonster,MAP_ROOM);
        }
    }
}

/**
 * @brief Moves the monster next to the player
 * 
 * @param game The current game
 */
void monster(Game *game){
    int x=0,y=0,x1=0,y1=0,x2=0,y2=0,posx=game->player.get_x(&game->player),posy=game->player.get_y(&game->player);
    get_actual_room(game,posx,posy,&x1,&x2,&y1,&y2);
    for(x=x1;x<x2;x++){
        for(y=y1;y<y2;y++){
            if(game->map.get(&game->map,x,y)==MAP_MONSTER){
                movementMonster(game,x,y);
                return ;
                //Je return ; comme ca je ne retombe pas sur le meme monstre une autre fois
            }
        }
    }
}