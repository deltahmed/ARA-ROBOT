#include "player.h"

/**
 * @brief Gets the x coordinate of the player.
 * 
 * @param self Pointer to self.
 * @return The x coordinate of the player.
 */
static int __get_x(Player* self){
    return self->__x;
}
/**
 * @brief Gets the y coordinate of the player . 
 * 
 * @param self Pointer to self.
 * @return The y coordinate of the player  .
 */
static int __get_y(Player* self){
    return self->__y;
}

/**
 * @brief Sets the x coordinate of the player  .
 * 
 * @param self Pointer to self.
 * @param x The new x coordinate of the player  .
 */
static void __set_x(Player* self, int x){
    self->__x = x;
}
/**
 * @brief Sets the y coordinate of the player  .
 * 
 * @param self Pointer to self.
 * @param y The new y coordinate of the player  .
 */
static void __set_y(Player* self, int y){
    self->__y = y;
}

/**
 * @brief Gets the life value of the player  .
 * 
 * @param self Pointer to self.
 * @return The life value of the player  .
 */
static int __get_life(Player* self){
    return self->__life;
}

/**
 * @brief Initializes the Player structure.
 *
 * @param self Pointer to self.
 */
void Init_Player(Player* self){
    self->__x = MAP_SIZE_X/2;
    self->__y = MAP_SIZE_Y/2;
    self->__life = 100;

    self->get_x = __get_x;
    self->get_y = __get_y;
    self->get_life = __get_life;
    self->set_x = __set_x;
    self->set_y = __set_y;

}