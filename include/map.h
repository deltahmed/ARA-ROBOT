#ifndef MAP
#define MAP
#include "ARA_def.h"
#include "ARA_window.h"

#define MAP_SIZE_X 100
#define MAP_SIZE_Y 100

typedef enum map_def_enum{
    MAP_NONE,
    MAP_VOID,
    MAP_ALL,
    MAP_WALL,
    MAP_ROOM,
    MAP_FUTURE_ROOM,
    MAP_DOOR_NORTH,
    MAP_DOOR_EAST,
    MAP_DOOR_WEST,
    MAP_DOOR_SOUTH,
    MAP_UNDISCOVERED_DOOR_NORTH,
    MAP_UNDISCOVERED_DOOR_EAST,
    MAP_UNDISCOVERED_DOOR_WEST,
    MAP_UNDISCOVERED_DOOR_SOUTH,
    MAP_END_OF_BLOCK,
    MAP_TASK,
    MAP_MONSTER,
}Map_def;

typedef struct __map_struct{
    int** __map;
    Size __sizex;
    Size __sizey;
    
    Size (*sizex)(struct __map_struct* self);
    Size (*sizey)(struct __map_struct* self);
    int (*get)(struct __map_struct* self, int x, int y);
    void (*set)(struct __map_struct* self, int x, int y, int value);
    void (*destroy)(struct __map_struct* self);
} Map;

void Map_init(Map* self, Size sizex, Size sizey);


#endif