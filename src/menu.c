#include "menu.h"

printTitle(ARA_Window self){
    mvwprintw(self.main_window,1,1,".______        ______     _______  __    __   _______");
    mvwprintw(self.main_window,2,1,"|   _  \\      /  __  \\   /  _____||  |  |  | |   ____|");
    mvwprintw(self.main_window,3,1,"|  |_)  |    |  |  |  | |  |  __  |  |  |  | |  |__");
    mvwprintw(self.main_window,4,1,"|      /     |  |  |  | |  | |_ | |  |  |  | |   __|");
    mvwprintw(self.main_window,5,1,"|  |\\  \\----.|  `--'  | |  |__| | |  `--'  | |  |____");
    mvwprintw(self.main_window,6,1,"| _| `._____| \\______/   \\______|  \\______/  |_______|");
    
    mvwprintw(self.main_window,7,1," __       __   __  ___  _______");
    mvwprintw(self.main_window,8,1,"|  |     |  | |  |/  / |   ____|");
    mvwprintw(self.main_window,9,1,"|  |     |  | |  '  /  |  |__");
    mvwprintw(self.main_window,10,1,"|  |     |  | |    <   |   __|");
    mvwprintw(self.main_window,11,1,"|  `----.|  | |  .  \\  |  |____");
    mvwprintw(self.main_window,12,1,"|_______||__| |__|\\__\\ |_______|");
}

void printmenu(ARA_Window self, char choice[SIZE_MENU][20], int k){
    //Y a moyen de beaucoup optimiser mais faudra mettre 🔳 et 🔲 dans une variable et utiliser la variable dans les conditions
    int i=0,letters=0;
    for(i=0;i<SIZE_MENU;i++){
        letters=strlen(choice[i]);
        letters--;
        if(i==k){
            mvwprintw(self.main_window, 4*i+NB_LINES/2-(SIZE_MENU-1)*2, NB_COLS/2-15, "💨");
            mvwprintw(self.main_window, 4*i+NB_LINES/2-(SIZE_MENU-1)*2, NB_COLS/2-10, "🔲");
            mvwprintw(self.main_window, 4*i+NB_LINES/2-(SIZE_MENU-1)*2, 10+NB_COLS/2-10-letters/2, "%s",choice[i]);
            mvwprintw(self.main_window, 4*i+NB_LINES/2-(SIZE_MENU-1)*2, 20+NB_COLS/2-9, "🔲");
            //Pour le deuxieme affichage je fais la colonne du premier + du deuxieme sur 2 comme ca je suis au milieux des 2 🔲 puis je recule de lettres/2 
            //Le 4*i c est parce que il y a 4 espaces entre chaque deux chaines
        }
        else{
            mvwprintw(self.main_window, 4*i+NB_LINES/2-(SIZE_MENU-1)*2, NB_COLS/2-10, "🔳");
            mvwprintw(self.main_window, 4*i+NB_LINES/2-(SIZE_MENU-1)*2, 10+NB_COLS/2-10-letters/2, "%s",choice[i]);
            mvwprintw(self.main_window, 4*i+NB_LINES/2-(SIZE_MENU-1)*2, 20+NB_COLS/2-9, "🔳");
            //Le -10 il vient de la difference d emplacement entre les deux 🔳 sur deux : (20-0)/2
        }
    }
}

int movementmenu(ARA_Window self, int *k){
    switch(self.get_key(&self)){
        case '\n' :
            return 1;
        case 'z' :
            if((*k)>0){
                (*k)--;
            }
            break;
            //Ne pas enlever le break; sinon ca passe a celui d'apres et ca bug
        case 's' :
            if((*k)<SIZE_MENU-1){
                (*k)++;
            }
    }
    return 0;
}

int menuGame(Game *game){
    int k=0;
    //Si on ajoute une autre option faudra changer le SIZE_MENU que j ai defini comme constante
    char choice[SIZE_MENU][20]={"New game","Resume game","Stats","Settings","Credit","Exit"};
    ARA_Window_init(&game->window,1);
    do{
        game->window.clear_all(&game->window);
        game->window.create_one_win_mode(&game->window);
        //printTitle(game->window);
        printmenu(game->window,choice,k);
        game->window.refresh_all(&game->window);
        game->window.update_key(&game->window);
    }while(movementmenu(game->window,&k)==0);
    return k;
}

int menuChoice(Game *game){
    switch (menuGame(game)){
        case 0 :
            generatemap(game);
            game->timer.reset(&game->timer);
            return 1;
        case 1 :
            recoverGame(game);
            return 1;
        case 4 :
            char choice[SIZE_MENU][20]={"Groupe","MI-3 tri-K","Membres","Ahmed","Abdelwaheb","Rayane"};
            game->window.clear_all(&game->window);
            game->window.create_one_win_mode(&game->window);
            printmenu(game->window, choice, 7);
            game->window.update_key(&game->window);
            game->window.get_key(&game->window);
            menuChoice(game);
            break;
        default :
            return 0;
    }
}