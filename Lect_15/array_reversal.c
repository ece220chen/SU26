#include <stdio.h>

void array_reverse(int array[], int n);
void swap(int *x, int *y);
void print_array(int array[], int n);

int main(){
	int n;
	printf("Enter the size of array: ");
	scanf("%d", &n);

	int array[n];
	int i;
	printf("Set each element for this array\n");
	for(i=0;i<n;i++){
		printf("Input number at index [%d]: ", i);
		scanf("%d", &array[i]);
	}
	
	printf("Array before reverse:\n");	
	print_array(array, n);

	array_reverse(array, n);

	printf("Array after reverse:\n");
	print_array(array, n);

	return 0;
}

void array_reverse(int array[], int n){
	int i;
	for(i=0;i<(n/2);i++){
		swap(array+i, array+(n-1-i)); /* ptr notation */
		/* swap(&(array[i]), &(array[n-1-i])); */
	}
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
void print_array(int array[], int n){
	int i;
        for(i=0;i<n;i++){
                printf("%d ", array[i]);
        }
        printf("\n");
}
