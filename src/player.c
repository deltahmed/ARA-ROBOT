#include "player.h"


static int __get_x(Player* self){
    return self->__x;
}
static int __get_y(Player* self){
    return self->__y;
}
static void __set_x(Player* self, int x){
    self->__x = x;
}
static void __set_y(Player* self, int y){
    self->__y = y;
}

static int __get_life(Player* self){
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
    self.set_y = __set_y;
    return self;

}