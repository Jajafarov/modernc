#include <stdlib.h>
#include <stdio.h>

void merge(int *arr, int s, int e);

void mergesort(int (*arr), int s, int e);


int main(int argc, char* argv[argc+1]){

    int len = argc - 1;
    int arr[len];

    for (int i = 1; i < argc; ++i) {
	arr[i - 1] = atoi(argv[i]);
    }

    mergesort(arr, 0, len - 1);

    for (int i = 0; i < len; ++i) {
	printf("%d\n", arr[i]);
    }

    return 0;
}

void mergesort(int *arr, int s, int e){
    
    if (e - s == 0) {
	return;
    } else if (e - s == 1) {
	if (arr[e - 1] > arr[e]) {
	    int temp = arr[e];
	    arr[e] = arr[e - 1];
	    arr[e - 1] = temp;
	}
	return;
    }

    int m = s + (e - s)/2;
    mergesort(arr, s, m);
    mergesort(arr, m + 1, e);
    merge(arr, s, e);
    return;
}

void merge(int *arr, int s, int e){
    int p1 = s + (e - s)/2;
    int p2 = e;
    int temp_arr[e - s + 1];

    for (int i = e - s; i >= 0; --i) {
	if (p1 - s < 0){
	    temp_arr[i] = arr[p2];
	    --p2;
	} else if (p2 - (s + (e - s)/2 + 1) < 0){
	    temp_arr[i] = arr[p1];
	    --p1;
	} else if (arr[p1] >= arr[p2]){
	    temp_arr[i] = arr[p1];
	    --p1;
	} else {
	    temp_arr[i] = arr[p2];
	    --p2;
	}
    }
    
    for (size_t i = s; i <= e; ++i){
	arr[i] = temp_arr[i-s];
    }
        
    return;
}
