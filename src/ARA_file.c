#include "ARA_file.h"

void saveArray(Map *self){
    FILE *fichier=NULL;
    Size i=0;
    fichier=fopen("mapArray.bin","wb");
    //S'il n'est pas deja cree il sera creer tout seul parce que j'utilise le mode "wb"
    if(fichier==NULL){
        exit(100);
    }
    for(i = 0; i < self->sizey(self); i++){
        fwrite(self->__map[i],sizeof(int),self->sizex(self),fichier);
    }
    fclose(fichier);
}

void recoverArray(Map *self){
    FILE *fichier=NULL;
    Size i=0;
    fichier=fopen("mapArray.bin","rb");
    if(fichier==NULL){
        exit(101);
    }
    for (i = 0; i < self->sizey(self); i++)
    {
        fread(self->__map[i],sizeof(int),self->sizex(self),fichier);
    }
    fclose(fichier);
}

void savePlayer(Player *self){
    FILE *fichier = fopen("playerStructure.bin", "wb");
    if(fichier == NULL){
        exit(200);
    }
    fwrite(&self->__x, sizeof(int), 1, fichier);
    fwrite(&self->__y, sizeof(int), 1, fichier);
    fwrite(&self->__life, sizeof(char), 1, fichier);
    fclose(fichier);
    //Quand je mets &self->get_x(&self) au lieu de &self->__x ca marche pas car la fonction est definie dans la structure avec une * 
}

void recoverPlayer(Player *self){
    FILE *fichier = fopen("playerStructure.bin", "rb");
    if(fichier == NULL){
        exit(201);
    }
    fread(&self->__x, sizeof(int), 1, fichier);
    fread(&self->__y, sizeof(int), 1, fichier);
    fread(&self->__life, sizeof(char), 1, fichier);
    fclose(fichier);
}

void saveTimer(Timer *self){
    FILE *fichier = fopen("timeStructure.bin", "wb");
    if(fichier == NULL){
        exit(300);
    }
    fwrite(&self->__actual_time, sizeof(Time), 1, fichier);
    fwrite(&self->__paused, sizeof(boolean), 1, fichier);
    fwrite(&self->__start_game_time, sizeof(Time), 1, fichier);
    fwrite(&self->__timer, sizeof(Time), 1, fichier);
    fclose(fichier);
    //Quand je mets &self->get_x(&self) au lieu de &self->__x ca marche pas car la fonction est definie dans la structure avec une * 
}

void recoverTimer(Timer *self){
    FILE *fichier = fopen("timeStructure.bin", "rb");
    if(fichier == NULL){
        exit(301);
    }
    fread(&self->__actual_time, sizeof(Time), 1, fichier);
    fread(&self->__paused, sizeof(boolean), 1, fichier);
    fread(&self->__start_game_time, sizeof(Time), 1, fichier);
    fread(&self->__timer, sizeof(Time), 1, fichier);
    //Une piste pour resoudre le probleme d heure apres un recover est d enlever le premier et troisieme fread
    fclose(fichier);
}

void saveGame(Game *game){
    savePlayer(&game->player);
    saveArray(&game->map);
    saveTimer(&game->timer);
    //Je ne peux pas enregistrer toute la structure d'un coup car dans toutes les structures il y a des pointeurs (l'entete des fonctions) qui font buguer le fichier
    //Donc il faut le faire manuellement pour chaque structure
}

void recoverGame(Game *game){
    recoverPlayer(&game->player);
    recoverArray(&game->map);
    recoverTimer(&game->timer);
}