#ifndef FILE_H
#define FILE_H

#include "ARA_def.h"
#include "map.h"
#include "ARA_window.h"
#include "game.h"

void saveArray(Map *self);
void recoverArray(Map *self);
void savePlayer(Player *self);
void recoverPlayer(Player *self);
void saveTimer(Timer *self);
void recoverTimer(Timer *self);
void saveGame(Game *game);
void recoverGame(Game *game);

#endif