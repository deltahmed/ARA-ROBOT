#include "items.h"

int destroy_obj(Game* game, int x, int y ){
    game->map.set(&game->map, x ,y, MAP_ROOM);
}

int object_effect(Game* game, int x, int y){
    intlog(game->player.get_life(&game->player));
    game->player.set_life(&game->player, game->player.get_life(&game->player) + 10);
    intlog(game->player.get_life(&game->player));
    destroy_obj(game, x, y);
}



