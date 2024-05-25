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
static __set_life(Player* self, int value){
    self->__life = stick_in_range(value, 0, MAX_LIFE);
}

/**
 * @brief Rearranges the player's inventory to remove empty slots.
 *
 * @param self Pointer to self.
 */
static void __rearenge_tab(Player* self){
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

/**
 * @brief Uses an item from the player's inventory.
 *
 * removes teh item it if the count reaches zero.
 * It then rearranges the inventory to remove any empty slots.
 *
 * @param self Pointer to self.
 * @param index Index of the item.
 * @throw VALUE_ERROR if index not in range.
 */
static void __use_object(Player* self, int index){
    if (index < 0 || index > MAX_INVENTORY)
    {
        ARA_error(VALUE_ERROR);
    }

    self->__inventory_count[index]--;
    if (self-> __inventory_count[index] <= 0){ 
        self->__inventory[index] = 0;
        self-> __inventory_count[index] = 0;
    }
    __rearenge_tab(self);
}

/**
 * @brief Adds an item to the player inventory.
 *
 * If the item already exists in the inventory, it increases its count. if not it add  the item to the first available slot.
 *
 * @param self Pointer to self..
 * @param object The item.
 * @throw VALUE_ERROR if __inv_index not in range.
 */
static void __add_object(Player* self, Map_def object){
    if (self-> __inv_index >= MAX_INVENTORY){
        ARA_error(VALUE_ERROR);
    }
    for (int i= 0; i < MAX_INVENTORY; i++){
        if(self->__inventory[i]== (int)object){
            self->__inventory_count[i]++;
            if (self->__inventory_count[i] > MAX_COUNT_INV)
            {
                self->__inventory_count[i] = MAX_COUNT_INV;
            }
            return;
        }
    }
    self->__inventory[self->__inv_index] = object;
    self->__inventory_count[self->__inv_index] = 1;
    self->__inv_index++;
}

/**
 * @brief Initializes the Player structure.
 *
 * @param self Pointer to self.
 */
void Init_Player(Player* self){
    self->__x = MAP_SIZE_X/2;
    self->__y = MAP_SIZE_Y/2;
    __set_life(self, MAX_LIFE-20);
    self->__inv_index = 0;
    for (size_t i = 0; i < MAX_INVENTORY; i++)
    {
        self->__inventory[i] = 0;
        self->__inventory_count[i] = 0;
    }
    

    self->get_x = __get_x;
    self->get_y = __get_y;
    self->get_life = __get_life;
    self->set_x = __set_x;
    self->set_y = __set_y;
    self->add_object = __add_object;
    self->use_object = __use_object;
    self->set_life = __set_life;
    self->__inv_index = 0;
    self->__vision = 0;
    self->__speed = 1;
    self->__xp = 0;

}