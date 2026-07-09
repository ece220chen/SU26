#include<stdio.h>
#define SIZE 5
void swap(int *x, int *y);
void bubble_sort(int array[]);

int main(){
	int array[SIZE] = {5,1,4,2,8};
	bubble_sort(array);
	int i;
	for(i=0;i<SIZE;i++){
		printf("array[%d]=%d\n", i, array[i]);
	}
	return 0;
}

void bubble_sort(int array[]){
	/* declare necessary variables */
	int flag, i;
	do{
		/* init 'swap' indicator */
		flag = 0;
		/* go through the entire array to compare and swap adjacent items */
		for(i=0;i<SIZE-1;i++){
			if(array[i]>array[i+1]){
				swap(array+i, array+i+1);
				flag++;
			}
		}
	}while(flag);
	/* go through the entire array again if there's a swap */
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
