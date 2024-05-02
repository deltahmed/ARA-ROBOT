
#include "ARA_def.h"
#include "map.h"
#include "ARA_window.h"
#include "ARA_time.h"



typedef struct __game_struct
{   
    ARA_Window window;
    Map map;
    Timer timer;
    
}Game;

void generatemap(Map* map){
    for (Size i = 0; i < map->sizex(map); i++)
    {
        for (Size j = 0; j < map->sizey(map); j++)
        {
            map->set(map, i, j, 1);
        }
        
    }
    
}

void printmap(Game* game){
    for (Size i = 1; i < GAME_SCREEN_X; i++)
    {
        for (Size j = 1; j < GAME_SCREEN_Y; j++)
        {   
            
            cprint(game->window.top, i, j, COLOR_MUR2, "#");
        }
        
    }
    
}


Game Game_init(){
    Game self;
    ARA_Window_init(&self.window, W_MODE_MULTIPLE);
    Map_init(&self.map, MAP_SIZE_X, MAP_SIZE_Y);
    Timer_init(&self.timer);
}



