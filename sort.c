#include<stdio.h>
#include <time.h>
#include <stdlib.h>


void merge(int[], int, int ,int);


void mergeSort(int nums[], int low, int high){
	if(low<high){
		int mid = (low+high)/2;
		mergeSort(nums, low, mid);
		mergeSort(nums, mid+1, high);
		merge(nums, low, mid, high);
	}
}


void merge(int nums[], int low, int mid, int high){
	//1. create two arrays
	int left_len = (mid-low)+1;
	int right_len = high-mid;
	int left[left_len];
	int right[right_len];
	
	//2. copy elements from original array into new arrays
	for(int index=0; index<left_len; index++){
		left[index] = nums[low+index];
	}
	
	int right_start = mid+1;
	for(int index=0; index<right_len; index++){
		right[index] = nums[right_start+index];
	}
	
	//3. start the merge process
	int left_index= 0;
	int right_index= 0;
	int num_index= low;
	
	while(left_index<left_len && right_index<right_len){
		if( left[left_index] < right[right_index] ){
			nums[num_index] = left[left_index];
			left_index++;
		}
		else{
			nums[num_index] = right[right_index];
			right_index++;
		}
		num_index++;
	}
	
	while(left_index < left_len){
		nums[num_index] = left[left_index];
		num_index++;
		left_index++;
	}
	
	while(right_index<right_len){
		nums[num_index] = right[right_index];
		num_index++;
		right_index++;
	}
	
}


int* makeArray(int length){
	int* pointer = malloc(sizeof(int)*length);
	//int* pointer = (int*)malloc(sizeof(int)*length);
	for(int i=0;i<length;i++){
    	pointer[i]=(rand()%length);
    }
    return pointer;
}


int main(int argc, char* argv[]){
	int size = atoi(argv[1]);
	
	int* nums = makeArray(size);
	
    clock_t begin = clock();

	mergeSort(nums, 0, size-1);
	clock_t end = clock();
	double timeTaken = (double)(end - begin) / CLOCKS_PER_SEC;
   
    printf("c mergeSort() took %f seconds to execute for %d elements\n", timeTaken, size);
	
    return 0;
}
