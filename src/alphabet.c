
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