#include "ARA_debug.h"


void ARA_debug_message(const char * file, const char * function, int line){
    FILE* logs = fopen(FILE_LOGS, "a");
    fprintf(logs,"\nfile : %s func : %s line :%d",file, function, line);
    fclose(logs);
}

void ARA_debug_message_value(int value, const char * file, const char * function, int line){
    FILE* logs = fopen(FILE_LOGS, "a");
    fprintf(logs,"\nfile : %s func : %s line :%d value: %d",file, function, line, value);
    fclose(logs);
}

void log_reset(){
    FILE* logs = fopen(FILE_LOGS, "w");
    fclose(logs);
}