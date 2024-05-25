#ifndef EVENTS_H
#define EVENTS_H

#include "game.h"
#include "map.h"
#include "ARA_window.h"
#include <unistd.h>
#include <time.h>

#define TASK_TIMOUT 200
#define MAIN_TIMEOUT 500
#define AVOID 30

void print_alphabet(Game *game, char car, int y, int x);
void print_bottom_window(Game *game);
void task_pop_up(Game *game, char * mission, char * emoji, int* x1, int* y1, int* x2, int* y2);
int task_recalibrate(Game *game);
void task_fill(Game *game);
void task_avoid(Game *game);
void print_arena(Game *game, char car);
int QTE(Game *game);
void movementMonster(Game *game, int xmonster, int ymonster);
void monster(Game *game);
void re_print_all(Game *game, int timeout);

#endif