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
 * @brief sets the life value of the player  .
 * 
 * @param self Pointer to self.
 */
static int __set_life(Player* self, int value){
    self->__life = stick_in_range(value, 0, MAX_LIFE);
}

static void __rearenge_tab(Player* self){
   self->__inv_index;
    int new_index = 0;
    for (int i=0; i < MAX_INVENTORY; i++){
        if (self-> __inventory[i] != 0){
            self->__inventory[new_index] = self-> __inventory[i];
            self->__inventory_count[new_index]= self->__inventory_count[i];
            new_index++;
        }
    }
    for (int i = new_index; i < MAX_INVENTORY; i++){
    self-> __inventory[i] = 0;
    self-> __inventory_count[i] = 0;
   }
}

static void __use_object(Player* self, int index){
    if (index < 0 || index > MAX_INVENTORY)
    {
        ARA_error(VALUE_ERROR);
    }

    self->__inventory_count[index]--;
    if (self-> __inventory_count[index] == 0){ //je pars du principe que la case est déjà vide
        self->__inventory[index] = 0;
    }
    __rearenge_tab(self);
}

static void __add_object(Player* self, Map_def object){
   
    
}

/**
 * @brief Initializes the Player structure.
 *
 * @param self Pointer to self.
 */
void Init_Player(Player* self){
    self->__x = MAP_SIZE_X/2;
    self->__y = MAP_SIZE_Y/2;
    __set_life(self, MAX_LIFE/2);
    self->__inv_index = 0;

    self->get_x = __get_x;
    self->get_y = __get_y;
    self->get_life = __get_life;
    self->set_x = __set_x;
    self->set_y = __set_y;
    self->add_object = __add_object;
    self->use_object = __use_object;
    self->set_life = __set_life;

}