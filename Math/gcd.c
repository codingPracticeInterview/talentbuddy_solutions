#include <stdio.h>
#include <stdlib.h>

int gcd_recur(a, b) {
	if(b == 0) {
		return a;
	}
	
	return gcd_recur(b, a%b);
}

int gcd_iter(a , b) {

	int temp = 0;
	
	while (b != 0) {
		temp = a%b;
		a = b; 
		b = temp;
	}
	
	return a;
}

int main () {
	int a = 0, b = 0, gcd = 0;
	
	printf("Enter two numbers \n");
	
	scanf("%d %d", &a, &b);
	
	gcd = gcd_recur(a, b);
	
	printf("Recursive GCD of %d and %d = %d\n", a, b, gcd);
	
	gcd = gcd_iter(a, b);
	
	printf("Iterative GCD of %d and %d = %d\n", a, b, gcd);
	
	return 0;
}
		