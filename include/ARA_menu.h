#ifndef MENU_H
#define MENU_H

#include "ARA_def.h"
#include "ARA_window.h"
#include "game.h"
#include "ARA_file.h"
#define SIZE_MENU 6
#define SIZE_CREDIT 4

void printmenu(ARA_Window self, char choice[SIZE_MENU][20], int k);
void printCredit(ARA_Window self);
int movementmenu(ARA_Window self, int *k);
int menuGame(Game *game);
int menuChoice(Game *game);
void printGameOver(ARA_Window self);
void gameEnd(Game game);

#endif