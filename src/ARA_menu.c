#include "ARA_menu.h"

/**
 * @brief Print the title of the game.
 * 
 * @param window The curent window.
 */
void printTitle(ARA_Window window){
    int y=9;
    mvwprintw(window.main_window,y,2,"    ___    ____  ___");              
    mvwprintw(window.main_window,y+1,2,"   /   |  / __ \\/   |");             
    mvwprintw(window.main_window,y+2,2,"  / /| | / /_/ / /| |");             
    mvwprintw(window.main_window,y+3,2," / ___ |/ _, _/ ___ |");             
    mvwprintw(window.main_window,y+4,2,"/_/ _|||_/_|||_/__|||___  ________");
    mvwprintw(window.main_window,y+5,2,"   / __ \\/ __ \\/ ____/ / / / ____/");
    mvwprintw(window.main_window,y+6,2,"  / /_/ / / / / / __/ / / / __/");   
    mvwprintw(window.main_window,y+7,2," / _, _/ /_/ / /_/ / /_/ / /___");   
    mvwprintw(window.main_window,y+8,2,"/_/ |_|\\____/\\____/\\____/_____/");
}

/**
 * @brief Print the menu options.
 * 
 * @param window The curent window.
 * @param choice Array of strings representing the menu options.
 * @param cursor the current cursor position.
 */
void print_menu(ARA_Window window, char choice[SIZE_MENU][20], int cursor){
    //Y a moyen de beaucoup optimiser mais faudra mettre 🔳 et 🔲 dans une variable et utiliser la variable dans les conditions
    int y=0,lines=0,columns=0,letters=0;
    for(y=0;y<SIZE_MENU;y++){
        letters=strlen(choice[y]);
        letters--;
        lines=4*y+NB_LINES/2-(SIZE_MENU-1)*2;
        columns=NB_COLS/2;//Faire -10 pour le centrer
        if(y==cursor){
            mvwprintw(window.main_window, lines, columns-5, "💨");
            mvwprintw(window.main_window, lines, columns, "🔲");
            mvwprintw(window.main_window, lines, columns-letters/2 +10, "%s",choice[y]);
            mvwprintw(window.main_window, lines, columns+20, "🔲");
            //Pour le deuxieme affichage je fais la colonne du premier + du deuxieme sur 2 comme ca je suis au milieux des 2 🔲 puis je recule de lettres/2 
            //Le 4*i c est parce que il y a 4 espaces entre chaque deux chaines
        }
        else{
            mvwprintw(window.main_window, lines, columns, "🔳");
            mvwprintw(window.main_window, lines, columns-letters/2 +10, "%s",choice[y]);
            mvwprintw(window.main_window, lines, columns+20, "🔳");
        }
    }
}

/**
 * @brief Print the credits of the game.
 * 
 * @param window The curent window.
 */
void print_credit(ARA_Window window){
    char credit[SIZE_CREDIT][20]={"MI-3 tri-K","Ahmed A.","Abdelwaheb A.","Rayane M."};
    int y=0,lines=0,columns=0,letters=0;
    for(y=0;y<SIZE_CREDIT;y++){
        letters=strlen(credit[y]);
        letters--;
        lines=4*y+NB_LINES/2-(SIZE_CREDIT-1)*2;
        columns=NB_COLS/2;//Faire -10 pour le centrer
        mvwprintw(window.main_window, lines, columns-2, "🏮");
        mvwprintw(window.main_window, lines, columns-letters/2 +10, "%s",credit[y]);
        mvwprintw(window.main_window, lines, columns+22, "🏮");
    }
    mvwprintw(window.main_window, NB_LINES-3, NB_COLS-10, "Menu : m");
    mvwprintw(window.main_window, NB_LINES-2, NB_COLS-3, "↩");
}

/**
 * @brief Handle menu navigation and key presses.
 * 
 * @param window The curent window.
 * @param cursor current cursor position.
 * @return true if the selection is confirmed.
 * @return false if not.
 */
int menu_movement(ARA_Window window, int *cursor){
    switch(window.get_key(&window)){
        case '\n' :
            return true;
        case 'z' :
            if((*cursor)>0){
                (*cursor)--;
            }
            break;
            //Ne pas enlever le break; sinon ca passe a celui d'apres et ca bug
        case 's' :
            if((*cursor)<SIZE_MENU-1){
                (*cursor)++;
            }
    }
    return false;
}

/**
 * @brief Display the main game menu and handle user input.
 * 
 * @param game The curent game.
 * @return the index of the selected menu option.
 */
int game_menu(Game *game){
    int cursor=0;
    //Si on ajoute une autre option faudra changer le SIZE_MENU que j ai defini comme constante
    char choice[SIZE_MENU][20]={"New game","Resume game","Stats","Settings","Credit","Exit"};
    ARA_Window_init(&game->window,1);
    do{
        game->window.clear_all(&game->window);
        game->window.create_one_win_mode(&game->window);
        printTitle(game->window);
        print_menu(game->window,choice,cursor);
        game->window.refresh_all(&game->window);
        game->window.update_key(&game->window);
    }while(menu_movement(game->window,&cursor)==0);
    return cursor;
}

/**
 * @brief Handle the user's choice from the main menu.
 * 
 * @param game The curent game.
 * @return a remplire stp ----------------------------------
 */
int choice_menu(Game *game){
    switch (game_menu(game)){
        case 0 :
            generate_map(game);
            game->timer.reset(&game->timer); //mettre les constante dans le . ----------------------------
            return 1;
        case 1 :
            recoverGame(game);
            game->timer.reset(&game->timer);
            return 1;
        case 4 :
            game->window.clear_all(&game->window);
            game->window.create_one_win_mode(&game->window);
            printTitle(game->window);
            print_credit(game->window);
            do{
                game->window.update_key(&game->window);
            }while(game->window.get_key(&game->window)!='m');
            choice_menu(game);
            break;
        default :
            game->window.destroy();
            game->map.destroy(&game->map);
            return 0;
    }
    return 0;
}

/**
 * @brief Print the "Game Over" screen.
 * 
 * @param window The curent window.
 */
void printGameOver(ARA_Window window){
    int y=7;
    mvwprintw(window.main_window,y,8,"  _______      ___      .___  ___.  _______");                     
    mvwprintw(window.main_window,y+1,8," /  _____|    /   \\     |   \\/   | |   ____|");                    
    mvwprintw(window.main_window,y+2,8,"|  |  __     /  ^  \\    |  \\  /  | |  |__");                       
    mvwprintw(window.main_window,y+3,8,"|  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|");                      
    mvwprintw(window.main_window,y+4,8,"|  |__| |  /  _____  \\  |  |  |  | |  |____");                     
    mvwprintw(window.main_window,y+5,8," \\______| /__/     \\__\\ |__|  |__| |_______|");                                                                                   
    mvwprintw(window.main_window,y+7,8,"                    ______   ____    ____  _______ .______");      
    mvwprintw(window.main_window,y+8,8,"                   /  __  \\  \\   \\  /   / |   ____||   _  \\");     
    mvwprintw(window.main_window,y+9,8,"                  |  |  |  |  \\   \\/   /  |  |__   |  |_)  |");    
    mvwprintw(window.main_window,y+10,8,"                  |  |  |  |   \\      /   |   __|  |      /");     
    mvwprintw(window.main_window,y+11,8,"                  |  `--'  |    \\    /    |  |____ |  |\\  \\----.");
    mvwprintw(window.main_window,y+12,8,"                   \\______/      \\__/     |_______|| _| `._____|");
}
/**
 * @brief Display the "Game Over" screen and handle user input for returning to the main menu.
 * 
 * @param game the current game.
 */
void gameEnd(Game game){
    game.window.clear_all(&game.window);
    game.window.create_one_win_mode(&game.window);
    printGameOver(game.window);
    mvwprintw(game.window.main_window, NB_LINES-3, NB_COLS-10, "Menu : m");
    mvwprintw(game.window.main_window, NB_LINES-2, NB_COLS-3, "↩");
    game.window.refresh_all(&game.window);
    do{
        game.window.update_key(&game.window);
    }while(game.window.get_key(&game.window)!='m');
}