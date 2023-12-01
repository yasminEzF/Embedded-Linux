#include<stdio.h>
int binSrch(int* ptr, int size, int key) {
	int i = 0;
	int hi = size - 1, lo = 0, mid;
	mid = (hi + lo) / 2;
	while(hi >= lo) {
		mid = (hi + lo) / 2;
		if( ptr[mid] > key) 
			hi = mid -1;
		else if( ptr[mid] < key) 
			lo = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main(void) {
 	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	printf(" Searching for element [4]: %d\n",binSrch(arr,15,5));
	return 0;
}

 


