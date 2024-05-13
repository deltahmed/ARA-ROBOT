
#include "ARA_math.h"


int mod(int a, int b){
    int r = a % b;
    return r < 0 ? r + b : r;
}
int max(int a, int b){
    return a < b ? b : a;
}
int min(int a, int b){
    return a > b ? b : a;
}

int randint(int a, int b){
    return a + rand()%(b-a);
}