/**
 * @file ARA_debug.h
 * @author Ahmed A., Rayane M., Abdelwaheb A. ()
 * @brief debug file header
 * @version 1.0
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h> 
#include <stdlib.h>
#include "ARA_def.h"

/**
 * @brief this macro call ARA_debug_message with the needed arguments.
 */
#define log() (ARA_debug_message(__FILE__,  __FUNCTION__, __LINE__))

/**
 * @brief This macro calls ARA_debug_message_value with the necessary arguments to log an integer value along with the file name, function name, and line number.
 * 
 * @param value The value logged.
 */
#define intlog(value) (ARA_debug_message_value(value, __FILE__,  __FUNCTION__, __LINE__))

void ARA_debug_message(const char * file, const char * function, int line);
void ARA_debug_message_value(int value, const char * file, const char * function, int line);
void log_reset();


#endif