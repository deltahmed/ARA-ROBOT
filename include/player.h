#ifndef PLAYER_H
#define PLAYER_H

typedef struct __player_struct
{
    int __x;
    int __y;
    char __life;

    int* __inventory;
    int (*get_x)(struct __player_struct* self);
    int (*get_y)(struct __player_struct* self);
    int (*get_life)(struct __player_struct* self);
    int (*set_x)(struct __player_struct* self, int x);
    int (*set_y)(struct __player_struct* self, int y);
}Player;

int __get_x(Player* self){
    return self->__x;
}
int __get_y(Player* self){
    return self->__y;
}
void __set_x(Player* self, int x){
    self->__x = x;
}
void __set_y(Player* self, int y){
    self->__y = y;
}

int __get_life(Player* self){
    return self->__life;
}


Player Init_Player(){
    Player self;
    self.__x = 1;
    self.__y = 1;
    self.__life = 100;

    self.get_x = __get_x;
    self.get_y = __get_y;
    self.get_life = __get_life;
    self.set_x = __set_x;
    self.get_y = __set_y;

}



#endif