#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "ARA_def.h"
#include "map.h"
#include "ARA_window.h"
#include "ARA_time.h"
#include "ARA_debug.h"

#define MAX_NB_ROOMS 30

/**
 * @brief Rooms max and min size definition.
 */
#define ROOM_MAX_SIZE 22
#define ROOM_MIN_SIZE 2

/**
 * @brief a direction struct for multiple uses.
 */
typedef enum __dir_enum{
    D_NORTH,
    D_EAST,
    D_WEST,
    D_SOUTH,
    D_X,
    D_Y,
}Direction;

/**
 * @brief Game struct with all the game need.
 */
typedef struct __game_struct
{   
    ARA_Window window;
    Map map;
    Timer timer;
    Player player;
    int nb_room;
    int nb_gen_room;
    int nb_tasks;
    int nb_fin_tasks;
    
}Game;

// ========================== generator.c ===============================

void update_life(Game * game);

Map_def get_inverse_door(Map_def direction);
Map_def discover_door(Map_def direction);



void generate_doors_on_wall(Game* game, int x1, int y1, int x2, int y2, Map_def direction);
void generate_doors(Game* game, int x1, int y1, int x2, int y2, Map_def banned_door);
void generate_with_rules(Game* game, int x1, int y1, int x2, int y2);
void generate_room(Game* game);
void generate_first_room(Game* game);
void generate_map(Game* game);

void fill_probable_zone(Game* game, int x, int y, Map_def fill);
void fill_zone_and_doors(Game* game, int x1, int y1, int x2, int y2, Map_def banned_door);

int is_block(Map_def value);
int is_door(Map_def value);
int is_real_block(Map_def value);
int is_undiscovered_door(Map_def value);

int check_3x3_zone(Game* game, int offsetx, int offsety);
int check_possible_gen(Game* game, int x, int y, Map_def door);
void check_generation_update(Game* game);

int intersect(Game* game, int x1, int y1, int x2, int y2);

int stick_in_range(int x,int rangex1,int rangex2);

// ========================== game.c ===============================

void get_actual_room(Game* game, int player_x, int player_y, int* x1, int* x2, int* y1, int* y2);

int is_in_triangle(int tested_x, int tested_y, int x1, int x2, int basey, int miny, int maxy, Direction direction);
int is_in_cone(Game* game, int x, int y, int player_x, int player_y, int* room1_x1, int* room1_x2, int* room1_y1, int* room1_y2, int* room2_x1, int* room2_x2, int* room2_y1, int* room2_y2);

void print_switch_room(Game* game, int get_value, int i, int j);
void print_in_shadow(Game* game, int get_value, int playerx, int playery, int i, int j, int actual_x, int actual_y);
void print_map(Game* game);


boolean check_player_move(Game* self, int x, int y);

int player_movement(Game* self);

void Game_init(Game* self);
void Game_restart(Game* self);
#endif