#include "my_math.h"

long mypow(int a, int b) {
    long x = 1;
    for (int i = 0; i < b; i++)
    {
        x *= a;
    }
    return x;
}