#include "TutorialConfig.h"
#include "MathFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#if defined(EXISTS_LOG) && defined(EXISTS_EXP)
    #include <math.h>
#endif

double mysqrt(double x) {
    if (x <= 0) {
        return 0;
    }

    double result = x;
#if defined(EXISTS_LOG) && defined(EXISTS_EXP)
    printf("EXISTS_LOG && EXISTS_EXP is true.\n");
    result = exp(log(x) * 0.5);
#else
    double r2 = 0;
    do
    {
        if (result <= 0) {
            result = 0.1;
        }
        r2 = result * result;
        double delta = x - r2;
        result = result + 0.5 * delta / result;
        printf("Computing sqrt of %f to be %f\n", x, result);
    } while (r2 < x - 0.000001 || r2 > x + 0.000001);
#endif // defined(EXISTS_LOG) && defined(EXISTS_EXP)
    return result;
}