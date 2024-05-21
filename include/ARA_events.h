#ifndef EVENTS_H
#define EVENTS_H

#include "game.h"
#include "map.h"
#include "ARA_window.h"

void task_recalibrate(Game *game);
int QTE(Game *game);
void keys(Game game);
void print_arena(Game *game, char car);
void print_alphabet(Game *game, char car, int x, int y);
void movementMonster(Game *game, int xmonster, int ymonster);
void monster(Game *game);

#endif