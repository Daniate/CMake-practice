#include "config.h"

#include <stdio.h>
#include <stdlib.h>

#ifdef USE_MY_MATH
#include "math/my_math.h"
#else
#include <math.h>
#endif

int main(int argc, const char *argv[]) {
    #ifdef USE_MY_MATH
        printf("使用自己的数学库 %ld\n", mypow(2, 3));
    #else
        printf("使用C标准数学库 %f\n", pow(2, 3));
    #endif
    return EXIT_SUCCESS;
}
