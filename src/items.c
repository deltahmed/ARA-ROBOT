#include "items.h"

int destroy_obj(Game* game, int x, int y ){
    game->map.set(&game->map, x ,y, MAP_ROOM);
}

int object_effect(Game* game, int x, int y){
    game->player.set_life(&game->player, game->player.get_life(&game->player) + 10);
    destroy_obj(game, x, y);
}



