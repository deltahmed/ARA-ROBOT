#ifndef MENU_H
#define MENU_H

#include "ARA_def.h"
#include "ARA_window.h"
#include "game.h"
#include "file.h"
#define SIZE_MENU 6

void printmenu(ARA_Window self, char choice[SIZE_MENU][20], int k);
int movementmenu(ARA_Window self, int *k);
int menuGame(Game *game);
int menuChoice(Game *game);

#endif