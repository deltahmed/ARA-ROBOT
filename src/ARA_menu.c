#include "ARA_menu.h"
#include <math.h>

/**
 * @brief Print the title of the game.
 * 
 * @param window The current window.
 */
void printTitle(ARA_Window self){
    int y=8;
    mvwprintw(self.main_window,y+1,2,"    ___    ____  ___");              
    mvwprintw(self.main_window,y+2,2,"   /   |  / __ \\/   |");             
    mvwprintw(self.main_window,y+3,2,"  / /| | / /_/ / /| |");             
    mvwprintw(self.main_window,y+4,2," / ___ |/ _, _/ ___ |");             
    mvwprintw(self.main_window,y+5,2,"/_/ _|||_/_|||_/__||| ____  ______");
    mvwprintw(self.main_window,y+6,2,"   / __ \\/ __ \\/ __ )/ __ \\/_  __/");
    mvwprintw(self.main_window,y+7,2,"  / /_/ / / / / __  / / / / / /");   
    mvwprintw(self.main_window,y+8,2," / _, _/ /_/ / /_/ / /_/ / / /");   
    mvwprintw(self.main_window,y+9,2,"/_/ |_|\\____/_____/\\____/ /_/");
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
    int y=0,lines=NB_LINES/2-(SIZE_MENU-1)*2,columns=NB_COLS/2,letters=0;
    for(y=0;y<SIZE_MENU;y++){
        letters=strlen(choice[y]);
        letters--;
        if(y==cursor){
            mvwprintw(window.main_window, lines+4*y, columns-5, "💨");
            mvwprintw(window.main_window, lines+4*y, columns, "🔲");
            mvwprintw(window.main_window, lines+4*y, columns-letters/2 +10, "%s",choice[y]);
            mvwprintw(window.main_window, lines+4*y, columns+20, "🔲");
            //Pour le deuxieme affichage je fais la colonne du premier + du deuxieme sur 2 comme ca je suis au milieux des 2 🔲 puis je recule de lettres/2 
            //Le 4*y c est parce que il y a 4 espaces entre chaque deux chaines
        }
        else{
            mvwprintw(window.main_window, lines+4*y, columns, "🔳");
            mvwprintw(window.main_window, lines+4*y, columns-letters/2 +10, "%s",choice[y]);
            mvwprintw(window.main_window, lines+4*y, columns+20, "🔳");
        }
    }
}

/**
 * @brief Print the credits of the game.
 * 
 * @param window The current window.
 */
void print_credit(ARA_Window window){
    char credit[SIZE_CREDIT][20]={"MI-3 tri-K","Ahmed A.","Abdelwaheb A.","Rayane M."};
    int y=0,lines=NB_LINES/2-(SIZE_CREDIT-1)*2,columns=NB_COLS/2,letters=0;
    for(y=0;y<SIZE_CREDIT;y++){
        letters=strlen(credit[y]);
        letters--;
        mvwprintw(window.main_window, lines+4*y, columns-2, "🏮");
        mvwprintw(window.main_window, lines+4*y, columns-letters/2 +10, "%s",credit[y]);
        mvwprintw(window.main_window, lines+4*y, columns+22, "🏮");
        //Pour le deuxieme affichage je fais la colonne du premier + du deuxieme sur 2 comme ca je suis au milieux des 2 🔲 puis je recule de lettres/2 
        //Le 4*y c est parce que il y a 4 espaces entre chaque deux chaines
    }
    mvwprintw(window.main_window, NB_LINES-3, NB_COLS-10, "Menu : m");
    mvwprintw(window.main_window, NB_LINES-2, NB_COLS-3, "↩");
}

/**
 * @brief Handle menu navigation and key presses.
 * 
 * @param window The current window.
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
 * @param game The current game.
 * @return the index of the selected menu option.
 */
int game_menu(Game *game){
    int cursor=0;
    //Si on ajoute une autre option faudra changer le SIZE_MENU que j ai defini comme constante
    char choice[SIZE_MENU][20]={"New game","Resume game","Credits","Exit"};
    ARA_Window_init(&game->window,W_MODE_ONE);
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

int verif_number(char *numberchar){
    int number=0,i=0,size=0,add=0;
    size=strlen(numberchar);
    for(i=0;i<size;i++){
        add=numberchar[i];
        if('0'<=numberchar[i] && numberchar[i]<='9'){
            add=numberchar[i]-'0';
        }
        number+=add* (int)pow(10,size-1-i);
    }
    return number;
}

/**
 * @brief Verify the caracters of a string
 * 
 * @param name 
 */
void verif_string(char *name){
    int i=0,size=0;
    size=strlen(name);
    for(i=0;i<size;i++){
        if(name[i]<'A' || name[i]>'z' || ('Z'<name[i] && name[i]<'a')){
            name[i]='_';
        }
    }
}

/**
 * @brief Gets the name and the seed from the player
 * 
 * @param game The current game
 */
void player_infos(Game *game){
    char choice[SIZE_INFOS][20]={"Name","Seed"};
    char seedchar[100];
    int i=0,cursor=0,seed=0;
    int checkname=0,checkseed=0;
    int lines=NB_LINES/2-(SIZE_INFOS)*2,columns=NB_COLS/2-24;

    ARA_Window_init(&game->window,W_MODE_ONE);

    do{
        game->window.clear_all(&game->window);
        game->window.create_one_win_mode(&game->window);
        for(i=0;i<SIZE_INFOS;i++){
            if(cursor==i){
                mvwprintw(game->window.main_window,6*i+lines,columns-4,"💨");
            }
            if(checkname==1 && i==0){
                mvwprintw(game->window.main_window,6*i+lines-1,columns,"▄█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█▄");
                mvwprintw(game->window.main_window,6*i+lines,columns+5,"%s :  %s",choice[i],game->player.__name);
                mvwprintw(game->window.main_window,6*i+lines+1,columns,"▀█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▀");
            }
            else{
                mvwprintw(game->window.main_window,6*i+lines-1,columns,"▄█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█▄");
                mvwprintw(game->window.main_window,6*i+lines,columns+5,"%s : ",choice[i]);
                mvwprintw(game->window.main_window,6*i+lines+1,columns,"▀█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▀");
            }
        }
        game->window.refresh_all(&game->window);
        nocbreak();
        echo();
        if(cursor==0){
            wmove(game->window.main_window,lines,columns+13);
            wscanw(game->window.main_window,"%s",game->player.__name);
            verif_string(game->player.__name);
            checkname=1;
            cursor++;
        }
        else if(cursor==1){
            wmove(game->window.main_window,lines+6,columns+13);
            wscanw(game->window.main_window,"%s",seedchar);
            seed=verif_number(seedchar);
            checkseed=1;
        }
        cbreak();
        noecho();
        if((checkname==1 && checkseed==1)){
            srand(seed);
            return;
        }
    }while(1);
}

int restor_with_name(Game *game){
    int lines=NB_LINES/2-(SIZE_INFOS)*2,columns=NB_COLS/2-24;
    int r=1;

    ARA_Window_init(&game->window,W_MODE_ONE);

    game->window.clear_all(&game->window);
    game->window.create_one_win_mode(&game->window);
    mvwprintw(game->window.main_window,lines-1,columns,"▄█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█▄");
    mvwprintw(game->window.main_window,lines,columns+5,"NAME : ");
    mvwprintw(game->window.main_window,lines+1,columns,"▀█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▀");

    game->window.refresh_all(&game->window);
    nocbreak();
    echo();
    wmove(game->window.main_window,lines,columns+13);
    wscanw(game->window.main_window,"%s",game->player.__name);
    verif_string(game->player.__name);
    cbreak();
    noecho();
    
    char name[200];
    sprintf(name,"%splayer.bin",game->player.__name);
    FILE *fichier=fopen(name,"rb");
    if(fichier==NULL){
        r=0;
    }
    else{
        fclose(fichier);
    }
    return r;
    game->window.destroy();
}

/**
 * @brief Handle the user's choice from the main menu.
 * 
 * @param game The current game.
 * @return the user's choice from the main menu.
 */
int choice_menu(Game *game){
    switch (game_menu(game)){
        case NEWGAME :
            game->window.destroy(&game->window);
            player_infos(game);
            generate_map(game);
            game->timer.reset(&game->timer);
            return NEWGAME;
        case RESUMEGAME :
            if(restor_with_name(game)==0){
                return RESTORE_FAIL;
            }
            recoverGame(game);
            game->timer.reset(&game->timer);
            return RESUMEGAME;
        case CREDIT :
            game->window.clear_all(&game->window);
            game->window.create_one_win_mode(&game->window);
            printTitle(game->window);
            print_credit(game->window);
            do{
                game->window.update_key(&game->window);
            }while(game->window.get_key(&game->window)!='m');
            return CREDIT;
        default :
            game->window.destroy();
            game->map.destroy(&game->map);
            return EXIT;
    }
}

/**
 * @brief Print the "Game Over" screen.
 * 
 * @param window The current window.
 */
void printGameOver(ARA_Window window){
    int y=6;
    mvwprintw(window.main_window,y+1,8,"  _______      ___      .___  ___.  _______");                     
    mvwprintw(window.main_window,y+2,8," /  _____|    /   \\     |   \\/   | |   ____|");                    
    mvwprintw(window.main_window,y+3,8,"|  |  __     /  ^  \\    |  \\  /  | |  |__");                       
    mvwprintw(window.main_window,y+4,8,"|  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|");                      
    mvwprintw(window.main_window,y+5,8,"|  |__| |  /  _____  \\  |  |  |  | |  |____");                     
    mvwprintw(window.main_window,y+6,8," \\______| /__/     \\__\\ |__|  |__| |_______|");                                                                                   
    mvwprintw(window.main_window,y+8,8,"                    ______   ____    ____  _______ .______");      
    mvwprintw(window.main_window,y+9,8,"                   /  __  \\  \\   \\  /   / |   ____||   _  \\");     
    mvwprintw(window.main_window,y+10,8,"                  |  |  |  |  \\   \\/   /  |  |__   |  |_)  |");    
    mvwprintw(window.main_window,y+11,8,"                  |  |  |  |   \\      /   |   __|  |      /");     
    mvwprintw(window.main_window,y+12,8,"                  |  `--'  |    \\    /    |  |____ |  |\\  \\----.");
    mvwprintw(window.main_window,y+13,8,"                   \\______/      \\__/     |_______|| _| `._____|");
}
/**
 * @brief Display the "Game Over" screen and handle user input for returning to the main menu.
 * 
 * @param game the current game.
 */
void gameEnd(Game game){
    ARA_Window_init(&game.window,W_MODE_ONE);
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

/**
 * @brief Print the title of the game.
 * 
 * @param window The current window.
 */
void printTitleWin(ARA_Window self){
    int y=4;
    mvwprintw(self.main_window,y+1,20,"$$\\     $$\\");                                      
    mvwprintw(self.main_window,y+2,20,"\\$$\\   $$  |");                                     
    mvwprintw(self.main_window,y+3,20," \\$$\\ $$  /$$$$$$\\  $$\\   $$\\");                    
    mvwprintw(self.main_window,y+4,20,"  \\$$$$  /$$  __$$\\ $$ |  $$ |");                   
    mvwprintw(self.main_window,y+5,20,"   \\$$  / $$ /  $$ |$$ |  $$ |");                   
    mvwprintw(self.main_window,y+6,20,"    $$ |  $$ |  $$ |$$ |  $$ |");                   
    mvwprintw(self.main_window,y+7,20,"    $$ |  \\$$$$$$  |\\$$$$$$  |");                   
    mvwprintw(self.main_window,y+8,20,"    \\__|   \\______/  \\______/");                                                                  
    mvwprintw(self.main_window,y+10,20,"            $$\\      $$\\ $$\\                 $$\\"); 
    mvwprintw(self.main_window,y+11,20,"            $$ | $\\  $$ |\\__|                $$ |");
    mvwprintw(self.main_window,y+12,20,"            $$ |$$$\\ $$ |$$\\ $$$$$$$\\        $$ |");
    mvwprintw(self.main_window,y+13,20,"            $$ $$ $$\\$$ |$$ |$$  __$$\\       $$ |");
    mvwprintw(self.main_window,y+14,20,"            $$$$  _$$$$ |$$ |$$ |  $$ |      \\__|");
    mvwprintw(self.main_window,y+15,20,"            $$$  / \\$$$ |$$ |$$ |  $$ |");          
    mvwprintw(self.main_window,y+16,20,"            $$  /   \\$$ |$$ |$$ |  $$ |      $$\\"); 
    mvwprintw(self.main_window,y+17,20,"            \\__/     \\__|\\__|\\__|  \\__|      \\__|");
}

/**
 * @brief 
 * 
 */
void gameWin(Game game){
    ARA_Window_init(&game.window,W_MODE_ONE);
    game.window.clear_all(&game.window);
    game.window.create_one_win_mode(&game.window);
    printTitleWin(game.window);
    mvwprintw(game.window.main_window, NB_LINES-3, NB_COLS-10, "Menu : m");
    mvwprintw(game.window.main_window, NB_LINES-2, NB_COLS-3, "↩");
    game.window.refresh_all(&game.window);
    do{
        game.window.update_key(&game.window);
    }while(game.window.get_key(&game.window)!='m');
}