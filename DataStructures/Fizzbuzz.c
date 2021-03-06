/*
* Your task is to
 write a function that prints to the standard output (stdout) the numbers from 1 to N (one per line) with the following restrictions
 for multiples of three print “Fizz” instead of the number for the multiples of five print “Buzz” instead of the number
for numbers which are multiples of both three and five print “FizzBuzz”
Note that your function will receive the following arguments: n
which is the integer number described above
Data constraints
the maximum value of N will not exceed 1000
Efficiency constraints
your function is expected to print the result in less than 2 seconds
Example
Input	Output
n: 15
 1
 2
 Fizz
 4
 Buzz
 Fizz
 7
 8
 Fizz
 Buzz
 11
 Fizz
 13
 14
  FizzBuzz
*/

#include <stdio.h>

void fizzbuzz(int n) {
    // Write your code here
    int i;
    for(i =1; i<=n; i++) {
        if((i%3 == 0) && !(i%5 == 0)) {
            printf("Fizz\n");
        }else if ((i%5 == 0) && !(i%3 == 0)) {
            printf("Buzz\n");
        }else if( (i%5 == 0) && (i%3 == 0)) {
            printf("FizzBuzz\n");
        }else {
            printf("%d\n", i);
        }
    }
}
