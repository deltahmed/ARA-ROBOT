
#include "game.h"


/**
 * @brief Function to get the inverse direction of a door.
 * 
 * @param direction base direction.
 * @return Map_def : inverse direction.
 * @throw Raise a VALUE_ERROR if the direction is not an undiscovered door.
 */
Map_def get_inverse_door(Map_def direction){
    switch (direction)
    {
    case MAP_UNDISCOVERED_DOOR_NORTH:
        return MAP_UNDISCOVERED_DOOR_SOUTH;
    case MAP_UNDISCOVERED_DOOR_EAST:
        return MAP_UNDISCOVERED_DOOR_WEST;
    case MAP_UNDISCOVERED_DOOR_WEST:
        return MAP_UNDISCOVERED_DOOR_EAST;
    case MAP_UNDISCOVERED_DOOR_SOUTH:
        return MAP_UNDISCOVERED_DOOR_NORTH;
    default:
        ARA_error(VALUE_ERROR);
        return NEGATIVE;
    }
}

/**
 * @brief Change the state of a Undiscovered door to a discovered door.
 * 
 * @param direction base direction.
 * @return Map_def the discovered door.
 * @throw Raise a VALUE_ERROR if the direction is not an undiscovered door.
 */
Map_def discover_door(Map_def direction){
    switch (direction)
    {
    case MAP_UNDISCOVERED_DOOR_NORTH:
        return MAP_DOOR_NORTH;
    case MAP_UNDISCOVERED_DOOR_EAST:
        return MAP_DOOR_EAST;
    case MAP_UNDISCOVERED_DOOR_WEST:
        return MAP_DOOR_WEST;
    case MAP_UNDISCOVERED_DOOR_SOUTH:
        return MAP_DOOR_SOUTH;
    default:
        ARA_error(VALUE_ERROR);
        return NEGATIVE;
    }
}

/**
 * @brief This function generate doors on a precises wall.
 * 
 * @param game The current game.
 * @param x1 The up left corner of the room x coordinate .
 * @param y1 The up left corner of the room y coordinate .
 * @param x2 The down right corner of the room x coordinate .
 * @param y2 The down right corner of the room y coordinate .
 * @param direction The door direction.
 */
void generate_doors_on_wall(Game* game, int x1, int y1, int x2, int y2, Map_def direction){
    int rand_var;
    switch (direction)
    {
    case MAP_UNDISCOVERED_DOOR_NORTH:
        rand_var = randint(x1+1, x2);
        if (check_possible_gen(game, rand_var, y1, direction))
        {   
            
            game->map.set(&game->map, rand_var, y1, MAP_UNDISCOVERED_DOOR_NORTH);
            fill_probable_zone(game, rand_var, y1, MAP_FUTURE_ROOM);
        }
        
        break;
    case MAP_UNDISCOVERED_DOOR_EAST:
        rand_var = randint(y1+1, y2);
        if (check_possible_gen(game, x2, rand_var, direction))
        {   
            
            game->map.set(&game->map, x2, rand_var, MAP_UNDISCOVERED_DOOR_EAST);
            fill_probable_zone(game, x2, rand_var, MAP_FUTURE_ROOM);
        }
        break;
    case MAP_UNDISCOVERED_DOOR_WEST:
        rand_var = randint(y1+1, y2);
        if (check_possible_gen(game, x1, rand_var, direction))
        {   
            game->map.set(&game->map, x1, rand_var, MAP_UNDISCOVERED_DOOR_WEST);
            fill_probable_zone(game, x1, rand_var, MAP_FUTURE_ROOM);
        }
        break;
    case MAP_UNDISCOVERED_DOOR_SOUTH:
        rand_var = randint(x1+1, x2);
        if (check_possible_gen(game, rand_var, y2, direction))
        {   
            
            game->map.set(&game->map, rand_var, y2, MAP_UNDISCOVERED_DOOR_SOUTH);
            fill_probable_zone(game, rand_var, y2, MAP_FUTURE_ROOM);
        }
        break;
    default:
        break;

    }
}

/**
 * @brief This function generate all the random doors in a room.
 * 
 * @param game The current game.
 * @param x1 The up left corner of the room x coordinate. 
 * @param y1 The up left corner of the room y coordinate .
 * @param x2 The down right corner of the room x coordinate .
 * @param y2 The down right corner of the room y coordinate .
 * @param banned_door The door where the player from.
 */

int get_door_index(int door){
    return door - MAP_UNDISCOVERED_DOOR_NORTH;
}

Map_def get_random_door(int* already_visited) {
    int d_possible[4] = {NEGATIVE, NEGATIVE, NEGATIVE, NEGATIVE};
    int d_index = 0;

    for (int direction = MAP_UNDISCOVERED_DOOR_NORTH; direction <= MAP_UNDISCOVERED_DOOR_SOUTH; direction++) {
        if (!already_visited[get_door_index(direction)]) {
            d_possible[d_index] = direction;
            d_index++;
        }
    }

    if (d_index == 0) {
        return 0;
    }

    int rand_index = randint(0, d_index - 1);
    return (Map_def)d_possible[rand_index];
}

void generate_doors(Game* game, int x1, int y1, int x2, int y2, Map_def banned_door){

    Map_def rand_door;
    int direction_used[4] = {false, false, false, false};

    if (is_door(banned_door))
    {
        direction_used[get_door_index((int)banned_door)] = 1;
    }
    
      
    int doors = randint(1,4);

    if (banned_door == MAP_ALL || doors == 3)
    {   

        for (int direction = MAP_UNDISCOVERED_DOOR_NORTH; direction <= MAP_UNDISCOVERED_DOOR_SOUTH; direction++){   
            if (direction != (int)banned_door ){
               
                generate_doors_on_wall(game, x1, y1, x2, y2, direction);
                
            }
            
            
        }
    }
    else if (banned_door != MAP_NONE)
    {
        for (int i = 0; i < doors; i++)
        {   
            rand_door = get_random_door(direction_used);
            generate_doors_on_wall(game, x1, y1, x2, y2, rand_door);
            direction_used[get_door_index((int)rand_door)] = true;
        }
    }
    
}

/**
 * @brief This function generate the first room of a new game.
 * 
 * @param game The current game.
 */
void generate_first_room(Game* game){
     
    int playerx = game->player.get_x(&game->player);
    int playery = game->player.get_y(&game->player);
    int size_x = randint(ROOM_MIN_SIZE*2, ROOM_MAX_SIZE-4);
    int size_y = randint(ROOM_MIN_SIZE*2, ROOM_MAX_SIZE-4);
   
    fill_zone_and_doors(game, playerx-size_x/2, playery-size_y/2,  playerx+size_x/2, playery+size_y/2, MAP_ALL);


}

/**
 * @brief This function generate the map and set the stars (*) in the background.
 * 
 * @param game The current game.
 */
void generate_map(Game* game){
    int randomtab[20] = {0};
    randomtab[0] = MAP_VOID;
    
    for (int x = 0; x < (int)game->map.sizex(&game->map); x++)
    {
        for (int y = 0; y < (int)game->map.sizey(&game->map); y++)
        {
            game->map.set(&game->map, x, y, randomtab[randint(0,20)]);
        }
    }
    
    generate_first_room(game);
    
}

/**
 * @brief This function generate the future room without crossing the others rooms.
 * 
 * @param game The current game.
 * @param x1 The up left corner of the room x coordinate .
 * @param y1 The up left corner of the room y coordinate .
 * @param x2 The down right corner of the room x coordinate .
 * @param y2 The down right corner of the room y coordinate .
 */
void generate_with_rules(Game* game, int x1, int y1, int x2, int y2){
    int playerx = game->player.get_x(&game->player);
    int playery = game->player.get_y(&game->player);
    
    int get_door = game->map.get(&game->map, playerx, playery);
    fill_probable_zone(game, playerx, playery, MAP_NONE);
    int max_x = max(x1,x2);
    int max_y = max(y1,y2);
    int min_x = min(x1,x2);
    int min_y = min(y1,y2);
     
    x1 = min_x;
    x2 = max_x;
    y1 = min_y;
    y2 = max_y;

    int miniroom = 0;
    
     

    while (intersect(game, x1, y1, x2, y2) && !miniroom){  
        if (y2-y1 + x2 - x1 <= 6)
        {
            miniroom = 1;
        }
        
        switch (get_door){
        case MAP_UNDISCOVERED_DOOR_NORTH:
                if (x1 < playerx-1)
                {
                    x1++;
                }
                if (playerx+1 < x2)
                {
                    x2--;
                }
                if (y2-y1 > ROOM_MIN_SIZE)
                {
                    y1++; 
                }
                
                

            break;
        case MAP_UNDISCOVERED_DOOR_WEST:
                if (x2-x1 > ROOM_MIN_SIZE)
                {
                    x1++;
                }
                if (y1 < playery-1)
                {
                    y1++;
                }
                if (playery+1 < y2)
                {
                    y2--;
                } 
            
            break;
        case MAP_UNDISCOVERED_DOOR_EAST:
                if (x2-x1 > ROOM_MIN_SIZE)
                {
                    x2--;
                }
                if (y1 < playery-1)
                {
                    y1++;
                }
                if (playery+1 < y2)
                {
                    y2--;
                } 
            break;
        case MAP_UNDISCOVERED_DOOR_SOUTH:
                if (x1 < playerx-1)
                {
                    x1++;
                     
                }
                if (playerx+1 < x2)
                {
                    x2--;
                     
                }
                if (y2-y1 > ROOM_MIN_SIZE)
                {
                    y2--; 
                }
            break;
        default:
            break;
        }
    }
    if (x2-x1 < ROOM_MIN_SIZE+1)
    {
        switch (get_door)
        {
        case MAP_UNDISCOVERED_DOOR_SOUTH:
        case MAP_UNDISCOVERED_DOOR_NORTH:
            x1 = playerx - ROOM_MIN_SIZE/2;
            x2 = playerx + ROOM_MIN_SIZE/2;
            break;
        case MAP_UNDISCOVERED_DOOR_EAST:
            x1 = playerx;
            x2 = playerx + (ROOM_MIN_SIZE-1);
            break;
        case MAP_UNDISCOVERED_DOOR_WEST:
            x1 = playerx - (ROOM_MIN_SIZE-1);
            x2 = playerx;
            break;
        default:
            break;
        }
    }

    if (y2-y1 < ROOM_MIN_SIZE+1)
    {
        switch (get_door)
        {
        case MAP_UNDISCOVERED_DOOR_SOUTH:
            y1 = playery;
            y2 = playery+(ROOM_MIN_SIZE-1);
            break;
        case MAP_UNDISCOVERED_DOOR_NORTH:
            y1 = playery-(ROOM_MIN_SIZE-1);
            y2 = playery;
            break;
        case MAP_UNDISCOVERED_DOOR_EAST:
        case MAP_UNDISCOVERED_DOOR_WEST:
            y1 = playery - ROOM_MIN_SIZE/2 ;
            y2 = playery + ROOM_MIN_SIZE/2;
            break;
        default:
            break;
        }
    }
    
    fill_zone_and_doors(game,x1, y1, x2, y2, get_inverse_door(get_door));
     
    game->map.set(&game->map, playerx, playery, discover_door(get_door));
}

/**
 * @brief This function generate a random room and call the generate_with_rules function.
 * 
 * @param game The current game.
 */
void generate_room(Game* game){
     
    int playerx = game->player.get_x(&game->player);
    int playery = game->player.get_y(&game->player);

    int x1, x2, y1, y2;
     
    int get_door = game->map.get(&game->map, playerx, playery);
      
    int size_x = randint(ROOM_MIN_SIZE, ROOM_MAX_SIZE);

    int size_y = randint(ROOM_MIN_SIZE, ROOM_MAX_SIZE);

    int offset_x = randint(2, size_x-1);

    int offset_y = randint(2, size_y-1);

    switch (get_door)
    {
    case MAP_UNDISCOVERED_DOOR_NORTH:
        x1 = playerx-offset_x;
        x2 = playerx+(size_x-offset_x);
        y1 = playery;
        y2 = playery-size_y;
        break;
    case MAP_UNDISCOVERED_DOOR_EAST:
        x1 = playerx;
        x2 = playerx+size_x;
        y1 = playery-offset_y;
        y2 = playery+(size_y-offset_y);
        break;
    case MAP_UNDISCOVERED_DOOR_WEST:
        x1 = playerx;
        x2 = playerx-size_x;
        y1 = playery-offset_y;
        y2 = playery+(size_y-offset_y);
        break;
    case MAP_UNDISCOVERED_DOOR_SOUTH:
        x1 = playerx-offset_x;
        x2 = playerx+(size_x-offset_x);
        y1 = playery;
        y2 = playery+size_y;
        break;
    default:
        break;
    }
    x1 = stick_in_range(x1, 0, game->map.sizex(&game->map)-1);
    x2 = stick_in_range(x2, 0, game->map.sizex(&game->map)-1);
    y1 = stick_in_range(y1, 0, game->map.sizey(&game->map)-1);
    y2 = stick_in_range(y2, 0, game->map.sizey(&game->map)-1);
    
    generate_with_rules(game, x1, y1, x2, y2);
    
}

/**
 * @brief This function fill a future probable zone for a room with MAP_FUTURE_ROOM or MAP_NONE.
 * 
 * @param game The current game..
 * @param x The player x position.
 * @param y The player y position.
 * @param fill The Map_def fill for the probable zone.
 */
void fill_probable_zone(Game* game, int x, int y, Map_def fill){
    int get_door = game->map.get(&game->map, x, y);
    switch (get_door)
    {
    case MAP_UNDISCOVERED_DOOR_NORTH:
        if (!is_real_block(game->map.get(&game->map, x-1, y-1))) {game->map.set(&game->map, x-1, y-1, fill);}
        if (!is_real_block(game->map.get(&game->map, x+1, y-1))) {game->map.set(&game->map, x+1, y-1, fill);}
        if (!is_real_block(game->map.get(&game->map, x  , y-1))) {game->map.set(&game->map, x  , y-1, fill);}
        if (!is_real_block(game->map.get(&game->map, x-1, y-2))) {game->map.set(&game->map, x-1, y-2, fill);}
        if (!is_real_block(game->map.get(&game->map, x+1, y-2))) {game->map.set(&game->map, x+1, y-2, fill);}
        if (!is_real_block(game->map.get(&game->map, x  , y-2))) {game->map.set(&game->map, x  , y-2, fill);}
        
        break;
    case MAP_UNDISCOVERED_DOOR_EAST:
        if (!is_real_block(game->map.get(&game->map, x+1, y-1))) {game->map.set(&game->map, x+1, y-1, fill);}
        if (!is_real_block(game->map.get(&game->map, x+1, y+1))) {game->map.set(&game->map, x+1, y+1, fill);}
        if (!is_real_block(game->map.get(&game->map, x+1, y  ))) {game->map.set(&game->map, x+1, y  , fill);}
        if (!is_real_block(game->map.get(&game->map, x+2, y-1))) {game->map.set(&game->map, x+2, y-1, fill);}
        if (!is_real_block(game->map.get(&game->map, x+2, y+1))) {game->map.set(&game->map, x+2, y+1, fill);}
        if (!is_real_block(game->map.get(&game->map, x+2, y  ))) {game->map.set(&game->map, x+2, y  , fill);}
        break;
    case MAP_UNDISCOVERED_DOOR_WEST:
        if (!is_real_block(game->map.get(&game->map, x-1, y-1))) {game->map.set(&game->map, x-1, y-1, fill);}
        if (!is_real_block(game->map.get(&game->map, x-1, y+1))) {game->map.set(&game->map, x-1, y+1, fill);}
        if (!is_real_block(game->map.get(&game->map, x-1, y  ))) {game->map.set(&game->map, x-1, y  , fill);}
        if (!is_real_block(game->map.get(&game->map, x-2, y-1))) {game->map.set(&game->map, x-2, y-1, fill);}
        if (!is_real_block(game->map.get(&game->map, x-2, y+1))) {game->map.set(&game->map, x-2, y+1, fill);}
        if (!is_real_block(game->map.get(&game->map, x-2, y  ))) {game->map.set(&game->map, x-2, y  , fill);}
        break;
    case MAP_UNDISCOVERED_DOOR_SOUTH:
        if (!is_real_block(game->map.get(&game->map, x-1, y+1))) {game->map.set(&game->map, x-1, y+1, fill);}
        if (!is_real_block(game->map.get(&game->map, x+1, y+1))) {game->map.set(&game->map, x+1, y+1, fill);}
        if (!is_real_block(game->map.get(&game->map, x  , y+1))) {game->map.set(&game->map, x  , y+1, fill);}
        if (!is_real_block(game->map.get(&game->map, x-1, y+2))) {game->map.set(&game->map, x-1, y+2, fill);}
        if (!is_real_block(game->map.get(&game->map, x+1, y+2))) {game->map.set(&game->map, x+1, y+2, fill);}
        if (!is_real_block(game->map.get(&game->map, x  , y+2))) {game->map.set(&game->map, x  , y+2, fill);}
        break;
    default:
        break;
    }
}

/**
 * @brief This function create the room walls and call the generate_doors function.
 * 
 * @param game The current .
 * @param x1 The up left corner of the room x coordinate .
 * @param y1 The up left corner of the room y coordinate.
 * @param x2 The down right corner of the room x coordinate .
 * @param y2 The down right corner of the room y coordinate.
 * @param banned_door The door where the player .
 */
void fill_zone_and_doors(Game* game, int x1, int y1, int x2, int y2, Map_def banned_door){
    int max_x = max(x1,x2);
    int max_y = max(y1,y2);
    int min_x = min(x1,x2);
    int min_y = min(y1,y2);
     
    x1 = min_x;
    x2 = max_x;
    y1 = min_y;
    y2 = max_y;
     
    for (int x = x1; x < x2+1 ; x++)
    {   
        game->map.set(&game->map, x, y1, MAP_WALL);
        game->map.set(&game->map, x, y2, MAP_WALL);
    }
     
    for (int y = y1; y < y2+1 ; y++)
    {   
        game->map.set(&game->map, x1, y, MAP_WALL);
        game->map.set(&game->map, x2, y, MAP_WALL);
    }

    for (int x = x1+1; x < x2 ; x++)
    {   
        for (int y = y1+1; y < y2 ; y++)
        {   
        game->map.set(&game->map, x, y, MAP_ROOM);
        }
    }
    
    game->map.set(&game->map, randint(x1+1,x2-1), randint(y1+1,y2-1), MAP_TASK);
    //game->map.set(&game->map, randint(x1+1,x2-1), randint(y1+1,y2-1), MAP_MONSTER);
    game->map.set(&game->map, randint(x1+1,x2-1), randint(y1+1,y2-1), MAP_HEATH_CHARGE);
    generate_doors(game, x1, y1, x2, y2, banned_door);
    
    
}

/**
 * @brief check if a value in the map is a "real" block (MAP_FUTURE_ROOM exluded).
 * 
 * @param value the map value.
 * @return true if the value is a block and it not MAP_FUTURE_ROOM.
 * @return false if not.
 */
int is_real_block(Map_def value){
    return is_block(value) && value != MAP_FUTURE_ROOM;
    
}

/**
 * @brief check if a value in the map is an undiscovered door.
 * 
 * @param value the map value.
 * @return true if the value is a undiscovered door .
 * @return false if not.
 */
int is_undiscovered_door(Map_def value){
    if (value >= MAP_UNDISCOVERED_DOOR_NORTH && value <= MAP_UNDISCOVERED_DOOR_SOUTH )
    {
        return true;
    }
    return false;
}

/**
 * @brief check if a value in the map is a block (MAP_FUTURE_ROOM included).
 * 
 * @param value the map value.
 * @return true if the value is a block.
 * @return false if not.
 */
int is_block(Map_def value){
    return (value < MAP_END_OF_BLOCK && value > MAP_ALL);
}

/**
 * @brief check if a value in the map is an door.
 * 
 * @param value the map value.
 * @return true if the value is a door .
 * @return false if not.
 */
int is_door(Map_def value){
    return (value <= MAP_UNDISCOVERED_DOOR_SOUTH && value >= MAP_DOOR_NORTH);
}



/**
 * @brief Check if a 3x3 zone is free.
 * 
 * @param game The current game.
 * @param offsetx The up left corner of the room x coordinate where the zone start.
 * @param offsety The up left corner of the room y coordinate where the zone start.
 * @return true if the zone is free .
 * @return false if not.
 */
int check_3x3_zone(Game* game, int offsetx, int offsety){
    for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {   
                if (offsetx+i != stick_in_range(offsetx+i, 0, game->map.sizex(&game->map)-1))
                {
                    return false;
                }
                if (offsety+j != stick_in_range(offsety+j, 0, game->map.sizey(&game->map)-1))
                {
                    return false;
                }
                if (is_block(game->map.get(&game->map, offsetx+i, offsety+j)))
                {
                    return false;
                }
                
            }
        }
    return true;
}


/**
 * @brief Check if a 3x3 zone is available on a specific door.
 * 
 * @param game The current game.
 * @param x The player x position.
 * @param y The player y position.
 * @param door The door direction (it has to be undiscovered).
 * @return true if the zone is available .
 * @return false if not.
 */
int check_possible_gen(Game* game, int x, int y, Map_def door){
    switch (door)
    {
    case MAP_UNDISCOVERED_DOOR_NORTH:
        return check_3x3_zone(game, x-ROOM_MIN_SIZE/2, y-ROOM_MIN_SIZE);
        break;
    case MAP_UNDISCOVERED_DOOR_EAST:
        return check_3x3_zone(game, x+ROOM_MIN_SIZE, y-ROOM_MIN_SIZE/2);
        break;
    case MAP_UNDISCOVERED_DOOR_WEST:
        return check_3x3_zone(game, x-ROOM_MIN_SIZE, y-1);
        break;
    case MAP_UNDISCOVERED_DOOR_SOUTH:
        return check_3x3_zone(game, x-ROOM_MIN_SIZE/2, y+ROOM_MIN_SIZE);
        break;
    default:
        break;
    }
    return true;
}

/**
 * @brief Check if the player is on a undiscovered door and generate a room.
 * 
 * @param game The current game.
 */
void check_generation_update(Game* game){
    int playerx = game->player.get_x(&game->player);
    int playery = game->player.get_y(&game->player);
    int get_value = game->map.get(&game->map, playerx, playery);
    if (is_undiscovered_door(get_value))
    {
        generate_room(game);
    }
    
}

/**
 * @brief This function check if a defined area is intercecting with other rooms.
 * 
 * @param game The current game.
 * @param x1 The up left corner of the room x coordinate.
 * @param y1 The up left corner of the room y coordinate.
 * @param x2 The down right corner of the room x coordinate.
 * @param y2 The down right corner of the room y coordinate.
 * @return true if the area is free.
 * @return false if the area isnt free.
 */
int intersect(Game* game, int x1, int y1, int x2, int y2){
    if (x1+1 >= x2)
    {
        x1= x2-1;

    }
    if (y1+1 >= y2)
    {
        y1= y2-1;
    }
    
    int get_value;
    for (int y = y1+1; y < y2; y++){  
            for (int x = x1+1; x < x2; x++)
            {
                get_value = game->map.get(&game->map, x, y);
                if (is_block(get_value))
                {
                    return true;
                }
                
            }
            
        }
    return false;
    
}
