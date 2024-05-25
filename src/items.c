#include "items.h"

int destroy_obj(Game* game, int x, int y ){
    game->map.set(&game->map, x ,y, MAP_ROOM);
}

int object_effect(Game* game, Map_def value){
    

    switch (value)
    {
    case MAP_HEATH_CHARGE:
        game->player.set_life(&game->player, game->player.get_life(&game->player) + 10);
        break;
    case MAP_HEATH_MEGA_CHARGE:
        game->player.set_life(&game->player, game->player.get_life(&game->player) + 50);
        break;
    case MAP_SONIC_VISION:
        game->player.__vision = 1;
        break;
    case MAP_SONIC_SPEED:
         game->player.__speed = 5;
        break;
    case MAP_HEATH_OR_DIE:
        if (randint(0,2) == 0)
        {
            game->player.set_life(&game->player, game->player.get_life(&game->player) + 10);
        } else {
            game->player.set_life(&game->player, game->player.get_life(&game->player) - 10);
        }
        
        break;
    
    default:
        break;
    }
}


