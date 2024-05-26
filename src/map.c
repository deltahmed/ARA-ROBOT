/**
 * @file map.c
 * @author Ahmed A., Rayane M., Abdelwaheb A.
 * @brief Map related functions/methods
 * @version 1.0
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "map.h"

/**
 * @brief Sets the width and the height of the map.
 * @param x The width vlalue.
 * @param y The height value.
 * @param self Pointer to self.
 */
static void __set_size(Map* self, Size x, Size y){
    self->__sizex = x;
    self->__sizey = y;
}

/**
 * @brief Gets the width of the map.
 * 
 * @param self Pointer to self.
 * @return The width of the map.
 * @throw raise EMPTY_OBJ_ERROR if map is NULL
 */
static Size __get_size_x(Map* self){
    if (self->__map == NULL){
        ARA_error(EMPTY_OBJ_ERROR);
    }
    return self->__sizex;
}

/**
 * @brief Gets the height of the map.
 * 
 * @param self Pointer to self.
 * @return The height of the map.
 * @throw raise EMPTY_OBJ_ERROR if map is NULL
 */
static Size __get_size_y(Map* self){
    if (self->__map == NULL){
        ARA_error(EMPTY_OBJ_ERROR);
    }
    return self->__sizey;
}

/**
 * @brief Gets the value at a specified position.
 * 
 * @param self Pointer to self.
 * @param x The x coordinate of the value.
 * @param y The y coordinate of the value.
 * @return The value at the specified position.
 * @throw raise EMPTY_OBJ_ERROR if map is NULL
 */
static int __get_map(Map* self, int x, int y){
    if (self->__map == NULL){
        ARA_error(EMPTY_OBJ_ERROR);
    }
    return self->__map[mod(y, self->sizey(self))][mod(x, self->sizex(self))];
}

/**
 * @brief Sets the value at a specified position.
 * 
 * @param self Pointer to self.
 * @param x The x coordinate of the value.
 * @param y The y coordinate of the value.
 * @param value The value to set.
 * @throw raise EMPTY_OBJ_ERROR if map is NULL
 */
static void __set_map(Map* self, int x, int y, int value){
    if (self->__map == NULL){
        ARA_error(EMPTY_OBJ_ERROR);
    }
    self->__map[mod(y, self->sizey(self))][mod(x, self->sizex(self))] = value;
}

/**
 * @brief Destroys the map, free all allocated resources.
 * 
 * @param self Pointer to self.
 * @throw raise ALREADY_DESTROYED_ERROR if map is NULL
 */
static void __destroy_map(Map* self){
    if (self->__map == NULL){
        ARA_error(ALREADY_DESTROYED_ERROR);
    }
    for (Size i = 0; i < self->sizey(self); i++)
    {
        free(self->__map[i]);
    }
    free(self->__map);
    __set_size(self, 0, 0);
    self->__map = NULL;
}

/**
 * @brief Initializes the Map structure.
 *
 * @param self Pointer to self.
 * @throw raise ALLOCATION_ERROR allocation fails
 */
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