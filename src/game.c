
#include "game.h"
#include "items.h"
//22


void update_life(Game * game){
    
    int time = 30 - mod(game->timer.get(&game->timer), 31);
    if (time == 0)
    {
        game->player.set_life(&game->player, game->player.get_life(&game->player) - 4);
        game->player.__vision = 0;
    }
}


/**
 * @brief Get the actual room corners based on the player's position.
 * 
 * @param game Pointer to the curent Game.
 * @param player_x The x coordinate of the player position.
 * @param player_y The y coordinate of the playe =r position.
 * @param x1 Pointer to store the left x of the room.
 * @param x2 Pointer to store the right x of the room.
 * @param y1 Pointer to store the top y of the room.
 * @param y2 Pointer to store the bottom y of the room.
 */
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

/**
 * @brief Check if a point is within a triangle shape.
 * 
 * CAUTION : to use it on y coordinate you have to inverse x and y in the func parameters 
 * 
 * @param tested_x The x coordinate of the point to test.
 * @param tested_y The y coordinate of the point to test.
 * @param x1 The left x of the triangle.
 * @param x2 The right x of the triangle.
 * @param basey The base y coordinate of the triangle.
 * @param miny The minimum y coordinate.
 * @param maxy The maximum y coordinate.
 * @param direction The direction of the triangle.
 * @return true if the point is in the triangle.
 * @return false if not.
 */
int is_in_triangle(int tested_x, int tested_y, int x1, int x2, int basey, int miny, int maxy, Direction direction){
    int spacement = 0;
    switch (direction)
    {
    case D_NORTH:
    case D_WEST:
        for (int x = x2; x > x1; x--)
        {   
            if (is_in(tested_x,x1, x-1) && is_in(tested_y, basey - spacement/2, basey + spacement/2) && is_in(tested_y, miny, maxy) )
            {
                return true;
            }
            
            spacement+=2;
        }
        break;
    case D_SOUTH:
    case D_EAST:
   
        for (int x = x1; x < x2; x++)
        {   

            if (is_in(tested_x,x+1, x2-1) && is_in(tested_y, basey - spacement/2, basey + spacement/2) && is_in(tested_y, miny, maxy))
            {   
                return true;
            }
            spacement+=2;
            
            
        }
        break;
    
    default:
        break;
    }
    return false;
}
/**
 * @brief Check if a point is within a cone area defined relative to the player's position.
 * 
 * @param game Pointer to the curent Game.
 * @param x The x coordinate of the point to test.
 * @param y The y coordinate of the point to test.
 * @param player_x The x coordinate of the player position.
 * @param player_y The y coordinate of the player position.
 * @param room1_x1 Pointer to store the left x of the first room.
 * @param room1_x2 Pointer to store the right x of the first room.
 * @param room1_y1 Pointer to store the top y of the first room.
 * @param room1_y2 Pointer to store the bottom y of the first room.
 * @param room2_x1 Pointer to store the left x of the second room.
 * @param room2_x2 Pointer to store the right x of the second room.
 * @param room2_y1 Pointer to store the top y of the second room.
 * @param room2_y2 Pointer to store the bottom y of the second room.
 * @return true if the point is in the cone.
 * @return false if not.
 */
int is_in_cone(Game* game, int x, int y, int player_x, int player_y, int* room1_x1, int* room1_x2, int* room1_y1, int* room1_y2, int* room2_x1, int* room2_x2, int* room2_y1, int* room2_y2){
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
        get_actual_room(game, player_x, player_y-1, room1_x1, room1_x2, room1_y1, room1_y2);
        get_actual_room(game, player_x, player_y+1, room2_x1, room2_x2, room2_y1, room2_y2);
        y1 = *room1_y1;
        y2 = *room2_y2;
        return is_in_triangle(y, x, y1, player_y, player_x, *room1_x1, *room1_x2, D_NORTH) || is_in_triangle(y, x, player_y, y2, player_x, *room2_x1, *room2_x2, D_SOUTH);
        
    case MAP_UNDISCOVERED_DOOR_EAST:
    case MAP_DOOR_EAST:
    case MAP_UNDISCOVERED_DOOR_WEST:
    case MAP_DOOR_WEST:
        get_actual_room(game, player_x-1, player_y, room1_x1, room1_x2, room1_y1, room1_y2);
        get_actual_room(game, player_x+1, player_y, room2_x1, room2_x2, room2_y1, room2_y2);
        x1 = *room1_x1;
        x2 = *room2_x2;
        return is_in_triangle(x, y, x1, player_x, player_y,*room1_y1, *room1_y2, D_WEST) ||  is_in_triangle(x, y, player_x, x2, player_y, *room2_y1, *room2_y2, D_EAST);
    
    default:
        break;
    }
    return 0;
    
}


/**
 * @brief Print the appropriate symbol for the room content.
 * 
 * @param game Pointer to the curent Game.
 * @param get_value The value of the content.
 * @param i The x coordinate for printing (ON THE SCREEN NOT THE MAP).
 * @param j The y coordinate for printing (ON THE SCREEN NOT THE MAP).
 */
void print_switch_room(Game* game, int get_value, int i, int j){
    switch (get_value)
    {
    case MAP_HEATH_CHARGE:
        cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "🔋"); 
        break;
    case MAP_MONSTER:
        cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "👾"); 
        break;
    case MAP_ROOM:
        cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "  ");
        break;
    case MAP_TASK_REC:
        cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "🕹"); 
        break;
    case MAP_TASK_FILL:
        cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "⛽"); 
        break;
    case MAP_TASK_TEMPER:
        cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "🌡"); 
        break;
    case MAP_TASK_AVOID:
        cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "🌑"); 
        break;
    case MAP_TASK_DOWN:
        cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "📡"); 
        break;
    case MAP_TASK_CHOOSE:
        cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "🔬"); 
        break;
    case MAP_TASK_UNDER:
        cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "🎮"); 
        break;
    case MAP_MONSTER1:
        cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "🕷"); 
        break;
    case MAP_MONSTER2:
        cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "👽"); 
        break;
    case MAP_MONSTER3:
        cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "🐙"); 
        break;
    case MAP_MONSTER4:
        cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "🛸"); 
        break;

    case MAP_HEATH_MEGA_CHARGE:
        cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "⚡ "); 
        break;
    case MAP_SONIC_VISION:
        cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "🔮"); 
        break;
    case MAP_HEATH_OR_DIE:
        cprint(game->window.top, i, j, BASE_CRS_COLOR_WHITE, "🧪"); 
        break;
    default:
        break;
    }
        
}


            

/**
 * @brief Print the map elements considering the player's visibility.
 * 
 * @param game Pointer to the Game structure.
 * @param get_value The value of the element.
 * @param playerx The x coordinate of the player position.
 * @param playery The y coordinate of the player position.
 * @param i The x coordinate for printing (ON THE SCREEN NOT THE MAP).
 * @param j The y coordinate for printing (ON THE SCREEN NOT THE MAP).
 * @param actual_x The x coordinate of the current map element (ON THE MAP NOT THE SCREEN).
 * @param actual_y The y coordinate of the current map element (ON THE MAP NOT THE SCREEN).
 */
void print_in_shadow(Game* game, int get_value, int playerx, int playery, int i, int j, int actual_x, int actual_y){
    int room1_x1;
    int room1_x2;
    int room1_y2;
    int room1_y1;

    int room2_x1;
    int room2_x2;
    int room2_y2;
    int room2_y1;

    int actual_room_x1, actual_room_x2, actual_room_y1, actual_room_y2;
    
    if (!is_door(game->map.get(&game->map, playerx, playery) ) || game->player.__vision)
    {
        get_actual_room(game, playerx, playery, &actual_room_x1, &actual_room_x2, &actual_room_y1, &actual_room_y2);

        if (((is_in(actual_x, actual_room_x1, actual_room_x2) &&  is_in(actual_y, actual_room_y1, actual_room_y2)) || game->player.__vision ))
        {
            print_switch_room(game, get_value, i, j);
        } else {
            
            cprint(game->window.top, i, j, BASE_CRS_COLOR_BRIGHT_BLACK, "//");
        }
    } else {
        if (is_in_cone(game, actual_x, actual_y, playerx, playery, &room1_x1, &room1_x2, &room1_y1, &room1_y2, &room2_x1, &room2_x2, &room2_y1, &room2_y2))
        {
            print_switch_room(game, get_value, i, j);
        } else {
            if ((actual_x < playerx && actual_y < playery)||(actual_x > playerx && actual_y > playery))
            {   
                if ((is_in(actual_x, room1_x1, room1_x2) &&  is_in(actual_y, room1_y1, room1_y2) ) || (is_in(actual_x, room2_x1, room2_x2) &&  is_in(actual_y, room2_y1, room2_y2)))
                {
                    cprint(game->window.top, i, j, BASE_CRS_COLOR_BRIGHT_BLACK, "\\\\");
                } else
                {
                    cprint(game->window.top, i, j, BASE_CRS_COLOR_BRIGHT_BLACK, "//");
                }
                
                
                
            } else {
                cprint(game->window.top, i, j, BASE_CRS_COLOR_BRIGHT_BLACK, "//");
            }
            
            
        }
        
    }
}

/**
 * @brief Print the map on the screen.
 * 
 * @param game Pointer to the curent Game.
 */
void print_map(Game* game){
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
    
                
                case MAP_HEATH_CHARGE:
                case MAP_MONSTER:
                case MAP_ROOM:
                case MAP_TASK_REC:
                case MAP_TASK_FILL:
                case MAP_TASK_TEMPER:
                case MAP_TASK_AVOID:
                case MAP_TASK_DOWN:
                case MAP_TASK_CHOOSE:
                case MAP_TASK_UNDER:
                case MAP_MONSTER1:
                case MAP_MONSTER2:
                case MAP_MONSTER3:
                case MAP_MONSTER4:
                case MAP_HEATH_MEGA_CHARGE:
                case MAP_SONIC_VISION:
                case MAP_HEATH_OR_DIE:
                    print_in_shadow(game, get_value, playerx, playery, i, j, actual_x, actual_y);
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



/**
 * @brief Check if a position is valid for the player or not
 * 
 * @param self Pointer to the curent Game.
 * @param x The x coordinate of a position.
 * @param y The y coordinate of a position.
 * @return true if the position is valid.
 * @return false if not.
 */
boolean check_player_move(Game* self, int x, int y){
    int sizex = self->map.sizex(&self->map);
    int sizey = self->map.sizey(&self->map);
    if (x>=0 && x<sizex && y>=0 && y<sizey && self->map.get(&self->map, x, y)!=MAP_WALL) {
        return true;
    }
    return false;
}



/**
 * @brief This function handle the movement of the player by checking the future position 
 * 
 * @param self Pointer to the curent Game.
 */
int player_movement(Game* self){
    
            
    int x = self->player.get_x(&self->player);
    int y = self->player.get_y(&self->player);

    switch(self->window.get_key(&self->window)){
        case 'm':
        case 'M':
            return 0;
            break;
        case 'q':
        case 'Q':
        case KEY_LEFT:
            
            if(check_player_move(self, x-1, y)){
                self->player.set_x(&self->player,x-1);
            }
            
            break;
        case 'd':
        case 'D':
        case KEY_RIGHT:
            if(check_player_move(self, x+1, y)){
                self->player.set_x(&self->player,x+1);
            }
            break;
        case 'z' :
        case 'Z' :
        case KEY_UP:
            if(check_player_move(self, x, y-1)){
                self->player.set_y(&self->player,y-1);
            }
            break;
        case  's' :
        case  'S' :
        case KEY_DOWN:
            if(check_player_move(self, x, y+1)){
                self->player.set_y(&self->player,y+1);
            }
            break;
        case KEY_F(1):
        case '1':
            object_effect(self, self->player.__inventory[0]);
            self->player.use_object(&self->player, 0);
            break;
        case KEY_F(2):
        case '2':
            object_effect(self, self->player.__inventory[1]);
            self->player.use_object(&self->player, 1);
            break;
        case KEY_F(3):
        case '3':
            object_effect(self, self->player.__inventory[2]);
            self->player.use_object(&self->player, 2);
            break;
        case KEY_F(4):
        case '4':
            object_effect(self, self->player.__inventory[3]);
            self->player.use_object(&self->player, 3);
            break;
        case KEY_F(5):
        case '5':
            object_effect(self, self->player.__inventory[4]);
            self->player.use_object(&self->player, 4);
            break;
        case KEY_F(6):
        case '6':
            object_effect(self, self->player.__inventory[5]);
            self->player.use_object(&self->player, 5);
            break;
        case KEY_F(7):
        case '7':
            object_effect(self, self->player.__inventory[6]);
            self->player.use_object(&self->player, 6);
            break;
        case KEY_F(8):
        case '8':
            object_effect(self, self->player.__inventory[7]);
            self->player.use_object(&self->player, 7);
            break;
        default:
            break;
    }
    
    self->window.__key = 0;
    if(check_generation_update(self)){
        return -1;
    }
    return 1;
    //Toujours mettre le return apres check

}

/**
 * @brief Initializes the Game structure.
 *
 * @param self Pointer to self.
 */
void Game_init(Game* self){
    srand(201);
    log_reset();
    ARA_Window_init(&self->window, W_MODE_MULTIPLE);
    Map_init(&self->map, MAP_SIZE_X, MAP_SIZE_Y);
    Timer_init(&self->timer);
    Init_Player(&self->player);
    self->nb_room = 1;
    self->nb_gen_room = 1;
    self->nb_tasks = 0;
    self->nb_end_tasks = 0;
}
