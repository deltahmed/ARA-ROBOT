#ifndef PLAYER_H
#define PLAYER_H

#include "map.h"

typedef struct __player_struct
{
    int __x;
    int __y;
    char __life;

    int* __inventory;
    int (*get_x)(struct __player_struct* self);
    int (*get_y)(struct __player_struct* self);
    int (*get_life)(struct __player_struct* self);
    void (*set_x)(struct __player_struct* self, int x);
    void (*set_y)(struct __player_struct* self, int y);
}Player;

void Init_Player(Player* self);


#endif