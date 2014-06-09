#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <stdio.h>
#include <math.h>

double fast_expo(int base, int exponent) {
	double result = 0;
	
	if (exponent == 0) {
		return 1;
	}
	
	result = fast_expo(base, (exponent/2));
	
	printf("%d %lF\n",exponent, result);
	
	/* Even Exponent */
	if ((exponent % 2) == 0) {
		return((double)result * (double)result);
	} else {
	/* Odd exponent */
		return((double)base * (double)result * (double)result);
	}
}		
		

int main(void) {
	double result;
	int base, exponent;
	
	printf("Input Base and Exponent\n");
	scanf("%d %d",&base, &exponent);
	
	result = fast_expo(base, exponent);
	
	printf("Math -- %d power %d = %lf\n", base, exponent, pow((double) base, (double) exponent));
	
	printf("%d power %d = %lf\n",base, exponent, result);
	
	return 0;
}
	