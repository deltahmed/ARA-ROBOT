#ifndef PLAYER_H
#define PLAYER_H

#include "map.h"
#include "ARA_debug.h"
#include "ARA_error.h"

#define MAX_INVENTORY 8
#define MAX_COUNT_INV 64
#define MAX_LIFE 110
#define MAX_NAME 100

/**
 * @brief Structure representing a player its properties and methods.
 */
typedef struct __player_struct
{
    int __x;
    int __y;
    int __life;
    int __name[100];
    int __inventory[MAX_INVENTORY];
    int __inventory_count[MAX_INVENTORY];
    int __inv_index;
    int __vision;
    int __speed;
    int __xp;
    /**
     * @brief Gets the x coordinate of the player.
     * 
     * @param self Pointer to self.
     * @return The x coordinate of the player.
     */
    int (*get_x)(struct __player_struct* self);

    /**
     * @brief Gets the y coordinate of the player . 
     * 
     * @param self Pointer to self.
     * @return The y coordinate of the player  .
     */
    int (*get_y)(struct __player_struct* self);

    /**
     * @brief Gets the life value of the player  .
     * 
     * @param self Pointer to self.
     * @return The life value of the player  .
     */
    int (*get_life)(struct __player_struct* self);

    /**
     * @brief sets the life value of the player  .
     * 
     * @param self Pointer to self.
     */
    void (*set_life)(struct __player_struct* self, int value);

    /**
     * @brief Sets the x coordinate of the player  .
     * 
     * @param self Pointer to self.
     * @param x The new x coordinate of the player  .
     */
    void (*set_x)(struct __player_struct* self, int x);

    /**
     * @brief Sets the y coordinate of the player  .
     * 
     * @param self Pointer to self.
     * @param y The new y coordinate of the player  .
     */
    void (*set_y)(struct __player_struct* self, int y);

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
    void (*use_object)(struct __player_struct* self, int index);

    /**
     * @brief Adds an item to the player inventory.
     *
     * If the item already exists in the inventory, it increases its count. if not it add  the item to the first available slot.
     *
     * @param self Pointer to self..
     * @param object The item.
     * @throw VALUE_ERROR if __inv_index not in range.
     */
    void (*add_object)(struct __player_struct* self, Map_def object);


}Player;

void Init_Player(Player* self);


#endif