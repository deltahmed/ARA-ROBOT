#ifndef MAP
#define MAP
#include "ARA_def.h"
#include "ARA_window.h"

/**
 * @brief MAP size definitions.
 */
#define MAP_SIZE_X 100
#define MAP_SIZE_Y 100

/**
 * @brief a definition of Size (unsigned int (uint32)).
 */
typedef uint32_t Size;

/**
 * @brief All possible values in the map.
 */

typedef enum map_def_enum{
    MAP_NONE,
    MAP_VOID,
    MAP_ALL,
    MAP_WALL,
    MAP_ROOM,
    MAP_FUTURE_ROOM,
    MAP_DOOR_NORTH,
    MAP_DOOR_EAST,
    MAP_DOOR_WEST,
    MAP_DOOR_SOUTH,
    MAP_UNDISCOVERED_DOOR_NORTH,
    MAP_UNDISCOVERED_DOOR_EAST,
    MAP_UNDISCOVERED_DOOR_WEST,
    MAP_UNDISCOVERED_DOOR_SOUTH,
    MAP_END_OF_BLOCK,
    MAP_TASK,
    MAP_MONSTER,
}Map_def;

/**
 * @brief Structure representing a map its properties and methods.
 */
typedef struct __map_struct{
    int** __map;
    Size __sizex;
    Size __sizey;
    
    /**
     * @brief Gets the width of the map.
     * 
     * @param self Pointer to self.
     * @return The width of the map.
     */
    Size (*sizex)(struct __map_struct* self);
    
    /**
     * @brief Gets the height of the map.
     * 
     * @param self Pointer to self.
     * @return The height of the map.
     */
    Size (*sizey)(struct __map_struct* self);
    
    /**
     * @brief Gets the value at a specified position.
     * 
     * @param self Pointer to self.
     * @param x The x coordinate of the value.
     * @param y The y coordinate of the value.
     * @return The value at the specified position.
     */
    int (*get)(struct __map_struct* self, int x, int y);
    
    /**
     * @brief Sets the value at a specified position.
     * 
     * @param self Pointer to self.
     * @param x The x coordinate of the value.
     * @param y The y coordinate of the value.
     * @param value The value to set.
     */
    void (*set)(struct __map_struct* self, int x, int y, int value);
    
    /**
     * @brief Destroys the map, free all allocated resources.
     * 
     * @param self Pointer to self.
     */
    void (*destroy)(struct __map_struct* self);
} Map;

void Map_init(Map* self, Size sizex, Size sizey);


#endif