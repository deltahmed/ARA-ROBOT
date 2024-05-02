
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

    for (Size i = 1; i < GAME_SCREEN_X; i++)
    {
        for (Size j = 1; j < GAME_SCREEN_Y; j++)
        {   
            if (game->map.get(&game->map, i, j) == 1)
            {
                cprint(game->window.top, i, j, COLOR_MUR2, "#");
            }
            
        }
        
    }
    int playerx = game->player.get_x(&game->player);
    int playery = game->player.get_y(&game->player);
    cprint(game->window.top, playerx, playery, COLOR_MUR2, "@");
    
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