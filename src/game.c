
#include "game.h"

typedef enum door_dir_enum{
    D_TOP,
    D_RIGHT,
    D_LEFT,
    D_BOTTOM,
}Door_Direction;

uint32_t __random(int a, int b){
    return a + rand()%b;
}


void fill_zone(Game* game, int x1, int y1, int x2, int y2){
    int max_x = max(x1,x2);
    int max_y = max(y1,y2);
    int min_x = min(x1,x2);
    int min_y = min(y1,y2);
    x1 = min_x;
    x2 = max_x;
    y1 = min_y;
    y2 = max_y;
    for (int x = x1; x < x2+1 ; x++)
    {
        game->map.set(&game->map, x, y1, MAP_DOOR);
        game->map.set(&game->map, x, y2, MAP_WALL);
    }
    for (int y = y1; y < y2+1 ; y++)
    {
        game->map.set(&game->map, x1, y, MAP_WALL);
        game->map.set(&game->map, x2, y, MAP_WALL);
    }
    
}

void generate_first_room(Game* game){
    int playerx = game->player.get_x(&game->player);
    int playery = game->player.get_y(&game->player);
    Size size_x = __random(6, 20);
    Size size_y = __random(6, 10);
    fill_zone(game, playerx-size_x/2, playery-size_y/2,  playerx+size_x/2, playery+size_y/2);


}
void generatemap(Game* game){
    generate_first_room(game);
    
}

void printmap(Game* game){
    int playerx = game->player.get_x(&game->player);
    int playery = game->player.get_y(&game->player);
    int offset_x = GAME_SCREEN_X/4;
    int offset_y = GAME_SCREEN_Y/2;

    int start_x = playerx - offset_x + 1;
    start_x = (start_x > 0) ? start_x : 0;

    int start_y = playery - offset_y + 1;
    start_y = (start_y > 0) ? start_y : 0;

    int end_x = playerx + offset_x;
    start_x = (end_x < MAP_SIZE_X) ? start_x : MAP_SIZE_X-GAME_SCREEN_X/2;

    int end_y = playery + offset_y ;
    start_y = (end_y < MAP_SIZE_Y) ? start_y : MAP_SIZE_Y-GAME_SCREEN_Y;

    int actual_x = start_x;
    int actual_y = start_y;
    int get_value, get_prev_value;

    for (Size i = 1; i < GAME_SCREEN_X+1; i+=2)
    {   
        actual_y = start_y;
        for (Size j = 1; j < GAME_SCREEN_Y+1; j++)
        {   
            get_value = game->map.get(&game->map, actual_x, actual_y);
            if (actual_x != 0)
            {
                get_prev_value = game->map.get(&game->map, actual_x-1, actual_y);
            }else {
                get_prev_value = MAP_NONE;
            }
            
            if ( (playerx == actual_x && playery == actual_y))
            {   
                cprintf(game->window.bottom, 0, 2, COLOR_MUR, "%d %d %d %d", playerx, playery, actual_x, actual_y);
                mvwprintw(game->window.top, j, i, "😀");
                //mvwprintw(game->window.top, j, i, "Ƣ@");   
            }else if (playerx != actual_x-1 || playery != actual_y)
            {
                switch (get_value)
                {
                case MAP_WALL:
                    cprint(game->window.top, i, j, COLOR_MUR2, "🟥");  
                    break;
                case MAP_DOOR:
                    if (get_prev_value != MAP_DOOR)
                    {
                        cprint(game->window.top, i, j, COLOR_MUR2, "🚪"); 
                    }
                    
                    
                    break;
                
                default:
                    break;
                }
                
            }
            
            
            actual_y++;
            
        }
        actual_x++;
        
    }
    
    
}

boolean __check_move(Game* self, int x, int y){
    int sizex = self->map.sizex(&self->map);
    int sizey = self->map.sizey(&self->map);
    if (x>=0 && x<sizex-1 && y>=0 && y<sizey && self->map.get(&self->map, x, y)!=1) {
        return 1;
    }
    return 0;
}


void __movement(Game* self){
    int x = self->player.get_x(&self->player);
    int y = self->player.get_y(&self->player);
    
    switch(self->window.get_key(&self->window)){
        case 'q':
            if(__check_move(self, x-1, y)){
                self->player.set_x(&self->player,x-1);
            }
            break;
        case 'd':
            if(__check_move(self, x+1, y)){
                self->player.set_x(&self->player,x+1);
            }
            break;
        case 'z' :
            if(__check_move(self, x, y-1)){
                self->player.set_y(&self->player,y-1);
            }
            break;
        case  's' :
            if(__check_move(self, x, y+1)){
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