#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "ARA_def.h"
#include "map.h"
#include "ARA_window.h"
#include "ARA_time.h"




typedef struct __game_struct
{   
    ARA_Window window;
    Map map;
    Timer timer;
    Player player;
    
}Game;

void generatemap(Map* map);

void printmap(Game* game);

void __movement(Game* self);


Game Game_init();

#endif