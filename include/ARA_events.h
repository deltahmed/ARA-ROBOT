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
void print_right_window(Game* game, int time_show);
void re_print_all(Game *game, int timeout, int show_right_time);


void task(Game *game, int value);
void task_pop_up(Game *game, char * mission, char * emoji, int* x1, int* y1, int* x2, int* y2);
void task_recalibrate(Game *game);
void task_fill(Game *game);
void task_temperature(Game *game);
void task_avoid(Game *game);
void task_download(Game *game);
void task_choose(Game *game);
void task_undertale(Game *game);

void print_arena(Game *game, char car, int monster);
int QTE(Game *game, int monster);

void movementMonster(Game *game, int xmonster, int ymonster, int monster);
void monster(Game *game);



#endif


