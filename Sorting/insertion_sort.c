#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define ARRAY_SIZE	100000

void insertion_sort(int *arr, int length)
{
    for (int i = 1; i < length; i++)
    {
        /* a temporary copy of the current element */
        int tmp = arr[i];
        int j;
 
        /* find the position for insertion */
        for (j = i; j > 0; j--)
        {
            if (arr[j - 1] < tmp)
                break;
            /* shift the sorted part to right */
            arr[j] = arr[j - 1];
        }
 
        /* insert the current element */
        arr[j] = tmp;
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
	
	insertion_sort(in_arr, arr_len);
	
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