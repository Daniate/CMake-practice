#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h"
#ifdef USE_MYMATH
    #include "MathFunctions.h"
#endif // USE_MYMATH

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        fprintf(stdout, "%s Version %d.%d\n", argv[0], Tutorial_VERSION_MAJOR, Tutorial_VERSION_MINOR);
        fprintf(stdout, "Usage: %s number\n", argv[0]);
        return EXIT_FAILURE;
    }
    double inputValue = atof(argv[1]);
#ifdef USE_MYMATH
    fprintf(stdout, "Using custom sqrt function.\n");
    double outputValue = mysqrt(inputValue);
#else
    fprintf(stdout, "Using sqrt function in math library.\n");
    double outputValue = sqrt(inputValue);
#endif // USE_MYMATH
    
    fprintf(stdout, "The square root of %f is %f\n", inputValue, outputValue);
    return EXIT_SUCCESS;
}
