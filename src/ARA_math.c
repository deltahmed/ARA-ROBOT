
#include "ARA_math.h"
#include <math.h>

int mod(int a, int b){
    int r = a % b;
    return r < 0 ? r + b : r;
}
