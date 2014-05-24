/*Missing number
 Given an array containing all numbers from 1 to N with the exception of one print the missing number to the standard output.
 Example input:
 array: 5 4 1 2
 Example output: 3
 Note: This challenge was part of Microsoft interviews. The expected complexity is O(N).
 */
 
 #include <stdio.h>

void find_missing_number(int *v, int v_length) {
    // Write your code here
   int a[v_length+1];
   int i;
    
   for(i =1; i <= v_length; i++) {
           a[v[i]] = 0xff;
   }
    for(i=1; i<= v_length ; i++) {
        if(a[i] != 0xff) {
            printf("%d\n",i);
            break;
        }
    }
      
    // To print results to the standard output you can use printf()
    // Example: printf("%s", "Hello world!");
}
