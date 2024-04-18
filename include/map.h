#ifndef MAP
#define MAP
#include "ARA_def.h"

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