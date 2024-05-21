#ifndef PLAYER_H
#define PLAYER_H

#include "map.h"

#define MAX_INVENTORY 9
#define MAX_LIFE 100

/**
 * @brief Structure representing a player its properties and methods.
 */
typedef struct __player_struct
{
    int __x;
    int __y;
    char __life;
    int __inventory[MAX_INVENTORY];
    int __inventory_count[MAX_INVENTORY];
    int __inv_index;

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

    void (*use_object)(struct __player_struct* self, int index);

    void (*add_object)(struct __player_struct* self, Map_def object);


}Player;

void Init_Player(Player* self);


#endif