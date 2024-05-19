#ifndef PLAYER_H
#define PLAYER_H

#include "map.h"

/**
 * @brief Structure representing a player its properties and methods
 */
typedef struct __player_struct
{
    int __x;
    int __y;
    char __life;

    /**
     * @brief Gets the x coordinate of the player
     * 
     * @param self Pointer to self
     * @return The x coordinate of the player  
     */
    int (*get_x)(struct __player_struct* self);

    /**
     * @brief Gets the y coordinate of the player  
     * 
     * @param self Pointer to self
     * @return The y coordinate of the player  
     */
    int (*get_y)(struct __player_struct* self);

    /**
     * @brief Gets the life value of the player  
     * 
     * @param self Pointer to self
     * @return The life value of the player  
     */
    int (*get_life)(struct __player_struct* self);

    /**
     * @brief Sets the x coordinate of the player  
     * 
     * @param self Pointer to self
     * @param x The new x coordinate of the player  
     */
    void (*set_x)(struct __player_struct* self, int x);

    /**
     * @brief Sets the y coordinate of the player  
     * 
     * @param self Pointer to self
     * @param y The new y coordinate of the player  
     */
    void (*set_y)(struct __player_struct* self, int y);
}Player;

void Init_Player(Player* self);


#endif