/**
 * @file ARA_events.c
 * @author Ahmed A., Rayane M., Abdelwaheb A.
 * @brief Events and task; printing on the right and bottom window
 * @version 1.0
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ARA_events.h"


/**
 * @brief Displays the control instructions in the bottom window of the game.
 * @param game Pointer to the current game.
 */

void print_right_window(Game* game, int time_show){
    char bat[20][100] = {
                        "▄█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█▄",
                        "█                     █",
                        "█          ██         █",
                        "█         ██          █",
                        "█        ██           █",
                        "█       ▀▀▀█▄▄▄       █",
                        "█           ██        █",
                        "█          ██         █",
                        "█         ██          █",
                        "█                     █",
                        "▀█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▀"};

    cprint(game->window.right, 3, 1, BASE_CRS_COLOR_WHITE, "         █▀▀▀█");
    int y = 2;
    int x = 3;
    int health = game->player.get_life(&game->player);
    int filled_length = (health * 11) / 100;
    for (int i = 0; i < 11; i++)
    {   
        
        
        if (i > 11 - filled_length)
        {   
            if (i == 0)
            {   
                cprint(game->window.right, x, y, BASE_CRS_COLOR_WHITE, "▄");
                x++;
                cprint(game->window.right, x, y, FONT_CRS_COLOR_GREEN, "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█");
                x+=21;
                cprint(game->window.right, x, y, BASE_CRS_COLOR_WHITE, "▄");
                x = 3;
            } else if (i == 10){
                cprint(game->window.right, x, y, BASE_CRS_COLOR_WHITE, "▀");
                x++;
                cprint(game->window.right, x, y, FONT_CRS_COLOR_GREEN, "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█");
                x+=21;
                cprint(game->window.right, x, y, BASE_CRS_COLOR_WHITE, "▀");
                x = 3;
            }
            
            else {
                cprintf(game->window.right, 3, y, FONT_CRS_COLOR_GREEN,"%s", bat[i]);
            }
            
        } else {
            cprintf(game->window.right, 3, y, BASE_CRS_COLOR_WHITE, "%s",bat[i]);
        }
        
        
        y++;
    }
    if (time_show)
    {
        int time = 30 - mod(game->timer.get(&game->timer), 31);
        
        cprint(game->window.right, 3, y+1, BASE_CRS_COLOR_WHITE, "▄█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█▄");
        game->timer.update(&game->timer);
        cprintf(game->window.right, 7, y+2, BASE_CRS_COLOR_BRIGHT_RED, " Décharge : %d",time);
        cprint(game->window.right, 3, y+3, BASE_CRS_COLOR_WHITE, "▀█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▀");
    } else {
        game->timer.update(&game->timer);
        cprint(game->window.right, 3, y+1, BASE_CRS_COLOR_WHITE, "▄█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█▄");
        cprint(game->window.right, 7, y+2, BASE_CRS_COLOR_BRIGHT_RED, "TASK IN PROGRESS");
        cprint(game->window.right, 3, y+3, BASE_CRS_COLOR_WHITE, "▀█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▀");
    }
    
    

    cprint(game->window.right, 1, y+5, BASE_CRS_COLOR_WHITE, "          █▀▀▀▀▀█");
    cprint(game->window.right, 1, y+6, BASE_CRS_COLOR_WHITE, "          █  Z  █");
    cprint(game->window.right, 1, y+7, BASE_CRS_COLOR_WHITE, "          █▄▄▄▄▄█");
    cprint(game->window.right, 1, y+9, BASE_CRS_COLOR_WHITE, " █▀▀▀▀▀█  █▀▀▀▀▀█  █▀▀▀▀▀█");
    cprint(game->window.right, 1, y+10, BASE_CRS_COLOR_WHITE, " █  Q  █  █  S  █  █  D  █");
    cprint(game->window.right, 1, y+11, BASE_CRS_COLOR_WHITE, " █▄▄▄▄▄█  █▄▄▄▄▄█  █▄▄▄▄▄█");
    cprint(game->window.right, 1, y+13, BASE_CRS_COLOR_WHITE, " █▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█");
    cprint(game->window.right, 1, y+14, BASE_CRS_COLOR_WHITE, " █ █▄▄▄▄▄▄▄TASKS▄▄▄▄▄▄▄█ █ ");
    cprint(game->window.right, 1, y+15, BASE_CRS_COLOR_WHITE, " █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█");
    cprint(game->window.right, 1, y+17, BASE_CRS_COLOR_WHITE, " █▀ M ▀█▄▄▄▄▄▄MENU▄▄▄▄▄▄▄▄");
    cprint(game->window.right, 1, y+18, BASE_CRS_COLOR_WHITE, " █▄▄▄▄▄█                 ▀");







}

/**
 * @brief Displays the inventory of the player
 * 
 * @param game The current game
 */
void print_bottom_window(Game *game){
    Player player = game->player;
    int base_x = 4;
    int x = base_x;
    int y = 1;
    int base_i = 0;
    for (int j = 0; j < 2; j++)
    {
        for (int i = base_i; i < MAX_INVENTORY/2 + base_i; i++)
        {   

            cprintf(game->window.bottom, x, y, BASE_CRS_COLOR_WHITE, "█▀F%d|%d ▀█ ",i+1,i+1);
            x+=10;
        }
        x = base_x;
        y++;
        for (int i = base_i; i < MAX_INVENTORY/2 + base_i; i++)
        {   
            switch (player.__inventory[i])
            {
            case MAP_HEATH_CHARGE:
                cprint(game->window.bottom, x, y, BASE_CRS_COLOR_WHITE, "█ 🔋    █ ");
                break;
            case MAP_SONIC_VISION:
                cprint(game->window.bottom, x, y, BASE_CRS_COLOR_WHITE, "█ 🔮    █ ");
                break;
            case MAP_HEATH_MEGA_CHARGE:
                cprint(game->window.bottom, x, y, BASE_CRS_COLOR_WHITE, "█ ⚡    █ ");
                break;
            case MAP_HEATH_OR_DIE:
                cprint(game->window.bottom, x, y, BASE_CRS_COLOR_WHITE, "█ 🧪    █ ");
                break;
            default:
                cprint(game->window.bottom, x, y, BASE_CRS_COLOR_WHITE, "█ []    █ ");
                break;
            }
            x+=10;
        }
        x = base_x;
        y++;
        for (int i = base_i; i < MAX_INVENTORY/2 + base_i; i++)
        {   
            cprintf(game->window.bottom, x, y, BASE_CRS_COLOR_WHITE, "█   x%02d █ ",player.__inventory_count[i]);
            x+=10;
        }
        x = base_x;
        y++;
        for (int i = base_i; i < MAX_INVENTORY/2 + base_i; i++)
        {   
            cprint(game->window.bottom, x, y, BASE_CRS_COLOR_WHITE, "█▄▄▄▄▄▄▄█ ");
            x+=10;
        }
        x = base_x;
        y+= 2;
        base_i += MAX_INVENTORY/2;
    }
        cprint(game->window.bottom, 45, 4, BASE_CRS_COLOR_WHITE, "█▀▀▀▀▀▀▀█ ");
        cprintf(game->window.bottom, 46, 5, BASE_CRS_COLOR_WHITE, "xp : %d",player.__xp);
        cprint(game->window.bottom, 45, 6, BASE_CRS_COLOR_WHITE, "█▄▄▄▄▄▄▄█ ");
    
}

/**
 * @brief Displays a task with a border made of emoji characters.
 *
 * This function draws a rectangular border using emoji characters.
 * 
 * @param game Pointer to the current game.
 */
void task_pop_up(Game *game, char * mission, char * emoji, int* x1, int* y1, int* x2, int* y2){
    int y=0;
    int x=0;
    *x1=(NB_COLS / 3)-22;
    *y1=(NB_LINES / 3)-7;
    *x2=(NB_COLS / 3)+23;
    *y2=(NB_LINES / 3)+7;
    //Il faut que x1 soit egale a (NB_COLS / 3)-k avec k pair comme ca ca ne bug pas avec l'affichage d une emote sur une autre
    char message[100];
    for(y=*y1; y<*y2; y++){
        for(x=*x1; x<*x2; x+=2){
            if(y==*y1 || y==*y2-1 || x==*x1 || x==*x2-1){
                snprintf(message, sizeof(message), "%s",emoji);
                mvwaddstr(game->window.top,y,x,message);
            }
            else{
                mvwaddstr(game->window.top,y,x,"  ");
            }
            
        }
    }
    //Comme mvwaddstr ne prend que 4 parametres je ne peux pas faire (....,"%s",mission) c est pour ca que snprintf formate ma chaine pour etre utilisee sans "%s"
    snprintf(message, sizeof(message), "%s",mission);
    mvwaddstr(game->window.top,*y1+1,*x1+(*x2-*x1)/2 - strlen(message)/2 +1,message);
}

/**
 * @brief Displays all the windows and the state of the timer
 * 
 * @param game The current game
 * @param timeout The time left
 * @param show_right_time The state of the timer(if it must be shown or not)
 */
void re_print_all(Game *game, int timeout, int show_right_time){
    game->window.clear_all(&game->window);
    game->window.create(&game->window);
    wtimeout(game->window.main_window,timeout);
    print_bottom_window(game);
    print_right_window(game, show_right_time);
    print_map(game);
}

/**
 * @brief Task of recalibrating the vessel
 * Tap SPACE when the cursor in on the red range
 * @param game The current game
 */
void task_recalibrate(Game *game){
    int x1, x2, y1, y2;
    int bar_x;
    int input = 0;
    int fail = -1;
    Direction dir = D_WEST;
    re_print_all(game, TASK_TIMOUT, false);
    task_pop_up(game, "Recalibrer le vaisssaux", "⚙ ", &x1, &y1, &x2, &y2);
    bar_x = x1+5;
    do
    {   
        re_print_all(game, TASK_TIMOUT/4, false);
        task_pop_up(game, "Recalibrer le vaisssaux", "⚙ ", &x1, &y1, &x2, &y2);
        if (dir == D_WEST)
        {
            bar_x++;
        } else {
            bar_x --;
        }
        if (bar_x >= x2-1)
        {
            dir = D_EAST;
        } 
        if (bar_x <= x1+1) {
            dir = D_WEST;
        }
    
        for (int y = y1+4; y < y2-3; y++)
        {
            for (int x = x1+2; x < x2-1; x++)
            {   
                if ( is_in(x, x1 + (x2-x1)/2 - 2, x1 + (x2-x1)/2 + 2))
                {   
                    if (bar_x == x)
                    {
                        cprintadd(game->window.top, x ,y ,FONT_CRS_COLOR_BRIGHT_RED,"█");
                    } else {
                        cprintadd(game->window.top, x ,y ,FONT_CRS_COLOR_BRIGHT_RED," ");
                    }
                    
                    
                } else if ( is_in(x, x1 + (x2-x1)/2 - 6, x1 + (x2-x1)/2 + 6 )){
                    if (bar_x == x)
                    {
                        cprintadd(game->window.top, x ,y ,FONT_CRS_COLOR_BRIGHT_YELLOW,"█");
                    } else {
                        cprintadd(game->window.top, x ,y ,FONT_CRS_COLOR_BRIGHT_YELLOW," ");
                    }
        
                } else {
                    if (bar_x == x)
                    {
                        cprintadd(game->window.top, x ,y ,FONT_CRS_COLOR_BRIGHT_GREEN,"█");
                    } else {
                        cprintadd(game->window.top, x ,y ,FONT_CRS_COLOR_BRIGHT_GREEN," ");
                    }
                }
                
                
            }
        }
        game->window.update_key(&game->window);
        input = game->window.get_key(&game->window);
        if (is_in(bar_x, x1 + (x2-x1)/2 - 2, x1 + (x2-x1)/2 + 2) && input == ' ')
        {
            fail = 0;
            game->player.__xp++;
        } else if (input == ' ') {
            re_print_all(game, TASK_TIMOUT, false);
            task_pop_up(game, "Recalibrer le vaisssaux", "⚙ ", &x1, &y1, &x2, &y2);
            bar_x = x1+1;
            input = 0;
            dir = D_WEST;
            for (int y = y1+4; y < y2-3; y++)
        {
            for (int x = x1+2; x < x2-1; x++){   
                if ( is_in(x, x1 + (x2-x1)/2 - 2, x1 + (x2-x1)/2 + 2)){   
                    cprintadd(game->window.top, x ,y ,FONT_CRS_COLOR_BRIGHT_RED," ");
                } else if ( is_in(x, x1 + (x2-x1)/2 - 6, x1 + (x2-x1)/2 + 6 )){
                    cprintadd(game->window.top, x ,y ,FONT_CRS_COLOR_BRIGHT_YELLOW," ");
                } else {
                    cprintadd(game->window.top, x ,y ,FONT_CRS_COLOR_BRIGHT_GREEN," ");
                    }
                }
            }
            game->player.set_life(&game->player, game->player.get_life(&game->player) - 10);
            cprintadd(game->window.top,x1+11,y1+5,BASE_CRS_COLOR_WHITE,"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█");
            cprintadd(game->window.top,x1+11,y1+6,BASE_CRS_COLOR_WHITE,"█  █▀▀▀  █▀▀█ ▀█▀  █    █");
            cprintadd(game->window.top,x1+11,y1+7,BASE_CRS_COLOR_WHITE,"█  █▀▀▀  █▄▄█  █   █    █");
            cprintadd(game->window.top,x1+11,y1+8,BASE_CRS_COLOR_WHITE,"█  █     █  █ ▄█▄  █▄▄█ █");
            cprintadd(game->window.top,x1+11,y1+9,BASE_CRS_COLOR_WHITE,"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█");
            wtimeout(game->window.main_window, MAIN_TIMEOUT);
            game->window.update_key(&game->window);
            input = game->window.get_key(&game->window);
        }   
    } while (fail != 0);
    game->nb_end_tasks++;


}

/**
 * @brief Task of downloading the DATA
 * Keep pressing SPACE button to finish the downloading
 * @param game The current game
 */
void task_download(Game *game){
    int x1, x2, y1, y2;
    int input = 0;
    int fail = -1;
    re_print_all(game, TASK_TIMOUT, false);
    task_pop_up(game, "Download DATA", "🌐", &x1, &y1, &x2, &y2);
    
    int start_x1 = x1+5;
    int start_x2 = x2-5;
    int start_y1 = y1+10;
    int start_y2 = y1+13;
    int color;
    int progress = start_x1+1;
    do
    {   
        re_print_all(game, TASK_TIMOUT/4, false);
        task_pop_up(game, "Download DATA", "🌐", &x1, &y1, &x2, &y2);
        cprintadd(game->window.top,x1+13,y1+2,BASE_CRS_COLOR_WHITE,"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█");
        cprintadd(game->window.top,x1+13,y1+3,BASE_CRS_COLOR_WHITE,"█        █        █");
        cprintadd(game->window.top,x1+13,y1+4,BASE_CRS_COLOR_WHITE,"█   ▀▄   █   ▄▀   █");
        cprintadd(game->window.top,x1+13,y1+5,BASE_CRS_COLOR_WHITE,"█     ▀▄ █ ▄▀     █");
        cprintadd(game->window.top,x1+13,y1+6,BASE_CRS_COLOR_WHITE,"█ █     ▀█▀     █ █");
        cprintadd(game->window.top,x1+13,y1+7,BASE_CRS_COLOR_WHITE,"█ █▄▄▄▄▄▄▄▄▄▄▄▄▄█ █");
        cprintadd(game->window.top,x1+13,y1+8,BASE_CRS_COLOR_WHITE,"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█");

        for (int y = start_y1; y < start_y2; y++)
        {
            for (int x = start_x1; x < start_x2; x++)
            {   
                color = (x < progress) ? FONT_CRS_COLOR_GREEN : BASE_CRS_COLOR_WHITE;

                if (x == start_x1 || x == start_x2-1 || ( (y == start_y1 || y == start_y2-1) && (x == start_x1+1 || x == start_x2-2) ))
                {
                    cprintadd(game->window.top,x,y,color,"█");
                } else if (y==start_y1){
                    cprintadd(game->window.top,x,y,color,"▀");
                } else if (y==start_y2-1){
                    cprintadd(game->window.top,x,y,color,"▄");
                } else {
                    cprintadd(game->window.top,x,y,color," ");
                }
                
            }
        }
        game->window.update_key(&game->window);
        input = game->window.get_key(&game->window);
        if (input == ' ')
        {
            progress ++;
        }
        if (progress >= start_x2-1){
            fail = 0;
        }
    
    }while (fail != 0);
    game->nb_end_tasks++;
          
}

/**
 * @brief Task of finding the suspect 
 * Find the emoji that is different from the others
 * @param game The current game
 */
void task_choose(Game *game){
    int x1, x2, y1, y2;
    int input = 0;
    int fail = -1;
    re_print_all(game, TASK_TIMOUT, false);
    task_pop_up(game, "Find the sus DNA", "🧫", &x1, &y1, &x2, &y2);
    
    int start_x1 = x1+5;
    int start_x2 = x2-4;
    int start_y1 = y1+4;
    int start_y2 = y2-1;
    int color;
    int playerx = start_x1+2;
    int playery = start_y1;
    int rand_x,rand_y;
    rand_x = randint(start_x1+2  , start_x2-3);
    rand_x += rand_x%2;
    rand_y = randint(start_y1+1  , start_y2 -3);
    int rand_emoji = randint(0,5);
    do
    {   
        re_print_all(game, TASK_TIMOUT/4, false);
        task_pop_up(game, "Find the sus DNA", "🧫", &x1, &y1, &x2, &y2);
        
        for (int y = start_y1; y < start_y2-1; y++)
        {
            for (int x = start_x1; x < start_x2; x+=2)
            {   
                color = (playerx == x && playery == y) ? FONT_CRS_COLOR_GREEN : BASE_CRS_COLOR_WHITE;

                if (is_in(x, start_x1+2  , start_x2-2 ) && is_in(y, start_y1  , start_y2 -2)){
                    switch (rand_emoji)
                    {
                    case 0:
                        if (x == rand_x && y== rand_y)
                        { 
                            cprintadd(game->window.top,x,y,color,"😄");
                        } else {
                            cprintadd(game->window.top,x,y,color,"😃");
                        }
                        break;
                    case 1:
                        if (x == rand_x && y== rand_y)
                        { 
                            cprintadd(game->window.top,x,y,color,"🕦");
                        } else {
                            cprintadd(game->window.top,x,y,color,"🕖");
                        }
                        break;
                    case 2:
                        if (x == rand_x && y== rand_y)
                        { 
                            cprintadd(game->window.top,x,y,color,"🔈");
                        } else {
                            cprintadd(game->window.top,x,y,color,"🔉");
                        }
                        break;
                    case 3:
                        if (x == rand_x && y== rand_y)
                        { 
                            cprintadd(game->window.top,x,y,color,"🔘");
                        } else {
                            cprintadd(game->window.top,x,y,color,"⚪ ");
                        }
                        break;
                    case 4:
                        if (x == rand_x && y== rand_y)
                        { 
                            cprintadd(game->window.top,x,y,color,"‼ ");
                        } else {
                            cprintadd(game->window.top,x,y,color,"⁉ ");
                        }
                        break;
                    
                    default:
                        break;
                    }
                    
                    
                } else  {
                    cprintadd(game->window.top,x,y,color,"  ");
                }
                
            }
        }
        game->window.update_key(&game->window);
        input = game->window.get_key(&game->window);

        if (input == ' ' && playerx == rand_x && playery == rand_y)
        {   
            game->player.__xp+=5;
            fail = 0;
        } else if (input == ' '){
            
            re_print_all(game, 1, false);
            task_pop_up(game, "Find the sus DNA", "🧫", &x1, &y1, &x2, &y2);
            game->player.set_life(&game->player, game->player.get_life(&game->player) - 10);
            cprintadd(game->window.top,x1+11,y1+5,BASE_CRS_COLOR_WHITE,"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█");
            cprintadd(game->window.top,x1+11,y1+6,BASE_CRS_COLOR_WHITE,"█  █▀▀▀  █▀▀█ ▀█▀  █    █");
            cprintadd(game->window.top,x1+11,y1+7,BASE_CRS_COLOR_WHITE,"█  █▀▀▀  █▄▄█  █   █    █");
            cprintadd(game->window.top,x1+11,y1+8,BASE_CRS_COLOR_WHITE,"█  █     █  █ ▄█▄  █▄▄█ █");
            cprintadd(game->window.top,x1+11,y1+9,BASE_CRS_COLOR_WHITE,"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█");
            wtimeout(game->window.main_window, MAIN_TIMEOUT);
            game->window.update_key(&game->window);
            input = game->window.get_key(&game->window);
        }
        switch (input)
        {
        case 'z':
            playery--;
            playery = stick_in_range(playery, start_y1  , start_y2 -2);
            break;
        case 's':
            playery++;
            playery = stick_in_range(playery, start_y1  , start_y2 -2);
            break;
        case 'q':
            playerx-=2;
            playerx = stick_in_range(playerx, start_x1+2  , start_x2-2 );
            break;
        case 'd':
            playerx+=2;
            playerx = stick_in_range(playerx, start_x1+2  , start_x2-2 );
            break;
        default:
            break;
        }
    
    }while (fail != 0);
    game->nb_end_tasks++;
}

/**
 * @brief Task of avoiding the bar
 * Move (z,s) in order to avoid being touched by the bar
 * @param game The current game
 */
void task_undertale(Game *game){
    int x1, x2, y1, y2;
    int input = 0;
    int fail = -1;
    re_print_all(game, TASK_TIMOUT, false);
    task_pop_up(game, "Human..it was nice to meet you", "☠ ", &x1, &y1, &x2, &y2);
    int nb_r = 0;
    int start_x1 = x1+5;
    int start_x2 = x2-4;
    int start_y1 = y1+4;
    int start_y2 = y2-1;
    int color;
    int playerx = start_x1+2;
    int playery = start_y1;
    int rand_y;
    struct timespec current;
    long actual = 0 , final= 0, compteur=0;
    rand_y = playery + 2;
    int charge = false;
    do
    {   
        
        re_print_all(game, 50, false);
        task_pop_up(game, "do you wanna have a bad time?", "☠ ", &x1, &y1, &x2, &y2);
        compteur += final - actual;
        if(compteur<0){
            compteur=0;
        }
        if(compteur>600){
            compteur-=600;
            if (!charge)
            {   
                rand_y = playery + randint(0  , 2) - randint(0  , 2);
                charge = true;
                nb_r++;
            } else {
                charge = false;
            }
        }
        
        
        
        for (int y = start_y1; y < start_y2-1; y++)
        {
            for (int x = start_x1; x < start_x2; x+=2)
            {   
                if (y == rand_y)
                {
                    color = (charge) ? FONT_CRS_COLOR_BRIGHT_YELLOW : FONT_CRS_COLOR_BRIGHT_RED;
                } else {
                    color = BASE_CRS_COLOR_WHITE;
                }
                
                if (is_in(x, start_x1+2  , start_x2-2 ) && is_in(y, start_y1  , start_y2 -2)){
                    
                    if (playerx == x && playery == y)
                    {
                        cprintadd(game->window.top,x,y,color,"💙");
                    } else {
                        cprintadd(game->window.top,x,y,color,"  ");
                    }
                    
                    
                    
                } else  {
                    cprintadd(game->window.top,x,y,color,"  ");
                }
                
            }
        }
        
        clock_gettime(CLOCK_REALTIME ,&current);
        actual=current.tv_sec*1000+current.tv_nsec/1000000;
        //Ca transforme tout en millisecondes
        game->window.update_key(&game->window);
        input = game->window.get_key(&game->window);
        clock_gettime(CLOCK_REALTIME,&current);
        final=current.tv_sec*1000+current.tv_nsec/1000000;

        if (!charge &&  playery == rand_y){
            charge = false;
            nb_r = 0;
            rand_y = playery + randint(0  , 2) - randint(0  , 2);
            re_print_all(game, 1, false);
            task_pop_up(game, "do you wanna have a bad time?", "☠ ", &x1, &y1, &x2, &y2);
            game->player.set_life(&game->player, game->player.get_life(&game->player) - 10);
            cprintadd(game->window.top,x1+11,y1+5,BASE_CRS_COLOR_WHITE,"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█");
            cprintadd(game->window.top,x1+11,y1+6,BASE_CRS_COLOR_WHITE,"█  █▀▀▀  █▀▀█ ▀█▀  █    █");
            cprintadd(game->window.top,x1+11,y1+7,BASE_CRS_COLOR_WHITE,"█  █▀▀▀  █▄▄█  █   █    █");
            cprintadd(game->window.top,x1+11,y1+8,BASE_CRS_COLOR_WHITE,"█  █     █  █ ▄█▄  █▄▄█ █");
            cprintadd(game->window.top,x1+11,y1+9,BASE_CRS_COLOR_WHITE,"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█");
            wtimeout(game->window.main_window, MAIN_TIMEOUT);
            game->window.update_key(&game->window);
            input = game->window.get_key(&game->window);
        }
        switch (input)
        {
        case 'z':
            playery--;
            playery = stick_in_range(playery, start_y1  , start_y2 -2);
            break;
        case 's':
            playery++;
            playery = stick_in_range(playery, start_y1  , start_y2 -2);
            break;
        case 'q':
            playerx-=2;
            playerx = stick_in_range(playerx, start_x1+2  , start_x2-2 );
            break;
        case 'd':
            playerx+=2;
            playerx = stick_in_range(playerx, start_x1+2  , start_x2-2 );
            break;
        default:
            break;
        }
    
    }while (fail != 0 && nb_r < 10 );
    game->player.__xp+=5;
    game->nb_end_tasks++;
          
}

/**
 * @brief Task of filling a tank
 * Spam the SPACE button to fill the tank
 * @param game The current game
 */
void task_fill(Game *game){
    int x1, x2, y1, y2, posx1, posy1, count=0, col=0, nbr=2;
    // nbr c'est le nombre d espaces qu on doit effectuer pour afficher toute une ligne jaune
    struct timespec current;
    //C est pour avoir un temps en millisecondes
    long actual=0,final=0;
    //Pour stocker le tres grand nombre de millisecondes
    char carvalue=0;
    char barrel[12][100] = {
                        "            ████",
                        "█▀▀▀█▀▀▀▀▀▀▀█▀▀▀▀█",
                        "█   █▄▄▄▄▄▄▄█    █",
                        "█  ▄          ▄  █",
                        "█   ▀▄      ▄▀   █",
                        "█     ▀▄  ▄▀     █",
                        "█       ██       █",
                        "█     ▄▀  ▀▄     █",
                        "█   ▄▀      ▀▄   █",
                        "█  ▀          ▀  █",
                        "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█"};
    do{
        re_print_all(game, TASK_TIMOUT, false);
        task_pop_up(game, "Remplir le reservoir", "🕸 ", &x1, &y1, &x2, &y2);
        posy1=y1+2;
        posx1=x1+13;
        //Ici je dessine le conteneur
        for(int k=0;k<11;k++){
            col=BASE_CRS_COLOR_BRIGHT_RED;
            if(count>(k+1)*nbr){
                col=SPECIAL_CRS_COLOR_RED_YELLOW;
            }
            cprintadd(game->window.top,posx1,posy1+10-k,col,barrel[10-k]);
        }

        game->window.update(&game->window);
        clock_gettime(CLOCK_REALTIME ,&current);
        actual=current.tv_sec*1000+current.tv_nsec/1000000;
        //Ca transforme tout en millisecondes
        game->window.update_key(&game->window);
        carvalue=game->window.get_key(&game->window);
        clock_gettime(CLOCK_REALTIME,&current);
        final=current.tv_sec*1000+current.tv_nsec/1000000;
        //Comme ca avec la difference on regarde en combien de temps le joueur a tape une touche pour eviter que le joueur reste appuye sur une touche
        if(carvalue!=' ' || final-actual<50){
            if(count>0){
                count--;
            }//Comme ca on descend pas en dessous de 0
        }
        else{
            count++;
        }
    }while(count<11*nbr);
    game->player.__xp+=1;
    game->nb_end_tasks++;
}

/**
 * @brief Choose one of the tasks to pop on the map
 * 
 * @param game The current game
 * @param value The task that is choosen
 */
void task(Game *game, int value){
    switch (value)
    {
    case MAP_TASK_REC:
        task_recalibrate(game);
        break;
    case MAP_TASK_FILL:
        task_fill(game);
        break;
    case MAP_TASK_TEMPER:
        task_temperature(game);
        break;
    case MAP_TASK_AVOID:
        task_avoid(game);
        break;
    case MAP_TASK_DOWN:
        task_download(game);
        break;
    case MAP_TASK_CHOOSE:
        task_choose(game);
        break;
    case MAP_TASK_UNDER:
        task_undertale(game);
        break;
    
    default:
        break;
    }
}

/**
 * @brief Task of regulating the vessel's temperature
 * Increase or decrease(z,s) the left number in order to be equal to the right one
 * @param game The current game
 */
void task_temperature(Game *game){
    int x1,x2,y1,y2,col=0;
    int correct=0,essay=0;
    char carvalue=0;
    char message[20];
    do{
        correct=randint(1,401)-200;
        essay=randint(1,401)-200;
        carvalue=0;
        do{
            re_print_all(game,MAIN_TIMEOUT,false);
            task_pop_up(game,"Regulate temperature","🔥",&x1,&y1,&x2,&y2);
            cprintadd(game->window.top,(x1+x2)/2-7,y1+4,BASE_CRS_COLOR_WHITE,"🔼");
            sprintf(message, "%d",essay);
            cprintadd(game->window.top,(x1+x2)/2-9,y1+5,BASE_CRS_COLOR_WHITE,"█▀▀▀▀▀█");
            cprintadd(game->window.top,(x1+x2)/2-9,y1+6,BASE_CRS_COLOR_WHITE,"█     █");
            cprintadd(game->window.top,(x1+x2)/2-9,y1+7,BASE_CRS_COLOR_WHITE,"█▄▄▄▄▄█");
            cprintadd(game->window.top,(x1+x2)/2-7,y1+8,BASE_CRS_COLOR_WHITE,"🔽");
            col=BASE_CRS_COLOR_BRIGHT_RED;
            if(essay<=0){
                col=BASE_CRS_COLOR_BRIGHT_BLUE;
            }
            cprintadd(game->window.top,(x1+x2)/2-7,y1+6,col,message);
            sprintf(message, "%d",correct);
            cprintadd(game->window.top,(x1+x2)/2+5,y1+5,BASE_CRS_COLOR_WHITE,"█▀▀▀▀▀█");
            cprintadd(game->window.top,(x1+x2)/2+5,y1+6,BASE_CRS_COLOR_WHITE,"█     █");
            cprintadd(game->window.top,(x1+x2)/2+5,y1+7,BASE_CRS_COLOR_WHITE,"█▄▄▄▄▄█");
            col=BASE_CRS_COLOR_BRIGHT_RED;
            if(correct<=0){
                col=BASE_CRS_COLOR_BRIGHT_BLUE;
            }
            cprintadd(game->window.top,(x1+x2)/2+7,y1+6,col,message);
            game->window.update(&game->window);

            game->window.update_key(&game->window);
            carvalue = game->window.get_key(&game->window);
            if(carvalue=='s' && essay>-202){
                essay--;
            }
            else if(carvalue=='z' && essay<202){
                essay++;
            }
            else if(carvalue==' ' && essay==correct){
                return;
            }
            else if(carvalue==' ' && essay!=correct){
                break;
            }
            
        }while(1);
        re_print_all(game,MAIN_TIMEOUT,false);
        task_pop_up(game,"Regulate temperature","🔥",&x1,&y1,&x2,&y2);
        cprintadd(game->window.top,x1+11,y1+5,BASE_CRS_COLOR_WHITE,"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█");
        cprintadd(game->window.top,x1+11,y1+6,BASE_CRS_COLOR_WHITE,"█  █▀▀▀  █▀▀█ ▀█▀  █    █");
        cprintadd(game->window.top,x1+11,y1+7,BASE_CRS_COLOR_WHITE,"█  █▀▀▀  █▄▄█  █   █    █");
        cprintadd(game->window.top,x1+11,y1+8,BASE_CRS_COLOR_WHITE,"█  █     █  █ ▄█▄  █▄▄█ █");
        cprintadd(game->window.top,x1+11,y1+9,BASE_CRS_COLOR_WHITE,"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█");
        wtimeout(game->window.main_window, MAIN_TIMEOUT);
        game->window.update_key(&game->window);
        carvalue = game->window.get_key(&game->window);
    }while(1);
    game->player.__xp+=1;
    game->nb_end_tasks++;
}
/**
 * @brief Task of avoiding meteorites
 * 
 * @param game The current game
 */
void task_avoid(Game *game){
    int xplayer,yplayer,posx1,posx2,posy1,posy2,retu=1;
    char carvalue=0;
    int lines[AVOID]={0},cols[AVOID]={0};
    struct timespec current;
    long actual=0,final=0;
    int compteur=0;
    do{
        retu=1;
        compteur=0;
        re_print_all(game, 1, false);
        task_pop_up(game, "Evitez les meteorites", "🏮", &posx1, &posy1, &posx2, &posy2);
        xplayer=(posx1+posx2)/2;
        yplayer=posy2-3;
        for(int k=0;k<AVOID/4;k++){
            for(int i=0;i<AVOID;i++){
                do{
                    cols[i]=randint(posx1+1,posx2-1);
                }while(cols[i]%2==0);
                lines[i]=posy1+2;
            }
            while(lines[0]<posy2-2){
                compteur+=final-actual;
                if(compteur<0){
                    compteur=0;
                }
                if(compteur>200){
                    compteur-=200;
                    for(int i=0;i<AVOID;i++){
                        lines[i]+=1;
                    }
                }
                clock_gettime(CLOCK_REALTIME,&current);
                actual=current.tv_sec*1000+current.tv_nsec/1000000;
                re_print_all(game, 50, false);
                task_pop_up(game, "Evitez les meteorites", "🏮", &posx1, &posy1, &posx2, &posy2);
                mvwaddstr(game->window.top,yplayer,xplayer,"🤖");
                for(int i=0;i<AVOID;i++){
                    if(lines[i]==yplayer && cols[i]==xplayer){
                        mvwaddstr(game->window.top,lines[i],cols[i],"💥");   
                    }
                    else{
                        mvwaddstr(game->window.top,lines[i],cols[i],"🌑");
                    }
                }
            
                game->window.update_key(&game->window);
                carvalue=game->window.get_key(&game->window);
                if(carvalue=='q' && xplayer>posx1+3){
                    xplayer-=2;
                }
                else if(carvalue=='d' && xplayer<posx2-3){
                    xplayer+=2;
                }
                clock_gettime(CLOCK_REALTIME,&current);
                final=current.tv_sec*1000+current.tv_nsec/1000000;
                for(int i=0;i<AVOID;i++){
                    if(cols[i]==xplayer && lines[i]==yplayer){
                        retu=0;
                        break;
                    }
                }
                if(retu==0){break;}
            }
            if(retu==0){break;}
        }
        if(retu==1){
            return;
        }
        re_print_all(game, 1, false);
        task_pop_up(game, "Evitez les meteorites", "🏮", &posx1, &posy1, &posx2, &posy2);
        game->player.set_life(&game->player, game->player.get_life(&game->player) - 10);
        cprintadd(game->window.top,posx1+11,posy1+5,BASE_CRS_COLOR_WHITE,"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█");
        cprintadd(game->window.top,posx1+11,posy1+6,BASE_CRS_COLOR_WHITE,"█  █▀▀▀  █▀▀█ ▀█▀  █    █");
        cprintadd(game->window.top,posx1+11,posy1+7,BASE_CRS_COLOR_WHITE,"█  █▀▀▀  █▄▄█  █   █    █");
        cprintadd(game->window.top,posx1+11,posy1+8,BASE_CRS_COLOR_WHITE,"█  █     █  █ ▄█▄  █▄▄█ █");
        cprintadd(game->window.top,posx1+11,posy1+9,BASE_CRS_COLOR_WHITE,"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█");
        wtimeout(game->window.main_window, MAIN_TIMEOUT);
        game->window.update_key(&game->window);
        carvalue = game->window.get_key(&game->window);
    }while(retu==0);
    game->player.__xp+=5;
    game->nb_end_tasks++;
}

/**
 * @brief Print the arena of the QTE game between the player and the monster
 * 
 * @param game Pointer to the Game structure containing game state and window information.
 * @param car The player input caracter
 */
void print_arena(Game *game, char car, int monster){
    int y=0,x=0,y1=(NB_LINES / 3)-5,y2=(NB_LINES / 3)+5,x1=(NB_COLS / 3)-22,x2=(NB_COLS / 3)+23;
    //Il faut que x1 soit egale a (NB_COLS / 3)-k avec k pair comme ca ca ne bug pas avec l'affichage d une emote sur une autre
    char fight[]="C'est l'heure du du-du-du-du-duel";
    char message[100];
    for(y=y1;y<y2;y++){
        for(x=x1;x<x2;x+=2){
            if(y==y1 || y==y2-1 || x==x1 || x==x2-1){
                snprintf(message, sizeof(message), "⚔ ");
            }
            else{
                snprintf(message, sizeof(message), "  ");
            }
            mvwaddstr(game->window.top,y,x,message);
        }
    }
    snprintf(message, sizeof(message), "%s",fight);
    //Comme mvwaddstr ne prend que 4 parametres je ne peux pas faire (....,"%s",mission) c est pour ca que snprintf formate ma chaine pour etre utilisee sans "%s"
    mvwaddstr(game->window.top,y1+1,x1+6,message);
    snprintf(message, sizeof(message), "🤖");
    mvwaddstr(game->window.top,y2-3,x1+3,message);
    switch (monster)
    {
    case MAP_MONSTER:
        snprintf(message, sizeof(message), "👾");
        mvwaddstr(game->window.top,y1+3,x2-4,message);
        break;
    case MAP_MONSTER1:
        snprintf(message, sizeof(message), "🕷");
        mvwaddstr(game->window.top,y1+3,x2-4,message);
        break;
    case MAP_MONSTER2:
        snprintf(message, sizeof(message), "👽");
        mvwaddstr(game->window.top,y1+3,x2-4,message);
        break;
    case MAP_MONSTER3:
        snprintf(message, sizeof(message), "🐙");
        mvwaddstr(game->window.top,y1+3,x2-4,message);
        break;
    case MAP_MONSTER4:
        snprintf(message, sizeof(message), "🛸");
        mvwaddstr(game->window.top,y1+3,x2-4,message);
        break;
    
    default:
        break;
    }
    
    if(car>=0){
        print_alphabet(game,car,(y1+y2)/2,(x1+x2)/2);
    }
    else{
        //Si car<0 c est un signal qui montre que je suis dans l'etape ou j attends que l'utilisateur tape espace
        print_alphabet(game,' ',(y1+y2)/2,(x1+x2)/2);
    }
    //A regarder le premier printArena dans le premier do while dans QTE pour comprendre pq je fais if car>0 
}

/**
 * @brief Executes a Quick Time Event (QTE) in the game.
 *
 * This function runs a QTE where the player must type random characters displayed on the screen 
 * within a certain time limit. If the player types the correct characters in the time limit, 
 * they pass the QTE; otherwise, they fail.
 *
 * @param game Pointer to the Game structure containing game state and window information.
 * @return true if the QTE is successfully completed.
 * @return false if not.
 */
int QTE(Game *game, int monster){
    char carvalue=0,car=0;
    int i=0;
    //Le premier do while c est en attendant que le joueur tape espace
    do{
        re_print_all(game, MAIN_TIMEOUT, false);
        print_arena(game,-1, monster );
        game->window.update(&game->window);
        game->window.update_key(&game->window);
    }while(game->window.get_key(&game->window)!=' ');
    //Là le joueur a tape espace et il commence a vraiment jouer le QTE
    for(i=0;i<6;i++){
        carvalue=randint('a','z'+1);
        re_print_all(game, MAIN_TIMEOUT*2, false);
        print_arena(game,carvalue, monster);          
        game->window.update(&game->window);
        game->window.update_key(&game->window);
        car=game->window.get_key(&game->window);
        if((car!=carvalue)||(car==ERR)){
            //Si le joueur perd on detruit tout
            //game->window.destroy();
            //game->map.destroy(&game->map);
            game->player.set_x(&game->player,MAP_SIZE_X/2);
            game->player.set_y(&game->player,MAP_SIZE_Y/2);
            return 0;
        }
    }
    //Si le programme arrive ici ca veut dire que le joueur a reussi de gagner au QTE
    game->map.set(&game->map,game->player.get_x(&game->player),game->player.get_y(&game->player),MAP_ROOM);
    //Je mets du vide a la place du monstre
    return 1;
}

/**
 * @brief Gives the direction of the monster to get next to the player
 * 
 * @param game The current game
 * @param xmonster The x of the monster to move
 * @param ymonster the y of the monster to move
 */
void movementMonster(Game *game, int xmonster, int ymonster, int _monster) {
    int x = game->player.get_x(&game->player), y = game->player.get_y(&game->player);

    if (x == xmonster) {
        if (y < ymonster) {
            if (game->map.get(&game->map, xmonster, ymonster - 1) == MAP_ROOM) {
                game->map.set(&game->map, xmonster, ymonster - 1, _monster);
                game->map.set(&game->map, xmonster, ymonster, MAP_ROOM);
            } else if (game->map.get(&game->map, xmonster - 1, ymonster) == MAP_ROOM) {
                game->map.set(&game->map, xmonster - 1, ymonster, _monster);
                game->map.set(&game->map, xmonster, ymonster, MAP_ROOM);
            } else if (game->map.get(&game->map, xmonster + 1, ymonster) == MAP_ROOM) {
                game->map.set(&game->map, xmonster + 1, ymonster, _monster);
                game->map.set(&game->map, xmonster, ymonster, MAP_ROOM);
            }
        } else if (y > ymonster) {
            if (game->map.get(&game->map, xmonster, ymonster + 1) == MAP_ROOM) {
                game->map.set(&game->map, xmonster, ymonster + 1, _monster);
                game->map.set(&game->map, xmonster, ymonster, MAP_ROOM);
            } else if (game->map.get(&game->map, xmonster - 1, ymonster) == MAP_ROOM) {
                game->map.set(&game->map, xmonster - 1, ymonster, _monster);
                game->map.set(&game->map, xmonster, ymonster, MAP_ROOM);
            } else if (game->map.get(&game->map, xmonster + 1, ymonster) == MAP_ROOM) {
                game->map.set(&game->map, xmonster + 1, ymonster, _monster);
                game->map.set(&game->map, xmonster, ymonster, MAP_ROOM);
            }
        }
    } else {
        if (x < xmonster) {
            if (game->map.get(&game->map, xmonster - 1, ymonster) == MAP_ROOM) {
                game->map.set(&game->map, xmonster - 1, ymonster, _monster);
                game->map.set(&game->map, xmonster, ymonster, MAP_ROOM);
            } else if (y < ymonster && game->map.get(&game->map, xmonster, ymonster - 1) == MAP_ROOM) {
                game->map.set(&game->map, xmonster, ymonster - 1, _monster);
                game->map.set(&game->map, xmonster, ymonster, MAP_ROOM);
            } else if (y > ymonster && game->map.get(&game->map, xmonster, ymonster + 1) == MAP_ROOM) {
                game->map.set(&game->map, xmonster, ymonster + 1, _monster);
                game->map.set(&game->map, xmonster, ymonster, MAP_ROOM);
            }
        } else if (x > xmonster) {
            if (game->map.get(&game->map, xmonster + 1, ymonster) == MAP_ROOM) {
                game->map.set(&game->map, xmonster + 1, ymonster, _monster);
                game->map.set(&game->map, xmonster, ymonster, MAP_ROOM);
            } else if (y < ymonster && game->map.get(&game->map, xmonster, ymonster - 1) == MAP_ROOM) {
                game->map.set(&game->map, xmonster, ymonster - 1, _monster);
                game->map.set(&game->map, xmonster, ymonster, MAP_ROOM);
            } else if (y > ymonster && game->map.get(&game->map, xmonster, ymonster + 1) == MAP_ROOM) {
                game->map.set(&game->map, xmonster, ymonster + 1, _monster);
                game->map.set(&game->map, xmonster, ymonster, MAP_ROOM);
            }
        }
    }
}


/**
 * @brief Moves the monster next to the player
 * 
 * @param game The current game
 */
void monster(Game *game){
    int x=0,y=0,x1=0,y1=0,x2=0,y2=0,posx=game->player.get_x(&game->player),posy=game->player.get_y(&game->player);
    get_actual_room(game,posx,posy,&x1,&x2,&y1,&y2);
    for(x=x1;x<x2;x++){
        for(y=y1;y<y2;y++){
            if(is_monster(game->map.get(&game->map,x,y))){
                movementMonster(game,x,y, game->map.get(&game->map,x,y));
                return ;
                //Je return ; comme ca je ne retombe pas sur le meme monstre une autre fois
            }
        }
    }
}
