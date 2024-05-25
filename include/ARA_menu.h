#ifndef MENU_H
#define MENU_H

#include <math.h>
#include "ARA_def.h"
#include "ARA_window.h"
#include "game.h"
#include "ARA_file.h"
#define SIZE_MENU 4
#define SIZE_CREDIT 4
#define SIZE_INFOS 2
#define NEWGAME 0
#define RESUMEGAME 1
#define CREDIT 2
#define EXIT 3

void printTitle(ARA_Window self);
void print_menu(ARA_Window self, char choice[SIZE_MENU][20], int k);
void print_credit(ARA_Window self);
int menu_movement(ARA_Window self, int *k);
int game_menu(Game *game);
int verif_number(char *numberchar);
void verif_string(char *name);
void player_infos(Game *game);
int choice_menu(Game *game);
void printGameOver(ARA_Window self);
void gameEnd(Game game);

#endif