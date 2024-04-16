#include <ncursesw/ncurses.h>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SOL 0
#define MC 1
#define MONSTER 2
#define PORTE 3
#define FLEUR 4

typedef struct{
    int fleur;
}Inventaire;

typedef struct{
    char pseudo[20];
    int vie;
    int numsalle;
    Inventaire inv;
}Joueur;

Joueur constructeurJoueur(){
    Joueur a;
    a.vie=5;
    a.inv.fleur=0;
    a.numsalle=1;
    printw("Donnez votre pseudo : ");
    refresh();
    scanw("%s",a.pseudo);
    return a;
}

void initializeColor(){
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
}

int** creationTab(int M, int N){
    int i=0;
    int **tab=NULL;
    tab=calloc(M,sizeof(int*));
    if(tab==NULL){
        exit(1);
    }
    for(i=0;i<M;i++){
        tab[i]=calloc(N,sizeof(int));
        if(tab[i]==NULL){
            exit(i+2);
        }
    }
    return tab;
}

void initializeTab(int** tab, int M, int N, int indice){
    int i=0,j=0,x=0,y=0,r=0;
    //Pas la peine d initialiser les case   tab[i][j]=SOL car je cree le tableau avec un calloc//
    if(indice==0){
        tab[rand()%(M-2)+1][N-1]=PORTE;
        tab[rand()%M][0]=MC;
    }
    else if(indice==2){
        x=rand()%(M-2)+1;
        tab[x][0]=PORTE;
        tab[x-1][0]=MC;
    }
    else{
        tab[rand()%(M-2)+1][N-1]=PORTE;
        x=rand()%(M-2)+1;
        tab[x][0]=PORTE;
        tab[x-1][0]=MC;
    }
    for(i=0;i<=rand()%10;i++){
        x=rand()%M;
        y=rand()%N;
        if(tab[x][y]==SOL){
            tab[x][y]=MONSTER;
        }
        x=rand()%M;
        y=rand()%N;
        if(tab[x][y]==SOL){
            tab[x][y]=FLEUR;
        }
    }
}

void boite(int hauteur, int largeur, int posx, int posy){
    int i=0;
    attron(COLOR_PAIR(4) | A_BOLD);
    mvprintw(posx,posy,"+");
    mvprintw(posx+hauteur-1,posy,"+");
    mvprintw(posx,posy+largeur-1,"+");
    mvprintw(posx+hauteur-1,posy+largeur-1,"+");
    for(i=posy+1;i<posy+largeur-1;i++){
        mvprintw(posx,i,"-");
        mvprintw(posx+hauteur-1,i,"-");
    }
    for(i=posx+1;i<posx+hauteur-1;i++){
        mvprintw(i,posy,"|");
        mvprintw(i,posy+largeur-1,"|");
    }
    attroff(COLOR_PAIR(4) | A_BOLD);
}

void afficheTab(int **tab, int M, int N, int hauteur, int largeur, int posx, int posy){
    int i=0,j=0;
    for(i=posx+1;i<posx+hauteur-1;i++){
        for(j=posy+1;j<posy+largeur-1;j++){
            switch(tab[i-(posx+1)][j-(posy+1)]){
                case SOL :
                    mvprintw(i,j," ");
                    break;
                case MC :
                    attron(COLOR_PAIR(1) | A_BOLD);
                    mvprintw(i,j,"@");
                    attroff(COLOR_PAIR(1) | A_BOLD);
                    break;
                case MONSTER :
                    attron(COLOR_PAIR(2) | A_BOLD);
                    mvprintw(i,j,"#");
                    attroff(COLOR_PAIR(2) | A_BOLD);
                    break;
                case PORTE :
                    attron(COLOR_PAIR(3) | A_BOLD);
                    mvprintw(i,j,"&");
                    attroff(COLOR_PAIR(3) | A_BOLD);
                    break;
                case FLEUR :
                    attron(COLOR_PAIR(5) | A_BOLD);
                    mvprintw(i,j,"y");
                    attroff(COLOR_PAIR(5) | A_BOLD);
                    break;
            }
        }
    }
}

void trouveMC(int **tab, int M, int N, int *x, int *y){
    int i=0,j=0;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            if(tab[i][j]==MC){
                *x=i;
                *y=j;
            }
        }
    }
}

void afficheSalle(int **tab, int M, int N, int hauteur, int largeur, int posx, int posy, Joueur *p1){
    int x=0,y=0;
    boite(hauteur,largeur,posx,posy);
    afficheTab(tab,M,N,hauteur,largeur,posx,posy);
    mvprintw(posx+hauteur+1,posy,"%s",(*p1).pseudo);
    mvprintw(posx+hauteur+2,posy,"Vous etes dans la salle numero %d",(*p1).numsalle);
    mvprintw(posx+hauteur+3,posy,"Vous avez %d fleurs",(*p1).inv.fleur);
    mvprintw(posx+hauteur+4,posy,"Vous avez %d vies",(*p1).vie);
    mvprintw(posx+hauteur+5,posy,"Quitter : Touche entree");
}

int mouvement(int **tab, int M, int N, Joueur *p1){
    char c=0;
    int x=0,y=0,i=0,j=0,a=0,b=0,r=0;
    trouveMC(tab,M,N,&x,&y);
    do{
        r=0;
        c=getch();
        switch(c){
            case 2 :
                if(x+1<=M-1){
                    a=x+1;
                    b=y;
                    r=1;
                }
                break;
            case 3 :
                if(x-1>=0){
                    a=x-1;
                    b=y;
                    r=1;
                }
                break;
            case 5 :
                if(y+1<=N-1){
                    a=x;
                    b=y+1;
                    r=1;
                }
                break;
            case 4 :
                if(y-1>=0){
                    a=x;
                    b=y-1;
                    r=1;
                }
                break;
            case '\n' :
                return 0;
                break;
        }
    }while(r==0);
    switch (tab[a][b]){//Je pourrais en faire une fonction si je mets beaucoup de types pour laisser la fonction mouvement juste pour le deplacement//
        case SOL :
            tab[a][b]=tab[x][y];
            tab[x][y]=SOL;
            break;
        case MONSTER :
            (*p1).vie--;
            if((*p1).vie<=0){return 10;}
            return 2;
            break;
        case PORTE :
            if(b==0){return 3;}//Ca veut dire que c la porte arriere//
            return 4;//Ca veut dire que c la porte avant//
            break;
        case FLEUR :
            tab[a][b]=tab[x][y];
            (*p1).inv.fleur++;
            tab[x][y]=SOL;
            break;
    }
    return 1;
}

int deplacement(int **tab, int M, int N, int hauteur, int largeur, int posx, int posy, Joueur *p1){
    int r=0;
    clear();
    afficheSalle(tab,M,N,hauteur,largeur,posx,posy,p1);
    refresh();
    do{
        r=mouvement(tab,M,N,p1);
        clear();
        afficheSalle(tab,M,N,hauteur,largeur,posx,posy,p1);
        refresh();
    }while(r==1);
    return r;
}

int game(int ***tab, int taille, int *M, int *N, Joueur *p1){
    int r=0,i=0,k=0,x=0,y=0,hauteur=0,largeur=0,posx=0,posy=0,indice=0,inv=0,xinitial=0,yinitial=0;
    char c=0;
    do{
        if(tab[k]==NULL){
            M[k]=rand()%16+5;
            N[k]=rand()%61+20;
            tab[k]=creationTab(M[k],N[k]);
            if(k==taille-1){indice=2;}
            else if(k==0){indice=0;}
            else{indice=1;}
            initializeTab(tab[k],M[k],N[k],indice);
            //L indice sert a differencier la premiere salle qui a besoin d une seule porte avant, la derniere qui a besoin d une seule porte arriere et les intermediaires qui ont besoin des deux//
            if(k==0){
                trouveMC(tab[k],M[k],N[k],&xinitial,&yinitial);//Pour enregistrer le point de depart dans la premiere salle pour y mettre le joueur en cas de defaite//
            }
        }
        (*p1).numsalle=k+1;//Pour pouvoir afficher a l ecran la salle ou se trouve le joueur//
        hauteur=M[k]+2;
        largeur=N[k]+2;
        posx=2;
        posy=4;
        r=deplacement(tab[k],M[k],N[k],hauteur,largeur,posx,posy,p1);
        if(r==3){k--;}//Alors c est la porte arriere//
        else if(r==4){k++;}//Alors c est la porte avant//
        else if(r==2){
            k=0;
            trouveMC(tab[k],M[k],N[k],&x,&y);//Parce qu on aura un MC deja posistionne a cote de la porte de la salle 1 donc il faut l enlever//
            tab[k][x][y]=SOL;
            tab[k][xinitial][yinitial]=MC;
        }
    }while(r!=0 && r!=10);
    for(k=0;k<taille;k++){//Je free le tab parceque si je sors de la boucle ca veut dire que soit j ai quitte soit j ai perdu//
        for(i=0;i<M[k];i++){
            free(tab[k][i]);
        }
        free(tab[k]);
    }//Je ne free pas le tab entier parce que de toute facon j ai fais ca a la fin du programme dans la fin du main//
    return r;
}


int main()
{
    initscr();
    curs_set(0);//Pour enlever la marque du curseur//
    clear();//Pour reintialiser l affichage, indispensable avant chaque affichage sinon y aura un affichage sur un autre et donc des points rouges apparaissent//
    keypad(stdscr, TRUE);//Pour activer les touches haut bas droite et gauche//
    initializeColor();//C est une fonction que j ai cree tout en haut, regroupant toutes les couleurs que j utilise//
    int i=0,k=0,salle=0;
    int *M=NULL,*N=NULL;
    int ***tab=NULL;
    Joueur p1;
    srand(time(NULL));
    p1=constructeurJoueur();
    do{
        printw("Donnez le nombre de salles : ");
        refresh();
        scanw("%d",&salle);
    }while(salle<=1 || salle>=20);
    clear();
    noecho();//Pour enlever l affichage d un caractere quand une touche est tapee, je le mets ici parceque en haut j ai besoin de voir ce que j ecris pour le scanf//
    M=calloc(salle,sizeof(int));
    N=calloc(salle,sizeof(int));
    tab=calloc(salle,sizeof(int**));//Ici le calloc est TRES Important car il initialise tous les tab[i] en NULL ce qu on va utiliser dans la fonction game pour savoir si une salle est cree ou non//
    k=game(tab,salle,M,N,&p1);//Ici M et N sont des tableaux de taille par exemple la premier salle est tab[0] sa case en haut a gauche est tab[0][0][0] et ses dimensions sont M[0] et N[0] et ainsi de suite//
    if(k==10){
        mvprintw(1,1,"GAMEOVER");
    }
    else{
        mvprintw(1,1,"VOUS AVEZ QUITTE");
    }
    free(tab);
    free(M);
    free(N);
    refresh();
    getch();
    endwin();
    return 0;
}
