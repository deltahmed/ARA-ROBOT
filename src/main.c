
#include "ARA_def.h"
#include "map.h"
#include "ARA_window.h"
#include "game.h"

#define SIZE_MENU 6

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
            mvwprintw(self.main_window, 4*i+NB_LINES/2-(SIZE_MENU-1)*2, 20+NB_COLS/2-10, "🔲");
            //Pour le deuxieme affichage je fais la colonne du premier + du deuxieme sur 2 comme ca je suis au milieux des 2 🔲 puis je recule de lettres/2 
            //Le 4*i c est parce que il y a 4 espaces entre chaque deux chaines
        }
        else{
            mvwprintw(self.main_window, 4*i+NB_LINES/2-(SIZE_MENU-1)*2, NB_COLS/2-10, "🔳");
            mvwprintw(self.main_window, 4*i+NB_LINES/2-(SIZE_MENU-1)*2, 10+NB_COLS/2-10-letters/2, "%s",choice[i]);
            mvwprintw(self.main_window, 4*i+NB_LINES/2-(SIZE_MENU-1)*2, 20+NB_COLS/2-10, "🔳");
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
        printmenu(game->window,choice,k);
        game->window.refresh_all(&game->window);
        game->window.update_key(&game->window);
    }while(movementmenu(game->window,&k)==0);
    game->window.destroy();
    return k;
}

//88 33

//22 58
int main(){
    Game game;
    Game_init(&game);
    menuGame(&game);
    generatemap(&game);
    while(TRUE) {
        game.window.clear_all(&game.window);

        game.window.create(&game.window);

        cprintf(game.window.top, 1, 1, COLOR_MUR, "Ceci est la fenetre du haut %d %d %d", COLS, LINES, game.window.get_key(&game.window));

        cprint(game.window.bottom, 1, 1, COLOR_MUR2, "Ceci est la fenetre du bas");

        
        printmap(&game);
        game.window.update_key(&game.window);
        __movement(&game);

        
            
        game.window.update(&game.window);
    }

    
    game.window.destroy();

    return 0;
}

