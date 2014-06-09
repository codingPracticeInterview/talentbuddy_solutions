#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define ARRAY_SIZE	100000

void swap(int *a, int *b) {
	int tmp = 0;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
	
}

void selection_sort(int *input_arr, int length) {
	int i, j, min_idx = 0;
	
	for(i = 0; i < (length - 1); i++) {	
		min_idx = i;	
		for(j = i+1; j < length; j++) {
			if(input_arr[j] < input_arr[min_idx]) {
				min_idx = j;
			}
		}
		
		swap(&input_arr[i], &input_arr[min_idx]);
	}
}

int main(void) {
	int *in_arr;
	unsigned int idx, arr_len;
	FILE *fp;
	char *file_name = "IntegerArray.txt";
	unsigned long long int  start_us = 0, end_us = 0;
	struct timeval tv;
	
	arr_len = ARRAY_SIZE;
	in_arr = malloc(arr_len * sizeof(int));
	
	fp = fopen(file_name, "r");
	
	for(idx = 0; idx < arr_len; idx++) {
		fscanf(fp, "%d",&in_arr[idx]);
	}
	
	gettimeofday(&tv,NULL);
	start_us = 1000000 * tv.tv_sec + tv.tv_usec;
	
	selection_sort(in_arr, arr_len);
	
	gettimeofday(&tv,NULL);
	end_us = 1000000 * tv.tv_sec + tv.tv_usec;
	
	
	printf("Sorted Array of %d elements\n",arr_len);
	
	for(idx = 0; idx < arr_len; idx++) {
		printf("%d\n",in_arr[idx]);
	}
	
	printf("\nStart-us: %llu, End-us: %llu, Exec_time-us: %llu\n", start_us, end_us, (end_us - start_us));
	
	free(in_arr);
	
	return 0;
}