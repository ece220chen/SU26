#include <stdio.h>
#define SIZE 7
#define ITEM 10

int binary(int array[], int item);

int main(){
	int array[] = {1,2,4,7,9,12,13};
	
	int index = binary(array, ITEM);
	if(index!= -1)
		printf("Found item (%d) at index:%d \n", ITEM, index);
	else
		printf("Item (%d) not found in array \n", ITEM);
	
	return 0;
}

/* return the index of the matching item in the sorted array */
int binary(int array[], int item){
	int L=0, H=SIZE-1, M;
	while(L<=H){
		M = (L+H)/2;
		if(item == array[M])
			return M;
		else if(item > array[M])
			L = M+1;
		else //item<array[M]
			H = M-1;
	}
	return -1;
}
