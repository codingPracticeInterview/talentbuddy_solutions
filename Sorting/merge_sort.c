#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define ARRAY_SIZE	100000

void merge(int *input_arr, int *aux_arr, int low, int mid, int high) {
	int lidx, hidx, ridx;
	
	//printf("%d %d %d\n", low, mid, high);
	
	/* Copy the contents of the input array into the aux array */
	for(ridx = low; ridx <= high; ridx++) {
		aux_arr[ridx] = input_arr[ridx];
	}
	
	lidx = low;
	hidx = mid +1;
	
	for(ridx = low; ridx <= high; ridx++) {
		if(lidx > mid) {
			input_arr[ridx] = aux_arr[hidx++];
		} else if(hidx > high) {
			input_arr[ridx] = aux_arr[lidx++];
		} else if(aux_arr[lidx] < aux_arr[hidx]) {
			input_arr[ridx] = aux_arr[lidx++];
		} else {
			input_arr[ridx] = aux_arr[hidx++];
		}
		
		//printf("%d ", input_arr[ridx]);
	}
	//printf("\n");
	
}

void merge_sort(int *input_arr, int *aux_arr, int low, int high) {
		int mid = (low + high)/2;

		if(high > low) {
			merge_sort(input_arr, aux_arr, low, mid);
			merge_sort(input_arr, aux_arr, (mid+1), high);
			merge(input_arr, aux_arr, low, mid, high);
		}
}

int main(void) {
	int *in_arr, *aux_arr;
	unsigned int idx, arr_len;
	FILE *fp;
	char *file_name = "IntegerArray.txt";
	unsigned long long int  start_us = 0, end_us = 0;
	struct timeval tv;
	
	arr_len = ARRAY_SIZE;
	in_arr = malloc(arr_len * sizeof(int));
	aux_arr = malloc(arr_len * sizeof(int));
	
	fp = fopen(file_name, "r");
	
	for(idx = 0; idx < arr_len; idx++) {
		fscanf(fp, "%d",&in_arr[idx]);
	}
	
	gettimeofday(&tv,NULL);
	start_us = 1000000 * tv.tv_sec + tv.tv_usec;
	
	merge_sort(in_arr, aux_arr, 0, (arr_len - 1));
	
	gettimeofday(&tv,NULL);
	end_us = 1000000 * tv.tv_sec + tv.tv_usec;
	
	
	printf("Sorted Array of %d elements\n",arr_len);
	
	for(idx = 0; idx < arr_len; idx++) {
		printf("%d\n",in_arr[idx]);
	}
	
	printf("\nStart-us: %llu, End-us: %llu, Exec_time-us: %llu\n", start_us, end_us, (end_us - start_us));
	
	free(in_arr);
	free(aux_arr);
	
	return 0;
}
	