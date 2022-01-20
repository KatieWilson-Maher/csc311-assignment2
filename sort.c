#include<stdio.h>
#include <time.h>


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
	}//end of while
	
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

int main(){

	
	int size = 100000;	
	int nums[size];
	
	
	
	clock_t time;
    time = clock();
    mergeSort(nums, 0, size);
    time = clock() - time;
    double timeTaken = ((double)time)/CLOCKS_PER_SEC; // in seconds
    printf("mergeSort() took %f seconds to execute \n", timeTaken);
    
    
    char *fileName = "time.txt";
    
    FILE *fp = fopen(fileName, "a");
    if (fp == NULL)
    {
        printf("Error opening the file %s", fileName);
        return -1;
    }
    fprintf(fp, "c program took %f seconds to run\n", timeTaken);

    fclose(fp);
    
    return 0;
}
















