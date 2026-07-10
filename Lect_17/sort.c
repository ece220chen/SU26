#include <stdio.h>
#define SIZE 5

void swap(int *x, int *y);
void bubble_sort(int array[]);
void insertion_sort(int array[]);
int partition(int array[], int start, int end);
void quicksort(int array[], int start, int end);

int main(){
	int i;
	int array[] = {7,4,6,1,3};
	
	bubble_sort(array);
	//insertion_sort(array);
	//quicksort(array, 0, SIZE-1);

	for(i=0;i<SIZE;i++){
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
} 

/* Bubble Sort */
void bubble_sort(int array[]){
	int n = SIZE-1;
	int i, temp, flag;

	//sort number in ascending order
	do{
		flag = 0;
		for(i=0;i<n;i++){
			//swap the two numbers if order is incorrect
			if(array[i]>array[i+1]){
				swap(array+i, array+i+1);
				//set the swap flag
				flag++;
			}
		}
		//decrement after each pass
		n--;
	}while(flag);
}

/* Insertion Sort */
void insertion_sort(int array[]){
	int i, j, temp, empty_idx;
        for(i=1;i<SIZE;i++){
		temp = array[i];
		empty_idx = i;
		for(j=i-1;j>=0;j--){
			if(temp < array[j]){
				//shift element to the right
				array[j+1] = array[j]; 
				//update empty position
				empty_idx = j;
			}
			else
				break;
		}
		//insert at the proper location
		array[empty_idx] = temp;
	}
}

/* Quicksort */
void quicksort(int array[], int start, int end){
	if(start >= end)
		return;
	
	int pivot_idx = partition(array,start,end);
	quicksort(array, start, pivot_idx-1);
	quicksort(array, pivot_idx+1, end);
}

int partition(int array[], int low, int high){
	int pivot = array[low]; //set first element as pivot

	int store_idx = low + 1; //set second element index as the starting store index

	printf("pivot = %d, start_idx = %d, end_idx = %d \n", pivot, low, high);

	int i;
	for(i=low+1;i<=high;i++){
		if(array[i] < pivot){
			swap(&array[i], &array[store_idx]);
                        store_idx++;
		}
	}

	swap(&array[low], &array[store_idx-1]);

	return store_idx-1;
}
