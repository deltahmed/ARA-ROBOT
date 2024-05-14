#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "ARA_def.h"
#include "map.h"
#include "ARA_window.h"
#include "ARA_time.h"
#include "ARA_debug.h"




typedef struct __game_struct
{   
    ARA_Window window;
    Map map;
    Timer timer;
    Player player;
    
}Game;

void generatemap(Game* game);

void printmap(Game* game);

void __movement(Game* self);


void Game_init(Game* self);

#endif