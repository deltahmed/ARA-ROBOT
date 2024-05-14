#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h> 
#include <stdlib.h>
#include "ARA_def.h"


#define log() (ARA_debug_message(__FILE__,  __FUNCTION__, __LINE__))

void ARA_debug_message(const char * file, const char * function, int line);
void log_reset();


#endif