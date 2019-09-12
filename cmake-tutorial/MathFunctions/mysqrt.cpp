#include "MathFunctions.h"
#include <stdio.h>
#include <stdlib.h>

double mysqrt(double x) {
    if (x <= 0) {
        return 0;
    }

    double result = x;

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
    return result;
}