
#include "game.h"
//22
#define ROOM_MAX_SIZE 22
#define ROOM_MIN_SIZE 3

typedef enum dir_enum{
    D_NORTH,
    D_EAST,
    D_WEST,
    D_SOUTH,
    D_X,
    D_Y,
}Direction;

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
        return -1;
    }
}

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
        ARA_error(UNDEFINED_ERROR);
        return -1;
    }
}

boolean is_undiscovered_door(Map_def value){
    if (value >= MAP_UNDISCOVERED_DOOR_NORTH && value <= MAP_UNDISCOVERED_DOOR_SOUTH )
    {
        return 1;
    }
    return 0;
}
int check_possible_gen(Game* game, int x, int y, Map_def door);
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
void generate_doors(Game* game, int x1, int y1, int x2, int y2, Map_def banned_door){
     
    int probable_direction[3];
    int probable_direction_reroll[2];
      
    int doors = randint(1,4);
    if (banned_door == MAP_NONE)
    {
        return;
    }
    if (banned_door == MAP_ALL || doors == 3){
        for (int direction = MAP_UNDISCOVERED_DOOR_NORTH; direction <= MAP_UNDISCOVERED_DOOR_SOUTH; direction++){   
            if (direction != (int)banned_door ){
                generate_doors_on_wall(game, x1, y1, x2, y2, direction);
            }
            
            
        }
    } else {
         
        int index = 0;
        for (int direction = MAP_UNDISCOVERED_DOOR_NORTH; direction <= MAP_UNDISCOVERED_DOOR_SOUTH; direction++){   
            if (direction != (int)banned_door){
                probable_direction[index] = direction;
                index++;
            }
        }
        for (int i = 0; i < doors; i++){
              
            int rand_var = randint(0,3);
            generate_doors_on_wall(game, x1, y1, x2, y2, (Map_def)probable_direction[rand_var]);
        
            probable_direction_reroll[0] = randint(0,rand_var);
            probable_direction_reroll[1] = randint(rand_var+1,3);
            probable_direction[rand_var] = probable_direction[probable_direction_reroll[randint(0,2)]];
            
        }
          
        
    }
    
}

int is_real_block(Map_def value){
    return is_block(value) && value != MAP_FUTURE_ROOM;
    
}

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
    
     
    generate_doors(game, x1, y1, x2, y2, banned_door);
    
    
}

void generate_first_room(Game* game){
     
    int playerx = game->player.get_x(&game->player);
    int playery = game->player.get_y(&game->player);
    int size_x = randint(ROOM_MIN_SIZE*2, ROOM_MAX_SIZE-4);
    int size_y = randint(ROOM_MIN_SIZE*2, ROOM_MAX_SIZE-4);
   
    fill_zone_and_doors(game, playerx-size_x/2, playery-size_y/2,  playerx+size_x/2, playery+size_y/2, MAP_ALL);


}
void generatemap(Game* game){
    int randomtab[20] = {0};
    randomtab[0] = MAP_VOID;
    
    for (int x = 0; x < game->map.sizex(&game->map); x++)
    {
        for (int y = 0; y < game->map.sizey(&game->map); y++)
        {
            game->map.set(&game->map, x, y, randomtab[randint(0,20)]);
        }
    }
    
    generate_first_room(game);
    
}

int is_block(Map_def value){
    return (value < MAP_END_OF_BLOCK && value > MAP_ALL);
}

int is_door(Map_def value){
    return (value <= MAP_UNDISCOVERED_DOOR_SOUTH && value >= MAP_DOOR_NORTH);
}


int check_3x3_zone(Game* game, int offsetx, int offsety){
    for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {   
                if (offsetx+i != stick_in_range(offsetx+i, 0, game->map.sizex(&game->map)-1))
                {
                    return 0;
                }
                if (offsety+j != stick_in_range(offsety+j, 0, game->map.sizey(&game->map)-1))
                {
                    return 0;
                }
                if (is_block(game->map.get(&game->map, offsetx+i, offsety+j)))
                {
                    return 0;
                }
                
            }
        }
    return 1;
}


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
}

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
                    return 1;
                }
                
            }
            
        }
    return 0;
    
}

void generate_with_rules(Game* game, int x1, int y1, int x2, int y2){
    int playerx = game->player.get_x(&game->player);
    int playery = game->player.get_y(&game->player);
    int get_x1, get_x2, get_y1, get_y2;
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
    

    int get_value;
     

    while (intersect(game, x1, y1, x2, y2)){  
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

    if (intersect(game, x1, y1, x2, y2))
    {
        ARA_error(VALUE_ERROR);
    }
    
    

    fill_zone_and_doors(game,x1, y1, x2, y2, get_inverse_door(get_door));
     
    game->map.set(&game->map, playerx, playery, discover_door(get_door));
}

int stick_in_range(int x,int rangex1,int rangex2){
    if (x < rangex1)
    {
        return rangex1;
    }
    if (x > rangex2)
    {
        return rangex2;
    }
    return x;
    
}

void generateroom(Game* game){
     
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

void get_actual_room(Game* game, int player_x, int player_y, int* x1, int* x2, int* y1, int* y2){
    int get_value;
    for (int x = player_x; x < player_x + ROOM_MAX_SIZE; x++)
    {
        get_value = game->map.get(&game->map, x, player_y);
        if (is_block(get_value) && get_value != MAP_ROOM)
        {
            *x2 = x;
            break;
        }
        
    }
    for (int x = player_x; x > player_x - ROOM_MAX_SIZE; x--)
    {
        get_value = game->map.get(&game->map, x, player_y);
        if (is_block(get_value) && get_value != MAP_ROOM)
        {
            *x1 = x;
            break;
        }
        
    }
    for (int y = player_y; y < player_y + ROOM_MAX_SIZE; y++)
    {
        get_value = game->map.get(&game->map, player_x, y);
        if (is_block(get_value) && get_value != MAP_ROOM)
        {
            *y2 = y;
            break;
        }
        
    }
    for (int y = player_y; y > player_y - ROOM_MAX_SIZE; y--)
    {
        get_value = game->map.get(&game->map, player_x, y);
        if (is_block(get_value) && get_value != MAP_ROOM)
        {
            *y1 = y;
            break;
        }
        
    }
    
}


void get_actual_2room_x(Game* game, int player_x, int player_y, int* x1, int* x2){
    int get_value;
    for (int x = player_x+1; x < player_x + ROOM_MAX_SIZE*2; x++)
    {
        get_value = game->map.get(&game->map, x, player_y);
        if (is_block(get_value) && get_value != MAP_ROOM)
        {
            *x2 = x;
            break;
        }
        
    }
    for (int x = player_x-1; x > player_x - ROOM_MAX_SIZE*2; x--)
    {
        get_value = game->map.get(&game->map, x, player_y);
        if (is_block(get_value) && get_value != MAP_ROOM)
        {
            *x1 = x;
            break;
        }
        
    }
    
}
void get_actual_2room_y(Game* game, int player_x, int player_y, int* y1, int* y2){
    int get_value;
    for (int y = player_y+1; y < player_y + ROOM_MAX_SIZE*2; y++)
    {
        get_value = game->map.get(&game->map, player_x, y);
        if (is_block(get_value) && get_value != MAP_ROOM)
        {
            *y2 = y;
            break;
        }
        
    }
    for (int y = player_y-1; y > player_y - ROOM_MAX_SIZE*2; y--)
    {
        get_value = game->map.get(&game->map, player_x, y);
        if (is_block(get_value) && get_value != MAP_ROOM)
        {
            *y1 = y;
            break;
        }
        
    }
    
}

int is_in_triangle(int tested_x, int tested_y, int x1, int x2, int basey, Direction direction){
    int spacement = 1;
    switch (direction)
    {
    case D_NORTH:
    case D_WEST:
        for (int x = x2; x > x1; x--)
        {   
            if (is_in(tested_x,x1, x-1) && is_in(tested_y, basey - spacement/2, basey + spacement/2) )
            {
                return 1;
            }
            
            spacement++;
        }
        break;
    case D_SOUTH:
    case D_EAST:
   
        for (int x = x1; x < x2; x++)
        {   
            intlog(spacement/2);
            if (is_in(tested_x,x+1, x2-1) && is_in(tested_y, basey - spacement/2, basey + spacement/2) )
            {   
                return 1;
            }
            spacement++;
            
            
        }
        break;
    
    default:
        break;
    }
    return 0;
}

int is_in_cone(Game* game, int x, int y, int player_x, int player_y){
    int x1; 
    int x2; 
    int y1; 
    int y2;

    int get_door = game->map.get(&game->map, player_x, player_y);
    switch (get_door)
    {
    case MAP_UNDISCOVERED_DOOR_NORTH:
    case MAP_DOOR_NORTH:
    case MAP_UNDISCOVERED_DOOR_SOUTH:
    case MAP_DOOR_SOUTH:
        get_actual_2room_y(game, player_x, player_y, &y1, &y2);
        
        return is_in_triangle(y, x, y1, player_y, player_x, D_NORTH) || is_in_triangle(y, x, player_y, y2, player_x, D_SOUTH);
        
    case MAP_UNDISCOVERED_DOOR_EAST:
    case MAP_DOOR_EAST:
    case MAP_UNDISCOVERED_DOOR_WEST:
    case MAP_DOOR_WEST:
        
        get_actual_2room_x(game, player_x, player_y, &x1, &x2);
        return is_in_triangle(x, y, x1, player_x, player_y, D_WEST) ||  is_in_triangle(x, y, player_x, x2, player_y, D_EAST);
    
    default:
        break;
    }
    
}

void printmap(Game* game){
    int playerx = game->player.get_x(&game->player);
    int playery = game->player.get_y(&game->player);
    int offset_x = GAME_SCREEN_X/4;
    int offset_y = GAME_SCREEN_Y/2;

    int start_x = playerx - offset_x + 1;
    start_x = (start_x > 0) ? start_x : 0;

    int start_y = playery - offset_y + 1;
    start_y = (start_y > 0) ? start_y : 0;

    int end_x = playerx + offset_x;
    start_x = (end_x < MAP_SIZE_X) ? start_x : MAP_SIZE_X-GAME_SCREEN_X/2;

    int end_y = playery + offset_y ;
    start_y = (end_y < MAP_SIZE_Y) ? start_y : MAP_SIZE_Y-GAME_SCREEN_Y;

    int actual_x = start_x;
    int actual_y = start_y;
    int get_value;

    int actual_room_x1, actual_room_x2, actual_room_y1, actual_room_y2;

    for (Size i = 1; i < GAME_SCREEN_X+1; i+=2)
    {   
        actual_y = start_y;
        for (Size j = 1; j < GAME_SCREEN_Y+1; j++)
        {   
            get_value = game->map.get(&game->map, actual_x, actual_y);
            
            if ( (playerx == actual_x && playery == actual_y))
            {   
                cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "🤖"); 
                //mvwprintw(game->window.top, j, i, "Ƣ@");   
            }else
            {
                switch (get_value)
                {
                case MAP_WALL:
                    cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "🔳"); 
                    break;
                case MAP_ROOM:
                    if (!is_door(game->map.get(&game->map, playerx, playery)))
                    {
                        get_actual_room(game, playerx, playery, &actual_room_x1, &actual_room_x2, &actual_room_y1, &actual_room_y2);

                        if (is_in(actual_x, actual_room_x1, actual_room_x2) &&  is_in(actual_y, actual_room_y1, actual_room_y2))
                        {
                            cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "  ");
                        } else {
                            cprint(game->window.top, i, j, BASE_CRS_COLOR_BRIGHT_BLACK, "..");
                        }
                    } else {
                        if (is_in_cone(game, actual_x, actual_y, playerx, playery))
                        {
                            cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "  ");
                        } else {
                            cprint(game->window.top, i, j, BASE_CRS_COLOR_BRIGHT_BLACK, "..");
                        }
                        
                    }
                    
                    
                    
                    break;
                case MAP_VOID:
                    cprint(game->window.top, i, j, BASE_CRS_COLOR_BRIGHT_BLACK, "* "); 
                    break;
                case MAP_UNDISCOVERED_DOOR_NORTH:
                case MAP_UNDISCOVERED_DOOR_EAST:
                case MAP_UNDISCOVERED_DOOR_WEST:
                case MAP_UNDISCOVERED_DOOR_SOUTH:
                    cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "🌀"); 
                    
                    break;
                case MAP_DOOR_NORTH:
                case MAP_DOOR_EAST:
                case MAP_DOOR_WEST:
                case MAP_DOOR_SOUTH:
                    cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "🍥"); 
                    
                    break;
                
                default:
                    break;
                }
                
            }
            
            
            actual_y++;
            
        }
        actual_x++;
        
    }
    
    
}

void check_generation(Game* game){
    int playerx = game->player.get_x(&game->player);
    int playery = game->player.get_y(&game->player);
    int get_value = game->map.get(&game->map, playerx, playery);
    if (is_undiscovered_door(get_value))
    {
        generateroom(game);
    }
    
}

boolean __check_move(Game* self, int x, int y){
    int sizex = self->map.sizex(&self->map);
    int sizey = self->map.sizey(&self->map);
    if (x>=0 && x<sizex && y>=0 && y<sizey && self->map.get(&self->map, x, y)!=MAP_WALL) {
        return 1;
    }
    return 0;
}




void __movement(Game* self){
    
    int x = self->player.get_x(&self->player);
    int y = self->player.get_y(&self->player);
    
    switch(self->window.get_key(&self->window)){
        case 'q':
            if(__check_move(self, x-1, y)){
                self->player.set_x(&self->player,x-1);
            }
            break;
        case 'd':
            if(__check_move(self, x+1, y)){
                self->player.set_x(&self->player,x+1);
            }
            break;
        case 'z' :
            if(__check_move(self, x, y-1)){
                self->player.set_y(&self->player,y-1);
            }
            break;
        case  's' :
            if(__check_move(self, x, y+1)){
                self->player.set_y(&self->player,y+1);
            }
    }
    self->window.__key = 0;
    check_generation(self);

}


void Game_init(Game* self){
    srand(56165);
    log_reset();
    ARA_Window_init(&self->window, W_MODE_MULTIPLE);
    Map_init(&self->map, MAP_SIZE_X, MAP_SIZE_Y);
    Timer_init(&self->timer);
    Init_Player(&self->player);
}