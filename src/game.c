
#include "game.h"

void generatemap(Map* map){
    for (Size i = 0; i < map->sizex(map); i++)
    {
        for (Size j = 0; j < map->sizey(map); j++)
        {
            map->set(map, i, j, rand()%20);
        }
        
    }
    
}

void printmap(Game* game){
    int playerx = game->player.get_x(&game->player);
    int playery = game->player.get_y(&game->player);
    int offset_x = GAME_SCREEN_X/2;
    int offset_y = GAME_SCREEN_Y/2;

    int start_x = playerx - offset_x + 1;
    start_x = (start_x > 0) ? start_x : 0;

    int start_y = playery - offset_y + 1;
    start_y = (start_y > 0) ? start_y : 0;

    int end_x = playerx + offset_x;
    start_x = (end_x < MAP_SIZE_X) ? start_x : MAP_SIZE_X-GAME_SCREEN_X;

    int end_y = playery + offset_y ;
    start_y = (end_y < MAP_SIZE_Y) ? start_y : MAP_SIZE_Y-GAME_SCREEN_Y;

    int actual_x = start_x;
    int actual_y = start_y;
    int get_value;

    for (Size i = 1; i < GAME_SCREEN_X+1; i++)
    {   
        actual_y = start_y;
        for (Size j = 1; j < GAME_SCREEN_Y+1; j++)
        {   
            get_value = game->map.get(&game->map, actual_x, actual_y);
            if ( get_value == 1)
            {
                get_value = 0;
                cprint(game->window.top, i, j, COLOR_MUR2, "#");  
            }
            if ( playerx == actual_x && playery == actual_y)
            {   
                cprintf(game->window.bottom, 0, 2, COLOR_MUR, "%d %d %d %d", playerx, playery, actual_x, actual_y);
                mvwprintw(game->window.top, j, i, "@");
                
            }
            
            actual_y++;
            
        }
        actual_x++;
        
    }
    
    
}
void __movement(Game* self){
    int x = self->player.get_x(&self->player);
    int y = self->player.get_y(&self->player);
    int sizex = self->map.sizex(&self->map);
    int sizey = self->map.sizey(&self->map);
    switch(self->window.get_key(&self->window)){
        case 'q':
            if(x>=1){
                self->player.set_x(&self->player,x-1);
            }
            break;
        case 'd':
            if(x<=sizex-2){
                self->player.set_x(&self->player,x+1);
            }
            break;
        case 'z' :
            if(y>=1){
                self->player.set_y(&self->player,y-1);
            }
            break;
        case  's' :
            if(y<=sizey-2){
                self->player.set_y(&self->player,y+1);
            }
    }
    self->window.__key = 0;
}


void Game_init(Game* self){
    srand(time(NULL));
    ARA_Window_init(&self->window, W_MODE_MULTIPLE);
    Map_init(&self->map, MAP_SIZE_X, MAP_SIZE_Y);
    Timer_init(&self->timer);
    Init_Player(&self->player);
}