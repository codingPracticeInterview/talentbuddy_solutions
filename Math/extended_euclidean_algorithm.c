#include <stdio.h>
#include <math.h>

typedef long int INT64;
/*
 * This is used evaulate the coefficient of (x, y) of 
 * gcd(a, b) = a * x + b * y;
 */

INT64 x_coeff, y_coeff;
INT64 eval_coeff(INT64 a, INT64 b)
{
    INT64 d, temp, gcd;
    if (b == 0) {
        x_coeff = 1;
        y_coeff = 0;
        //printf("1. x = %ld, y = %ld\n", x_coeff, y_coeff);/* DEBUG PRINT */
        return a;
    } else {
        gcd = eval_coeff(b, a % b);
        temp = y_coeff;
        y_coeff = (x_coeff - (floor((double)a / (double)b) * y_coeff)); 
        x_coeff = temp;
        //printf("2. x = %ld, y = %ld\n", x_coeff, y_coeff);/* DEBUG PRINT */
        return gcd;
    }
}

int main(int argc, char *argv[])
{
    INT64 gcd;
    INT64 a, b;

    printf("Input a: \n");
    scanf("%ld", &a);

    printf("Input b: \n");
    scanf("%ld", &b);

    gcd = eval_coeff(a, b);

    printf("GCD: %ld, X-coeff: %ld, Y-coeff: %ld\n", gcd, x_coeff, y_coeff);
    return 0;
}
