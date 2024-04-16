
#include "map.h"

void __set_size(Map* self, Size x, Size y){
    self->__sizex = x;
    self->__sizey = y;
}


Size __get_size_x(Map* self){
    if (self->__map == NULL){
        ARA_error(DESTROYED);
    }
    return self->__sizex;
}

Size __get_size_y(Map* self){
    if (self->__map == NULL){
        ARA_error(DESTROYED);
    }
    return self->__sizey;
}

int __get_map(Map* self, int x, int y){
    if (self->__map == NULL){
        ARA_error(DESTROYED);
    }
    return self->__map[mod(y, self->sizey(self))][mod(x, self->sizex(self))];
}

void __set_map(Map* self, int x, int y, int value){
    if (self->__map == NULL){
        ARA_error(DESTROYED);
    }
    self->__map[mod(y, self->sizey(self))][mod(x, self->sizex(self))] = value;
}

void __destroy_map(Map* self){
    if (self->__map == NULL){
        ARA_error(ALREADY_DESTROYED);
    }
    for (Size i = 0; i < self->sizey(self); i++)
    {
        free(self->__map[i]);
    }
    free(self->__map);
    __set_size(self, 0, 0);
    self->__map = NULL;
}

void Map_init(Map* self, Size sizex, Size sizey){
    __set_size(self, sizex, sizey);
    self->__map = (int**)calloc(sizey, sizeof(int*));
    if (self->__map == NULL){
        ARA_error(ALLOCATION_ERROR);
    }
    for (Size i = 0; i < sizey; i++)
    {
        self->__map[i] = (int*)calloc(sizex, sizeof(int));
        if (self->__map[i] ==NULL){
            ARA_error(ALLOCATION_ERROR);
        }
    }
    self->get = __get_map;
    self->set = __set_map;
    self->sizex = __get_size_x;
    self->sizey = __get_size_y;
    self->destroy = __destroy_map;
    
}