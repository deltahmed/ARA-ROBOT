#ifndef FILE_H
#define FILE_H
#include "ARA_def.h"
#include "map.h"
#include "ARA_window.h"
#include "game.h"



#define MAX_FILE_NAME 500


void saveArray(Game *game);
void recoverArray(Game *game);
void savePlayer(Game *game);
void recoverPlayer(Game *game);
void saveTimer(Game *game);
void recoverTimer(Game *game);
void saveGame(Game *game);
void recoverGame(Game *game);



#endif



