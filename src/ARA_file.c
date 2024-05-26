#include "ARA_file.h"

void saveArray(Game *game){
    FILE *fichier=NULL;
    Size i=0;
    char name[MAX_FILE_NAME];
    sprintf(name,"data/%smap.bin",game->player.__name);
    fichier=fopen(name,"wb");
    //S'il n'est pas deja cree il sera creer tout seul parce que j'utilise le mode "wb"
    if(fichier==NULL){
        ARA_error(FILE_ERROR);
    }
    for(i = 0; i < game->map.sizey(&game->map); i++){
        fwrite(game->map.__map[i],sizeof(int),game->map.sizex(&game->map),fichier);
    }
    fclose(fichier);
}

void recoverArray(Game *game){
    FILE *fichier=NULL;
    Size i=0;
    char name[MAX_FILE_NAME];
    sprintf(name,"data/%smap.bin",game->player.__name);
    fichier=fopen(name,"rb");
    if(fichier==NULL){
        ARA_error(FILE_ERROR);
    }
    for (i = 0; i < game->map.sizey(&game->map); i++)
    {
        fread(game->map.__map[i],sizeof(int),game->map.sizex(&game->map),fichier);
    }
    fclose(fichier);
}

void savePlayer(Game *game){
    char name[MAX_FILE_NAME];
    sprintf(name,"data/%splayer.bin",game->player.__name);
    FILE *fichier = fopen(name, "wb");
    if(fichier == NULL){
        ARA_error(FILE_ERROR);
    }
    fwrite(&game->player.__x, sizeof(int), 1, fichier);
    fwrite(&game->player.__y, sizeof(int), 1, fichier);
    fwrite(&game->player.__life, sizeof(char), 1, fichier);
    fwrite(&game->player.__vision, sizeof(int), 1, fichier);
    fwrite(&game->player.__xp, sizeof(int), 1, fichier);
    fwrite(&game->player.__inv_index, sizeof(int), 1, fichier);
    fwrite(&game->player.__inventory, sizeof(int), MAX_INVENTORY, fichier);
    fwrite(&game->player.__inventory_count, sizeof(int), MAX_INVENTORY, fichier);
    fclose(fichier);
}

void recoverPlayer(Game *game){
    char name[MAX_FILE_NAME];
    sprintf(name,"data/%splayer.bin",game->player.__name);
    FILE *fichier = fopen(name, "rb");
    if(fichier == NULL){
        ARA_error(FILE_ERROR);
    }
    fread(&game->player.__x, sizeof(int), 1, fichier);
    fread(&game->player.__y, sizeof(int), 1, fichier);
    fread(&game->player.__life, sizeof(char), 1, fichier);
    fread(&game->player.__vision, sizeof(int), 1, fichier);
    fread(&game->player.__xp, sizeof(int), 1, fichier);
    fread(&game->player.__inv_index, sizeof(int), 1, fichier);
    fread(&game->player.__inventory, sizeof(int), MAX_INVENTORY, fichier);
    fread(&game->player.__inventory_count, sizeof(int), MAX_INVENTORY, fichier);
    fclose(fichier);
}

void saveTimer(Game *game){
    char name[MAX_FILE_NAME];
    sprintf(name,"data/%stimer.bin",game->player.__name);
    FILE *fichier = fopen(name, "wb");
    if(fichier == NULL){
        ARA_error(FILE_ERROR);
    }
    fwrite(&game->timer.__actual_time, sizeof(Time), 1, fichier);
    fwrite(&game->timer.__paused, sizeof(boolean), 1, fichier);
    fwrite(&game->timer.__start_game_time, sizeof(Time), 1, fichier);
    fwrite(&game->timer.__timer, sizeof(Time), 1, fichier);
    fclose(fichier);
    //Quand je mets &self->get_x(&self) au lieu de &self->__x ca marche pas car la fonction est definie dans la structure avec une * 
}

void recoverTimer(Game *game){
    char name[MAX_FILE_NAME];
    sprintf(name,"data/%stimer.bin",game->player.__name);
    FILE *fichier = fopen(name, "rb");
    if(fichier == NULL){
        ARA_error(FILE_ERROR);
    }
    fread(&game->timer.__actual_time, sizeof(Time), 1, fichier);
    fread(&game->timer.__paused, sizeof(boolean), 1, fichier);
    fread(&game->timer.__start_game_time, sizeof(Time), 1, fichier);
    fread(&game->timer.__timer, sizeof(Time), 1, fichier);
    //Une piste pour resoudre le probleme d heure apres un recover est d enlever le premier et troisieme fread
    fclose(fichier);
}

void saveGame(Game *game){
    savePlayer(game);
    saveArray(game);
    saveTimer(game);
    char name[MAX_FILE_NAME];
    sprintf(name,"data/%sgameconst.bin",game->player.__name);
    FILE *fichier = fopen(name, "wb");
    if(fichier == NULL){
        ARA_error(FILE_ERROR);
    }
    fwrite(&game->nb_end_tasks, sizeof(int), 1, fichier);
    fwrite(&game->nb_gen_room, sizeof(int), 1, fichier);
    fwrite(&game->nb_room, sizeof(int), 1, fichier);
    fwrite(&game->nb_tasks, sizeof(int), 1, fichier);
    //Je ne peux pas enregistrer toute la structure d'un coup car dans toutes les structures il y a des pointeurs (l'entete des fonctions) qui font buguer le fichier
    //Donc il faut le faire manuellement pour chaque structure
    fclose(fichier);
}

void recoverGame(Game *game){
    recoverPlayer(game);
    recoverArray(game);
    recoverTimer(game);
    char name[MAX_FILE_NAME];
    sprintf(name,"data/%sgameconst.bin",game->player.__name);
    FILE *fichier = fopen(name, "rb");
    if(fichier == NULL){
        ARA_error(FILE_ERROR);
    }
    fread(&game->nb_end_tasks, sizeof(int), 1, fichier);
    fread(&game->nb_gen_room, sizeof(int), 1, fichier);
    fread(&game->nb_room, sizeof(int), 1, fichier);
    fread(&game->nb_tasks, sizeof(int), 1, fichier);
    fclose(fichier);
}