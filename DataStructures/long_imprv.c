#include <stdio.h>

void longest_improvement(int *grades, int grades_length) {
    int idx = 0, count_imprv = 1, long_imprv = 1;
    
    for (idx = 1 ; idx < grades_length; idx++) {
        if(grades[idx] >= grades[idx-1]) {
            count_imprv++;
            if(count_imprv > long_imprv) {
                long_imprv = count_imprv;
            }
        } else {
            count_imprv = 1;
        }
    }
    
    printf("%d\n", long_imprv);
}

int main() {
    int grades[] = {1, 2, 3, 4, 5, 6, 7, 8};
    
    longest_improvement(grades,8);
}